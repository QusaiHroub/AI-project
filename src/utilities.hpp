#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <algorithm>
#include <random>

#include "particle.hpp"
#include "maplevel99plus.hpp"

const unsigned long long PRIME = 261798184036870849ll;

Particle &getRandomParticle(MapLevel99Plus &map) {
    std::random_device rd;
    std::mt19937_64 eng(rd());
    std::uniform_int_distribution<unsigned long long> distr;

    long double randomNumber =  distr(eng) % PRIME;

    return map[randomNumber];
}

#endif // UTILITIES_HPP
