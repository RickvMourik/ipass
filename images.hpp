#ifndef IMAGES_HPP
#define IMAGES_HPP

#include "hwlib.hpp"

class images{
    protected:
        hwlib::glcd_oled & display;

    public:
        images(hwlib::glcd_oled &display):
        display( display )
        {}

        virtual void draw() = 0;
};

#endif // IMAGES_HPP