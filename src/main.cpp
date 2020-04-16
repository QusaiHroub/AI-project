#include <iostream>
#include <vector>
#include <cmath>

#include "maplevel99plus.hpp"
#include "particle.hpp"
#include "particle_filter.hpp"
#include "utilities.hpp"
#include "heatsensor.hpp"

using namespace std;

int main() {
	vector<Particle> particlesList;//our particles
	double arr[1000] = {};
	double avg = utilities::getTempForAllPositions(arr);
	double mean;
	
	HeatSensor heatSensor(arr, 1000);
	
	int start , stepSize, nextStep;
	cout << "Enter the start point of rebot : ";
	cin >> start;
	cout << "Enter the step length  of rebot : ";
	cin >> stepSize;
	
	int  currentPosition = start;

	double standardDeviation = utilities::getStandardDeviation(arr, avg);
	double numberOfRandomParticles;
	cout << "Enter the number of particles : ";
	cin >> numberOfRandomParticles;
	//to select particles
	utilities::getRandomParticles(particlesList, arr, currentPosition, avg, standardDeviation, numberOfRandomParticles);
	double sum;
	while (currentPosition < 1000) {
		sum = 0;
		for (unsigned long i = 0; i < particlesList.size(); i++)
		{
			cout << "Particle number " << i << " in position : " << particlesList[i].getPosition() << endl;
			sum += particlesList[i].getPosition();
		}
		
		mean = sum / particlesList.size();
		nextStep = stepSize * utilities::smallRnadomError(3, 1.5);
		cout << "Robot position : " << currentPosition << endl;
		cout << "Mean : " << mean << endl;
		cout << "Variance : " << abs(currentPosition - (sum / particlesList.size())) << endl;
		Particle_filter(particlesList, nextStep, heatSensor.read(currentPosition), avg, standardDeviation, mean, arr);
		currentPosition += nextStep;
	}

	return 0;
}
