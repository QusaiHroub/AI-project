#ifndef MAPLEVEL99PLUS_HPP
#define MAPLEVEL99PLUS_HPP

#include "particle.hpp"

#include <vector>

class BSTNode {
public:
    ~BSTNode();
    Particle *particle;
    BSTNode *left;
    BSTNode *right;
    BSTNode *parent;
};

class MapLevel99Plus {

private:
    BSTNode *m_root;

    void clear(BSTNode *);
    Particle *getAt(BSTNode *, long double);

public:
    MapLevel99Plus();
    ~MapLevel99Plus();

    void inseart(BSTNode *, Particle *, BSTNode * = nullptr);
    void inseart(Particle *);
    void buildForVector(BSTNode *, std::vector<Particle>, int, int, BSTNode * = nullptr);
    void buildForVector(std::vector<Particle>, void (*) (std::vector<Particle>::iterator, std::vector<Particle>::iterator) = nullptr);
    void clear();

    Particle *getAt(long double);

    Particle &operator[](long double);
};

#endif // MAPLEVEL99PLUS_HPP
