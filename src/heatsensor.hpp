#ifndef HEATSENSOR_HPP
#define HEATSENSOR_HPP

#include "utilities.hpp"

class HeatSensor {
private:
    const int WEIGHT_LIST_SIZE = 4;
    const int WEIGHT_LIST[4] = {60, 22, 12, 6};

    double * m_heatList = nullptr;
    int m_heatListSize;

    double randomError();
    double sampling(int);
    double getSampleHeat(int, int);

public:
    HeatSensor();
    HeatSensor(double *, int);

    void setHeatList(double *, int);
    double *getHeatList();

    double read(int);
};

#endif // HEATSENSOR_HPP
