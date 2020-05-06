#ifndef PARTICLE_FILTER_HPP_INCLUDED
#define PARTICLE_FILTER_HPP_INCLUDED

#include <vector>
#include <cmath>

#include "particle.hpp"
#include "maplevel99plus.hpp"
#include "utilities.hpp"


// particle filter 
 void Particle_filter(std::vector<Particle>& particlesList, int U, double Z, double avg, double standardDeviation, int (*error)(), double arr[]) {
	
	//determine start point of expected area, that the robot position expected be in. 
    int expectedPosition = 0;

	//List for new particles after random selection.
	std::vector<Particle> newS;

	//comulative map for random selection.
	MapLevel99Plus map;
	map.buildForVector(particlesList);

	double weightSum = 0;
	for (unsigned long i = 0; i < particlesList.size(); i++) {
        int err = error();
		//select random particle.
		Particle randomParticle = Particle(&utilities::getRandomParticle(map));
        if (randomParticle.getPosition() + U + err >= 1000) {
			randomParticle.setPosition((rand() % (1000 - expectedPosition)) + expectedPosition);
		} else {
            randomParticle.setPosition(randomParticle.getPosition() + U + err);
		}

		//update particle weight.
		double weightParticle = utilities::weight(Z - arr[randomParticle.getPosition()], avg, standardDeviation);
		randomParticle.setWeight(weightParticle);
		weightSum += weightParticle;
		newS.push_back(randomParticle);
	}

	//update particles list.
	for (unsigned long i = 0; i < particlesList.size(); i++) {
		particlesList[i] = newS[i];
	}

	//normalize weight of paricles.
	for (unsigned long i = 0; i < particlesList.size(); i++)
		particlesList[i] = utilities::normalize(particlesList[i], weightSum);
}

#endif // PARTICLE_FILTER_HPP_INCLUDED
