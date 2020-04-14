#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <algorithm>

#include "particle.hpp"

bool compare(Particle &lParticle, Particle &hParticle) {
    return lParticle.getWeight() < hParticle.getWeight();
}

void uSort(std::vector<Particle>::iterator begin, std::vector<Particle>::iterator end) {
    std::sort(begin, end, compare);
}

#endif // UTILITIES_HPP
