//
// Temperature.h
// Vince Allen
// Chapter 6, project10
//

#include <stdio.h>

class Temperature {
    double tempKelvin;
public:
    void setTempKelvin(double temp) { tempKelvin = temp; };
    void setTempFahrenheit(double temp);
    void setTempCelsius(double temp);
    double getTempKelvin() { return tempKelvin; };
    double getTempFahrenheit();
    double getTempCelsius();
};
