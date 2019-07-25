#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "hwlib.hpp"


class rectangle{
    private:
        hwlib::window & w;
        int start_x;
        int start_y;
        int end_x;
        int end_y;

    public:
      rectangle( hwlib::window & w,
        int i_start_x,
        int i_start_y,
        int i_end_x,
        int i_end_y ):
        
        w( w ),
        start_x( i_start_x ),
        start_y( i_start_y),
        end_x( i_end_x ),
        end_y( i_end_y)
   {}
   
   void draw();

};

#endif // RECTANGLE_HPP