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
	vector<Particle> particlesList;//list contain the particles of robot
	double arr[1000] = {};//Array Contain the temperature for every point  on robot path
	double avg = utilities::getTempForAllPositions(arr);// calculate the average of temperature
	double mean;

	HeatSensor heatSensor(arr, 1000);//class to keep the temperature

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
	utilities::getRandomParticles(particlesList, arr, currentPosition, avg, standardDeviation, numberOfRandomParticles);//function to  select random particles
	double sum;//to sum all positions
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
		cout << "Variance : " << utilities::Variance(mean, particlesList) << endl;
		Particle_filter(particlesList, nextStep, heatSensor.read(currentPosition), avg, standardDeviation, mean, arr);//to apply the particle filter algorithm
		currentPosition += nextStep;
	}

	return 0;
}
