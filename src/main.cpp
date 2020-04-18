#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "particle.hpp"
#include "particle_filter.hpp"
#include "utilities.hpp"
#include "heatsensor.hpp"

using namespace std;

int readInt(int &);

int main() {

	const int DEFAULT_STEP_LENGTH = 11;
	const int DEFAULT_START_POSITION = 13;
	const int DEFAULT_PARTICLES_NUMBER = 45;

	//list contain the particles of robot
	vector<Particle> particlesList;

	//Array Contain the temperature for every point  on robot path
	double arr[1000] = {};

	// calculate the average of temperature
	double avg = utilities::getTempForAllPositions(arr);
	double mean;

	//heat sensor (: to get the temperature
	HeatSensor heatSensor(arr, 1000);
	
	int start = DEFAULT_START_POSITION, stepSize = DEFAULT_STEP_LENGTH, nextStep;
	
	cout << "Enter the start point of rebot (default = " << DEFAULT_START_POSITION << ") : ";
	while (readInt(start)) {
		cout << "Invalid integer. Try again (default = " << DEFAULT_START_POSITION << ") : ";
	}
	
	cout << "Enter the step length  of rebot (default = " << DEFAULT_STEP_LENGTH << ") : ";
	while (readInt(stepSize)) {
		cout << "Invalid integer. Try again (default = " << DEFAULT_STEP_LENGTH << ") : ";
	}

	int  currentPosition = start;

	double standardDeviation = utilities::getStandardDeviation(arr, avg);
	int numberOfRandomParticles = DEFAULT_PARTICLES_NUMBER;
	
	cout << "Enter the number of particles (default = " << DEFAULT_PARTICLES_NUMBER << ") : ";
	while (readInt(numberOfRandomParticles)) {
		cout << "Invalid integer. Try again (default = " << DEFAULT_PARTICLES_NUMBER << ") : ";
	}

	//function to  select random particles
	utilities::getRandomParticles(particlesList, arr, currentPosition, avg, standardDeviation, numberOfRandomParticles);
	double sum;
	
	while (cout << "press enter to continue ... ", currentPosition < 1000 && cin.get() == '\n') {
		sum = 0;

		//print position for all particles.
		for (unsigned long i = 0; i < particlesList.size(); i++)
		{
			cout << "Particle number " << i << " in position : " << particlesList[i].getPosition() << endl;
			sum += particlesList[i].getPosition();
		}

		//calc mean value.
		mean = sum / particlesList.size();

		// add small error on next step.
		nextStep = stepSize * utilities::smallRnadomError(3, 1.5);
		
		cout << "Robot position : " << currentPosition << endl;
		cout << "Mean : " << mean << endl;
		cout << "Variance : " <<utilities::Variance(mean, particlesList) << endl;
		
		//to apply the particle filter algorithm
		Particle_filter(particlesList, nextStep, heatSensor.read(currentPosition), avg, standardDeviation, mean, arr);
		currentPosition += nextStep;
	}

	return 0;
}

int readInt(int &inputRef) {
	string input;

	getline(cin, input);
	if (!input.empty() && !(stringstream(input) >> inputRef)) {
		return -1;
	} 
	return 0;
}
