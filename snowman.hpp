#ifndef SNOWMAN_HPP
#define SNOWMAN_HPP

#include "hwlib.hpp"
#include "images.hpp"

class snowmanClass : public images {
   
    public:
    snowmanClass(hwlib::glcd_oled & display):
    images( display )
     
    {}
    
    void draw() override; 
    };

#endif // SNOWMAN_HPP