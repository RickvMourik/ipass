#include "hwlib.hpp"
#include "application.hpp"
#include "images.hpp"
#include "adxl345.hpp"
#include "house.hpp"
#include "snowman.hpp"
#include "train.hpp"


   
/// \brief
/// application run
/// \details
/// This function is the application that makes the image change when you use the sensor. \n
/// You can change the threshold of every axis via the application constructor. \n
/// The constructor has base values and only needs the sensor and oled display if you choose to keep the threshold base values.\n
/// The posThreshX and Y are the values to determine when the acceleration or tilt in the right or up direction is high enough for the display to show the next image. \n
/// The negThreshX and Y are the values to determine when the acceleration or tilt in the left or down direction is high enough for the display to show the next image.\n
/// The high and low reset values are the values where the data from the axes has to be in between in order to change to image again.\n
/// As long as the axes have not been in the reset area at the same time the image will not change, no matter how far you tilt or how fast you accelerate the sensor.\n
/// If the negThresh value is bigger than the posThresh value, they wil automatically be swapped.
/// The same happens with the reset values.   
void application::run(){
   snowmanClass snow( oled_target );
   trainClass train( oled_target );
   houseClass house( oled_target );
   int counter = 1;
   bool go = 0;
   int valx = 0;
   int valy = 0;
   snow.draw();
   if(posThreshX < negThreshX){           // swapping posThresh en negTresh if neccesary
      int temp = posThreshX;
      posThreshX = negThreshX;
      negThreshX = temp;
      hwlib::cout << "posThresh and NegThresh x are swapped \n";
   } if(posThreshY < negThreshY){
      int temp = posThreshY;
      posThreshY = negThreshY;
      negThreshY = temp;
      hwlib::cout << "posThresh and NegThresh y are swapped \n";
   }if(highResetX < lowResetX){
      int temp = highResetX;
      highResetX = lowResetX;
      lowResetX = temp;
      hwlib::cout << "highReset and lowReset x are swapped \n";
   }if(highResetY < lowResetY){
      int temp = highResetY;
      highResetY = lowResetY;
      lowResetY = temp;
      hwlib::cout << "highReset and lowReset x are swapped \n";
   }
   while(1){
      valx = sensor.getX();
      valy = sensor.getY();
      hwlib::cout << hwlib::dec  <<"x= " << valx << " y= "<< valy << "\n";
      if( (valx > posThreshX && valy > negThreshY) || (valy > posThreshY && valx > negThreshX) ){                // counter goes up unless the counter already is 3 then it goes back to 1
	      if( counter == 1){
            counter =3;
         }else{
            counter --;
         }
         
         go = 1;
      }
      if( ( valx < negThreshX && valy <posThreshY) || ( valy < negThreshY && valx < posThreshX ) ){               // counter goes down unless the counter already is 1 then it goes back to 3
         if(counter == 3){
            counter =1;
         }else{
            counter ++;
         }
         go = 1;
      }
      if(go){                                                     // if statements to determine which image should be displayed and if go = 0 the picture won't change or update
         if(counter ==1){
            snow.draw();
         }
         if(counter ==2){
            train.draw();
         }
         if(counter == 3){
            house.draw();
         }
         while( valx <= lowResetX  || valx >= highResetX || valy <= lowResetY || valy >= highResetY ){
            valx = sensor.getX();
            valy = sensor.getY();
            hwlib::cout << hwlib::dec  <<"x= " << valx << " y= "<< valy << "\n";
         }
         go = 0;
      }
   }      
}