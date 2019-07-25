#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "hwlib.hpp"
#include "adxl345.hpp"
#include "images.hpp"

class application{
    private:
    adxl345 & sensor;
    hwlib::glcd_oled & oled_target;
    int posThreshX;
    int negThreshX;
    int posThreshY;
    int negThreshY;
    int highResetX;
    int lowResetX;
    int highResetY;
    int lowResetY;

    public:
    application(adxl345 & sensor, hwlib::glcd_oled & display, int posThreshX = 100, int negThreshX =-100, int posThreshY = 125, int negThreshY = -125,
    int highResetX= 25, int lowResetX= -25, int highResetY= 25, int lowResetY =-25):
    sensor( sensor ),
    oled_target( display ),
    posThreshX( posThreshX ),
    negThreshX( negThreshX ),
    posThreshY( posThreshY ),
    negThreshY( negThreshY ),
    highResetX( highResetX ),
    lowResetX( lowResetX ),
    highResetY( highResetY ),
    lowResetY( lowResetY )

    {}
    void run();

};

#endif // APPLICATION_HPP