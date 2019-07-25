#ifndef HOUSE_HPP
#define HOUSE_HPP

#include "hwlib.hpp"
#include "images.hpp"

class houseClass: public images {
   
    public:
    houseClass(hwlib::glcd_oled & display):
    images( display )
     
    {}
    
    void draw() override; 
    };

#endif // HOUSE_HPP