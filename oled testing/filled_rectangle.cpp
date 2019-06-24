#include <hwlib.hpp>
#include "filled_rectangle.hpp"

void filled_rectangle::print(){
   for(int i=start_y; i<= end_y; i++){
      for(int j=start_x; j<= end_x; j++){
         w.hwlib::window::write(hwlib::xy(j,i));
      }
   }
   w.flush();
}
