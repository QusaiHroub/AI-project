#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <vector>
#include <algorithm>
#include <random>

#include "particle.hpp"
#include "maplevel99plus.hpp"

namespace utilities {

    const unsigned long long PRIME = 261798184036870849ll;
    const double PI = 3.14159265;

    //return random value between 0 and MAX_ULL (max of unsignes log long)
    unsigned long long rand();

    //return random value between 0 and mod.
    unsigned long long randMod(unsigned long long mod);

    //return particle that selected randomly from map of type MapLevel99Plus.
    Particle& getRandomParticle(MapLevel99Plus& map);

    //clac weight of particle.
    double weight(double x, double u, double q);

    //normalize weight of particle.
    Particle normalize(Particle p, double w);

    //init particles list with random particles.
    void getRandomParticles(std::vector<Particle>& particlesList, double arr[], int currentPosition, double avg, double standardDeviation, int numberOfParticles);

    //init temp map;
    double getTempForAllPositions(double* arr);

    //return standerd deviation.
    double getStandardDeviation(double arr[], double avg);

    //return small error controlled by two factors.
    double smallRnadomError(int, double = 1.0);

    //calc the variance of particles positions.
    double Variance(double mean, std::vector<Particle> particlesList);
}

#endif // UTILITIES_HPP
