// ==========================================================================
//
// OLED circle demo on DB103
//
// (c) Wouter van Ooijen (wouter@voti.nl) 2019
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt) 
//
// ==========================================================================

#include "hwlib.hpp"
#include "images.hpp"
#include "filled_rectangle.hpp"
#include "rectangle.hpp"





int main( void ){
       
   namespace target = hwlib::target;

 
   auto scl      = hwlib::target::pin_oc{ hwlib::target::pins::scl };
   auto sda      = hwlib::target::pin_oc{ hwlib::target::pins::sda };
   
   auto i2c_bus      = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto display      = hwlib::glcd_oled( i2c_bus, 0x3c  ); 
   
   images image_target(display);

   
   while(1){
      image_target.train();
      hwlib::wait_ms(1000);
      image_target.house();
      hwlib::wait_ms(1000);
      image_target.snowman();
      hwlib::wait_ms(1000);
   }

   
}
