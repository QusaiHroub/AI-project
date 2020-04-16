#include "heatsensor.hpp"

HeatSensor::HeatSensor() {

}

HeatSensor::HeatSensor(double *heatList, int size) {
    setHeatList(heatList, size);
}

void HeatSensor::setHeatList(double *heatList, int size) {
    m_heatList = heatList;
    m_heatListSize = size;
}

double *HeatSensor::getHeatList() {
    return m_heatList;
}

double HeatSensor::randomError() {
    return utilities::smallRnadomError(4, 5);
}

double HeatSensor::getSampleHeat(int weight, int position) {
    return weight * m_heatList[position] * randomError() / 100;
}

double HeatSensor::sampling(int position) {
    double result = getSampleHeat(WEIGHT_LIST[0], position);
    double temp;

    for (int i = 1; i < WEIGHT_LIST_SIZE; i++) {
        if (position + i < m_heatListSize) {
            temp = getSampleHeat(WEIGHT_LIST[i], position + 1);
        } else {
            temp = getSampleHeat(WEIGHT_LIST[i], position);
        }
        if (position - i > -1) {
            temp /= 2;
            temp += getSampleHeat(WEIGHT_LIST[i] / 2, position - 1);
        } else {
            temp /= 2;
            temp += getSampleHeat(WEIGHT_LIST[i] / 2, position);
        }
        result += temp;
    }

    return result;
}

double HeatSensor::read(int position) {
    return sampling(position);
}
