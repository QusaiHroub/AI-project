#include "particle.hpp"

Particle::Particle() {

}

Particle::Particle(long double weight, int position) {
    setWeight(weight);
    setPosition(position);
}

Particle::Particle(Particle *particle) {
    setWeight(particle->getWeight());
    setPosition(particle->getPosition());
}

long double Particle::getWeight() const {
    return m_weight;
}

void Particle::setWeight(long double weight) {
    if (weight < MIN_WEIGHT) {
        m_weight = MIN_WEIGHT;
        return;
    }

    m_weight = weight;
}

int Particle::getPosition() const {
    return m_position;
}

void Particle::setPosition(int position) {
    m_position = position;
}

long double Particle::getL() const {
    return m_l;
}

void Particle::setL(long double l) {
    m_l = l;
}

long double Particle::getH() const {
    return m_h;
}

void Particle::setH(long double h) {
    m_h = h;
}

Particle &Particle::operator=(const Particle &right) {
    setWeight(right.getWeight());
    setPosition(right.getPosition());
    setH(right.getH());
    setL(right.getL());

    return *this;
}
