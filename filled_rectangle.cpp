#include <hwlib.hpp>
#include "filled_rectangle.hpp"

/// \brief
/// filled_rectangle
/// \details
/// This function draws a filled rectangle on a specified screen 
void filled_rectangle::print(){
   for(int i=start_y; i<= end_y; i++){
      for(int j=start_x; j<= end_x; j++){
         w.hwlib::window::write(hwlib::xy(j,i));
      }
   }
   w.flush();
}
