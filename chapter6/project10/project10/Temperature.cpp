//
// Temperature.cpp
// Vince Allen
// Chapter 6, project10
//

#include "Temperature.h"

const double CONST_TO_KELVIN = 0.55555555;
const double CONST_FROM_KELVIN = 1.8;

void Temperature::setTempFahrenheit(double temp) {
    tempKelvin = (temp + 459.67) * (CONST_TO_KELVIN);
}

void Temperature::setTempCelsius(double temp) {
    tempKelvin = temp + 273.15;
}

double Temperature::getTempFahrenheit() {
    return getTempKelvin() * CONST_FROM_KELVIN - 459.67;
};

double Temperature::getTempCelsius() {
    return getTempKelvin() - 273.15;
};
