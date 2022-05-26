#include "robot.hpp"

#include "utilities.hpp"

Robot::Robot(double *heatList, int heatListSize) : m_heatSensor(heatList, heatListSize) {
}

Robot::~Robot() {
}

double Robot::getRededHeat() {
    return m_heatSensor.read(m_position);
}

int Robot::getMoveError() {
    return 10 * utilities::smallRnadomError(3, 2.5) - 10;
}

void Robot::move() {
    m_lastStepSize = m_stepSize + getMoveError();
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
