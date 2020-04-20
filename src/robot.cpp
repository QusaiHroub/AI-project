#include "robot.hpp"

#include "utilities.hpp"

Robot::Robot(double *heatList, int heatListSize) : m_heatSensor(heatList, heatListSize) {
}

Robot::~Robot() {
}

double Robot::getRededHeat() {
    return m_heatSensor.read(m_position);
}

void Robot::move() {
    m_lastStepSize = m_stepSize * utilities::smallRnadomError(3, 1.5);
    m_position += m_lastStepSize;
}

int Robot::getRobotPosition() {
    return m_position;
}

int Robot::getLastStepSize() {
    return m_lastStepSize;
}

int Robot::getStepSize() {
    return m_stepSize;
}
