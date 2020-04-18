#include <algorithm>
#include <random>

#include "utilities.hpp"

namespace utilities {

	unsigned long long rand() {
		std::random_device rd;
		std::mt19937_64 eng(rd());
		std::uniform_int_distribution<unsigned long long> distr;

		return distr(eng);
	}

	unsigned long long randMod(unsigned long long mod) {
		return rand() % mod;
	}

	Particle& getRandomParticle(MapLevel99Plus& map) {
		long double randomNumber = randMod(PRIME);

		return map[randomNumber];
	}

	/**
	To calculate the weights using gaussian formula
	*/
	double weight(double x, double u, double q) {
		return ((1 / (q * sqrt(2 * PI))) * exp(-1 * pow((x - u), 2) / 2 * pow(q, 2)));
	}

	/*
	To normalize the weights
	**/
	Particle normalize(Particle p, double w) {
		p.setWeight(p.getWeight() / w);
		return p;
	}

	void getRandomParticles(std::vector<Particle>& particlesList, double arr[], int currentPosition, double avg, double standardDeviation, int numberOfParticles) {
		int pos = 0;
		double weightSum = 0;
		while (pos < numberOfParticles) {
			Particle particle = new Particle();
			int newParticle = randMod(997);
			particle.setPosition(newParticle);
			double weightParticle = weight(arr[currentPosition] - arr[newParticle], avg, standardDeviation);
			particle.setWeight(weightParticle);
			weightSum += weightParticle;
			particlesList.push_back(particle);
			pos++;
		}
		for (unsigned long i = 0; i < particlesList.size(); i++)
			particlesList[i] = normalize(particlesList[i], weightSum);

	}

	double getTempForAllPositions(double* arr) {
		double sum = 0;
		int j = 0;
		for (double i = 0; i < 1; i += 0.001) {
			arr[j] = cos(2 * PI * i) + 0.5 * cos((3 * i + 0.23) * 2 * PI) + 0.5 * cos((5 * i - 0.4) * 2 * PI) + 0.5 * cos((7 * i - 2.09) * 2 * PI) + 0.5 * cos((9 * i - 3) * 2 * PI);
			sum += arr[j];
			j++;
		}
		return  sum / 1000;
	}

	double getStandardDeviation(double arr[], double avg) {
		double sum = 0;
		for (int i = 0; i < 1000; i++) {
			sum += pow(arr[i] - avg, 2);
		}

		return sum / 1000;
	}

	double smallRnadomError(int n, double factor) {
		return 1.0 + factor * (utilities::rand() & 1 ? -1 : 1) * ((utilities::rand() % 101) / pow(10, n));
	}
	
	double Variance(double mean, std::vector<Particle> particlesList) {
		double sum = 0;
			for (int i = 0; i < particlesList.size(); i++) {
				sum += pow(particlesList[i].getPosition() - mean,2);
			}
		return sqrt(sum / (particlesList.size() - 1));
	}
}
