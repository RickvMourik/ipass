#ifndef IMAGES_HPP
#define IMAGES_HPP

#include "hwlib.hpp"

class images{
    private:
        hwlib::glcd_oled & display;

    public:
        images(hwlib::glcd_oled &dislpay):
        display( dislpay )
        {}

        void snowman();

        void house();

        void train();

};

#endif // IMAGES_HPP