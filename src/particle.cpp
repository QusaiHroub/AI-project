#include "particle.hpp"

Particle::Particle() {

}

Particle::Particle(long double weight, int position) {
    setWeight(weight);
    setPosition(position);
}

long double Particle::getWeight() {
    return m_weight;
}

void Particle::setWeight(long double weight) {
    if (weight < MIN_Weight) {
        m_weight = MIN_Weight;
        return;
    }

    m_weight = weight;
}

int Particle::getPosition() {
    return m_position;
}

void Particle::setPosition(int position) {
    m_position = position;
}

long double Particle::getL() {
    return m_l;
}

void Particle::setL(long double l) {
    m_l = l;
}

long double Particle::getH() {
    return m_h;
}

void Particle::setH(long double h) {
    m_h = h;
}
