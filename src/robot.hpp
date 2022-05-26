#ifndef ROBOT_HPP
#define ROBOT_HPP

#include "heatsensor.hpp"

class Robot {
public:
    Robot(double *, int);
    ~Robot();
    void move();
    int getLastStepSize();
    int getRobotPosition();
    double getRededHeat();
    int getStepSize();
    static int getMoveError();

private:
    const int DEFAULT_STEP_LENGTH = 11;
    const int DEFAULT_START_POSITION = 13;

    HeatSensor m_heatSensor;
    int m_position = DEFAULT_START_POSITION;
    int m_stepSize = DEFAULT_STEP_LENGTH;
    int m_lastStepSize;
};

#endif // ROBOT_HPP
