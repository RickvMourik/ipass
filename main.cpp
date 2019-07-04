#include "hwlib.hpp"
#include "images.hpp"
#include "filled_rectangle.hpp"
#include "rectangle.hpp"
#include "adxl345.hpp"

/// @file

/// \brief
/// main
/// \details
/// This is the main file of the programm.
/// Here you can alter the setup for the sensor.
/// The application is also made here.
int main( void ){

   /// \brief
   /// pin setup
   /// \details
   /// The pins of the oled screen, the sensor and the buttons are set here.
   /// The oled and sensor work via i2c communication.
   namespace target = hwlib::target;

 
   auto scl      = hwlib::target::pin_oc{ hwlib::target::pins::scl };
   auto sda      = hwlib::target::pin_oc{ hwlib::target::pins::sda };
   
   auto i2c_bus      = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   auto display      = hwlib::glcd_oled( i2c_bus, 0x3c  ); 

   auto scl_adxl      = hwlib::target::pin_oc{ hwlib::target::pins::d9 };
   auto sda_adxl     = hwlib::target::pin_oc{ hwlib::target::pins::d10 };
   
   auto i2c_bus_adxl     = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
   adxl345 sensor( i2c_bus_adxl);

   auto buttonDown = hwlib::target::pin_in( hwlib::target::pins::d12);
   auto buttonUp = hwlib::target::pin_in( hwlib::target::pins::d13);
   
   /// \brief
   /// adxl345 sensor setup
   /// \details
   /// Here you can configure the sensor to your needs with the functions of adxl345 for more details on how to configure the sensor, check the function
   
   sensor.powerOn();
   sensor.setRangeSetting();        //standard on 2g use 4, 8, 16 as value for other range
   sensor.setBitRate();             //standard 100 hz other options are: 1600, 800, 400, 200, 50, 25, 12, 6, 3
   sensor.setAxisOffset(0,0,0);     //set the offset of the axis 5.6 mg/LSB max 254
   
   //set to 1 to enable tap detextion for the axes
   bool tapX = 0;                   
   bool tapY = 0;
   bool tapZ = 0;
   bool suppresTap = 0;
   bool taps[4] = {suppresTap, tapX, tapY,tapZ};

   sensor.setTreshTap(10);             //threshold for tap interupts
   sensor.setTapDuration(0);           //set how long it takes for the a value to count as above the tap treshhold 0 disables tap threshold (625 μs/LSB)
   sensor.setTapDetection(taps);       //setting if the axel detects tap
   
   bool act_ac_dc = 0;                 //1 to compare first data after inactivity to new data, 0 to keep comparing to threshold 
   bool actX = 0;                      //1 to enable activity check for the axis, 0 to disable
   bool actY = 0;
   bool actZ = 0;
   bool inact_ac_dc = 0;               //1 to compare first data after inactivity to new data, 0 to keep comparing to threshold 
   bool inactX = 0;                    //1 to enable inactivity check for the axis, 0 to disable
   bool inactY = 0;
   bool inactZ = 0;
   bool act_inact_tot[8] = {act_ac_dc, actX, actY, actZ, inact_ac_dc, inactX, inactY, inactZ};

   sensor.setLatent(0);                //set time window to before double tap can be measured (1.25 ms/LSB) 0 disables double tap
   sensor.setWindow(0);                //set time window where double tap can be measured (1.25 ms/LSB) 0 disables double tap
   sensor.setTreshAct(10);             //set threshold for activity detection (62.5 mg/LSB)
   sensor.setTreshInact(10);           //set threshold for inactivity detection (62.5 mg/LSB)
   sensor.setInactTime(1);             //set time for how long a value has to be under inactivity threshold to be considered inactivity (1 sec/LSB)
   sensor.setActInactCtl(act_inact_tot);  //set the act and inact for the axes and compare data

   sensor.setFreeFallThresh(0);        //set freefall threshold (62.5 mg/LSB) 
   sensor.setFreeFalltime(0);          //set how long value must be under freefall threshold (5 ms/LSB)


   
   //interupt settings
   bool data_ready = 0;      
   bool single_tap = 0;
   bool double_tap = 0;
   bool activity = 0;
   bool inactivity = 0;
   bool freefall = 0;
   bool watermark = 0;
   bool overrun = 0;
   bool interrupts[8] = {data_ready, single_tap, double_tap, activity, inactivity, freefall, watermark, overrun};

   sensor.setInterrupts(interrupts);
   
   //application
   images image_target(display);
   int counter = 1;
   bool go = 0;
   image_target.snowman();
   while(1){
      buttonDown.refresh();
      if( buttonDown.read()){
	      if( counter == 1){
            counter =3;
         }else{
            counter --;
         }
         
         go = 1;
      }
      buttonUp.refresh();
      if( buttonUp.read()){
         if(counter == 3){
            counter =1;
         }else{
            counter ++;
         }
         go = 1;
      }
      if(go){
         if(counter ==1){
            image_target.snowman();
         }
         if(counter ==2){
            image_target.train();
         }
         if(counter == 3){
            image_target.house();
         }
         go = 0;
      }
   }      
}
