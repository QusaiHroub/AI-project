#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <algorithm>
#include <random>

#include "particle.hpp"
#include "maplevel99plus.hpp"

namespace utilities {

const unsigned long long PRIME = 261798184036870849ll;

unsigned long long rand() {
    std::random_device rd;
    std::mt19937_64 eng(rd());
    std::uniform_int_distribution<unsigned long long> distr;

    return distr(eng);
}

unsigned long long randMod(unsigned long long mod) {
    return rand() % mod;
}

Particle &getRandomParticle(MapLevel99Plus &map) {
    long double randomNumber = randMod(PRIME);

    return map[randomNumber];
}

}

#endif // UTILITIES_HPP
