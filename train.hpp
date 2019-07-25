#ifndef TRAIN_HPP
#define TRAIN_HPP

#include "hwlib.hpp"
#include "images.hpp"

class trainClass : public images {
   
    public:
    trainClass(hwlib::glcd_oled & display):
    images( display )
     
    {}
    
    void draw() override; 
    };

#endif // TRAIN_HPP