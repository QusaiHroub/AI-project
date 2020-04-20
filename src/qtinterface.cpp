#include "qtinterface.hpp"

#include "particle_filter.hpp"

QtInterface::QtInterface(double *heatList, int heatListSize, Robot *robot, std::vector<Particle> &particlesList, double avg, double standardDeviation) : m_particlesList(particlesList) {
    m_heatList = heatList;
    m_heatListSize = heatListSize;
    m_robot = robot;
    m_avg = avg;
    m_standardDeviation = standardDeviation;
}

QList<int> QtInterface::getParticlesPostions() {
    QList<int> list;
    for (unsigned long i = 0; i < m_particlesList.size(); i++) {
        list.push_back(m_particlesList[i].getPosition());
    }

    return list;
}

int QtInterface::getRobotPosition() {
    return m_robot->getRobotPosition();
}

bool QtInterface::isCanMove() {
    return m_isCanMove;
}

void QtInterface::moveOneStep() {
    if (!m_isCanMove) {
        return;
    }

    m_robot->move();
    Particle_filter(m_particlesList, m_robot->getLastStepSize(), m_robot->getRededHeat(), m_avg, m_standardDeviation, getMeanValue(), m_heatList);

    if (m_robot->getRobotPosition() + m_robot->getStepSize() * 1.2 >= 1000) {
        m_isCanMove = false;
    }
}

double QtInterface::getMeanValue() {
    double sum = 0;

    //print position for all particles.
    for (unsigned long i = 0; i < m_particlesList.size(); i++) {
        sum += m_particlesList[i].getPosition();
    }

    //calc mean value.
    return sum / m_particlesList.size();
}

QList<double> QtInterface::getHeatList() {
    QList<double> list;
    for (int i = 0; i < m_heatListSize; i++) {
        list.push_back(m_heatList[i]);
    }

    return list;
}

double QtInterface::getVariance(double mean) {
    return utilities::Variance(mean, m_particlesList);
}
