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

    unsigned long long rand();
    unsigned long long randMod(unsigned long long mod);
    Particle& getRandomParticle(MapLevel99Plus& map);
    double weight(double x, double u, double q);
    Particle normalize(Particle p, double w);
    void getRandomParticles(std::vector<Particle>& particlesList, double arr[], int currentPosition, double avg, double standardDeviation, int numberOfParticles);
    double getTempForAllPositions(double* arr);
    double getStandardDeviation(double arr[], double avg);
    double smallRnadomError(int, double = 1.0);
   	double Variance(double mean, std::vector<Particle> particlesList);
}

#endif // UTILITIES_HPP
