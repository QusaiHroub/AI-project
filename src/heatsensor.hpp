#ifndef HEATSENSOR_HPP
#define HEATSENSOR_HPP

#include "utilities.hpp"

class HeatSensor {
private:
    const int WEIGHT_LIST_SIZE = 5;
    const int WEIGHT_LIST[5] = {45, 27, 17, 7, 4};

    double * m_heatList = nullptr;
    int m_heatListSize;

    //generate small random error for heat senseor using utilities::smallRandomError.
    double randomError();

    //get weighted average for 7 close temperature to position
    double sampling(int);

    //get sampling value with small error.
    double getSampleHeat(int, int);

public:
    HeatSensor();
    HeatSensor(double *, int);

    void setHeatList(double *, int);
    double *getHeatList();

    double read(int);
};

#endif // HEATSENSOR_HPP
