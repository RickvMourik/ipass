#include <hwlib.hpp>
#include "rectangle.hpp"

/// \brief
/// rectangle
/// \details
/// This is the function draws a hollow rectangle on the specified screen.
void rectangle::draw(){
   hwlib::line top({start_x, start_y}, {end_x, start_y});
   hwlib::line bottom( {start_x, end_y}, {end_x, end_y});
   hwlib::line left( {start_x, start_y}, {start_x, end_y});
   hwlib::line right( {end_x, start_y}, {end_x, end_y});


   top.draw(w);
   bottom.draw(w);
   left.draw(w);
   right.draw(w);
}