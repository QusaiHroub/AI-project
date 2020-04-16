#ifndef PARTICLE_FILTER_HPP_INCLUDED
#define PARTICLE_FILTER_HPP_INCLUDED

#include <vector>
#include <cmath>

#include "particle.hpp"
#include "maplevel99plus.hpp"
#include "utilities.hpp"

 void Particle_filter(std::vector<Particle>& particlesList, int U, double Z, double avg, double standardDeviation, int currentPosition, double arr[]) {
	std::vector<Particle> newS;
	MapLevel99Plus map;
	map.buildForVector(particlesList);
	double weightSum = 0;
	for (unsigned long i = 0; i < particlesList.size(); i++) {
		Particle randomParticle = Particle(&utilities::getRandomParticle(map));
		if (randomParticle.getPosition() + U >= 1000)
			randomParticle.setPosition((rand() % (1000- currentPosition))+ currentPosition);
		else
			randomParticle.setPosition(randomParticle.getPosition() + U);
		double weightParicle = utilities::weight(Z - arr[randomParticle.getPosition()], avg, standardDeviation);
		randomParticle.setWeight(weightParicle);
		weightSum += weightParicle;
		newS.push_back(randomParticle);
	};
	for (unsigned long i = 0; i < particlesList.size(); i++) {
		particlesList[i] = newS[i];
	}
	for (unsigned long i = 0; i < particlesList.size(); i++)
		particlesList[i] = utilities::normalize(particlesList[i], weightSum);
}

#endif // PARTICLE_FILTER_HPP_INCLUDED
