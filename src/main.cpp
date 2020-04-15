#include <iostream>
#include <vector>
#include <cmath>

#include "maplevel99plus.hpp"
#include "particle.hpp"
#include "particle_filter.hpp"
#include "utilities.hpp"
using namespace std;

int main() {
	vector<Particle> particlesList;//our particle
	double arr[1000];
	const double pi = 3.14159265;

	int start , step;
	cout << "Enter the start point of rebot : ";
	cin >> start;
	cout << "Enter the step length  of rebot : ";
	cin >> step;

	int  currentPosition = start;
	double avg = utilities::getTempForAllPositions(arr);

	double standardDeviation = utilities::getStandardDeviation(arr, avg);
	double numberOfRandomParticles;
	cout << "Enter the number of particles : ";
	cin >> numberOfRandomParticles;
	//to select particles
	utilities::getRandomParticles(particlesList, arr, currentPosition, avg, standardDeviation, numberOfRandomParticles);
	double sum;
	while (currentPosition < 1000) {
		sum = 0;
		for (int i = 0; i < particlesList.size(); i++)
		{
			cout << "Particle number " << i << " in position : " << particlesList[i].getPosition() << endl;
			sum += particlesList[i].getPosition();
		}

		cout << "Robot position : " << currentPosition << endl;
		cout << "Mean : " << sum / particlesList.size() << endl;
		cout << "Variance : " << abs(currentPosition - (sum / particlesList.size())) << endl;
		Particle_filter(particlesList, step, arr[currentPosition], avg, standardDeviation, currentPosition, arr);//need random error arr[currentPosition]
		currentPosition += step;//need random error

	}

	return 0;
}

