#ifndef QTINTERFACE_HPP
#define QTINTERFACE_HPP

#include <QObject>
#include <QList>

#include "robot.hpp"
#include "particle.hpp"

class QtInterface : public QObject {
    Q_OBJECT
public:
    QtInterface(double *, int, Robot *, std::vector<Particle> &, double, double);

    Q_INVOKABLE QList<int> getParticlesPostions();
    Q_INVOKABLE int getRobotPosition();
    Q_INVOKABLE void moveOneStep();
    Q_INVOKABLE bool isCanMove();
    Q_INVOKABLE double getMeanValue();
    Q_INVOKABLE QList<double> getHeatList();
    Q_INVOKABLE double getVariance(double);

private:
    double *m_heatList;
    int m_heatListSize;
    Robot *m_robot;
    std::vector<Particle> &m_particlesList;
    bool m_isCanMove = true;
    double m_avg;
    double m_standardDeviation;
};

#endif // QTINTERFACE_HPP
