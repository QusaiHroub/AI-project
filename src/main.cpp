#include <iostream>
#include <vector>
#include <cmath>

#include "maplevel99plus.hpp"
#include "particle.hpp"
#include "particle_filter.hpp"
#include "utilities.hpp"
using namespace std;

int main() {
	vector<Particle> v;//our particle
	double arr[1000];
	const double pi = 3.14159265;


	int start = 6, currentPosition = start, step = 12;

	double sum = 0;
	int j = 0;
	for (double i = 0; i < 1; i += 0.001) {
		arr[j] = cos(2 * pi * i) + 0.5 * cos((3 * i + 0.23) * 2 * pi) + 0.5 * cos((5 * i - 0.4) * 2 * pi) + 0.5 * cos((7 * i + 2.09) * 2 * pi) + 0.5 * cos((9 * i - 3) * 2 * pi);
		sum += arr[j];
		j++;
	}
	double avg = sum / 1000;

	sum = 0;
	for (int i = 0; i < 1000; i++) {
		sum += pow(arr[i] - avg, 2);

	}

	double standardDeviation = sum / 1000;

	//to select particles
	int pos = start;
	double weightSum = 0;
	double w = 0;
	while (pos < 1000) {
		Particle particle = new Particle();
		particle.setPosition(pos);
		double weightParticle = weight(arr[currentPosition] - arr[pos], avg, standardDeviation);
		particle.setWeight(weightParticle);
		weightSum += weightParticle;
		v.push_back(particle);
		pos = pos + step;
	}
	for (int i = 0; i < v.size(); i++)
		v[i] = normalize(v[i], weightSum);

	while (currentPosition < 1000) {
		sum = 0;
		for (int i = 0; i < v.size(); i++)
		{
			cout << "Particle number " << i << " in position : " << v[i].getPosition() << endl;
			sum += v[i].getPosition();
		}

		cout << "Robot position : " << currentPosition << endl;
		cout << "Mean : " << sum / v.size() << endl;
		currentPosition += step;//need random error
		v = Particle_filter(v, 10, arr[currentPosition], avg, standardDeviation, currentPosition, arr);//need random error arr[currentPosition]
	}

	return 0;
}

