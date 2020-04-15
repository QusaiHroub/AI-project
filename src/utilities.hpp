#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <algorithm>
#include <random>

#include "particle.hpp"
#include "maplevel99plus.hpp"

namespace utilities {

const unsigned long long PRIME = 261798184036870849ll;

unsigned long long uRand() {
    std::random_device rd;
    std::mt19937_64 eng(rd());
    std::uniform_int_distribution<unsigned long long> distr;

    return distr(eng);
}

unsigned long long uRandMod(unsigned long long mod) {
    return uRand() % mod;
}

Particle &getRandomParticle(MapLevel99Plus &map) {
    long double randomNumber = uRandMod(PRIME);

    return map[randomNumber];
}

}

#endif // UTILITIES_HPP
