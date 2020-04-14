#include "maplevel99plus.hpp"

MapLevel99Plus::MapLevel99Plus() {

}

MapLevel99Plus::~MapLevel99Plus() {
    clear();
}

void MapLevel99Plus::inseart(BSTNode **root, Particle *particle, BSTNode *parent) {
    if (*root == nullptr) {
        (*root) = new BSTNode;
        (*root)->particle = particle;
        (*root)->left = nullptr;
        (*root)->right = nullptr;
        (*root)->parent = parent;
        return;
    }

    if (particle->getH() < (*root)->particle->getH()) {
        inseart(&(*root)->left, particle, *root);
    } else {
        inseart(&(*root)->right, particle, *root);
    }
}

void MapLevel99Plus::inseart(Particle *particle) {
    inseart(&m_root, particle);
}

void MapLevel99Plus::buildForVector(BSTNode **root, std::vector<Particle> &list, int low, int high, BSTNode *parent) {
    if (low > high) {
        return;
    }

    int mid = (low + high) / 2;

    inseart(root, &list[mid], parent);

    buildForVector(&(*root)->left, list, low, mid - 1, *root);
    buildForVector(&(*root)->right, list, mid + 1, high, *root);
}

void MapLevel99Plus::buildForVector(std::vector<Particle> &list, void (*sort) (std::vector<Particle>::iterator, std::vector<Particle>::iterator)) {
    if (sort != nullptr) {
        sort(list.begin(), list.end());
    }

    initLAndHForParticlesInVector(list);

    buildForVector(&m_root, list, 0, list.size() - 1);
}

void MapLevel99Plus::clear(BSTNode *root) {
    if (root != nullptr) {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}

void MapLevel99Plus::clear() {
    clear(m_root);
}

Particle *MapLevel99Plus::getAt(BSTNode *root, long double p) {
    if (p > root->particle->getH()) {
        return getAt(root->right, p);
    } else if (p < root->particle->getL()) {
        return getAt(root->left, p);
    }
    return root->particle;
}

Particle *MapLevel99Plus::getAt(long double p) {
    return getAt(m_root, p);
}

Particle &MapLevel99Plus::operator[](long double p) {
    return (*(getAt(p)));
}

void MapLevel99Plus::initLAndHForParticlesInVector(std::vector<Particle> &list) {
    long double prevPoint = 0.0l;
    for (unsigned long i = 0; i < list.size(); i++) {
        list[i].setL(prevPoint);
        prevPoint += list[i].getWeight() * PRIME;
        list[i].setH(prevPoint);
    }
}

BSTNode::~BSTNode() {

}
