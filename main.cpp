#include "hwlib.hpp"
#include "images.hpp"
#include "filled_rectangle.hpp"
#include "rectangle.hpp"
#include "adxl345.hpp"
#include "application.hpp"
#include "snowman.hpp"
#include "train.hpp"
#include "house.hpp"

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
   adxl345 sensor( i2c_bus, 0x53);


   /// \brief
   /// adxl345 sensor setup
   /// \details
   /// Here you can configure the sensor to your needs with the functions of adxl345 for more details on how to configure the sensor, check the function
   
   sensor.powerOn();
   sensor.setRangeSetting(4);        //standard on 2g use 4, 8, 16 as value for other range
   sensor.setBitRate(100);             //standard 100 hz other options are: 1600, 800, 400, 200, 50, 25, 12, 6, 3
   sensor.setAxisOffset(-4, -12, -58);     //set the offset of the axis 5.6 mg/LSB max 254
   
   //set to 1 to enable tap detextion for the axes
   bool suppresTap = 0;
   bool tapX = 0;                   
   bool tapY = 0;
   bool tapZ = 0;
   bool taps[4] = {tapZ, tapY, tapX, suppresTap};

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
   bool act_inact_tot[8] = {inactZ, inactY, inactX, inact_ac_dc, actZ, actY, act_ac_dc, actX};

   sensor.setLatent(0);                //set time window to before double tap can be measured (1.25 ms/LSB) 0 disables double tap
   sensor.setWindow(0);                //set time window where double tap can be measured (1.25 ms/LSB) 0 disables double tap
   sensor.setTreshAct(10);             //set threshold for activity detection (62.5 mg/LSB)
   sensor.setTreshInact(10);           //set threshold for inactivity detection (62.5 mg/LSB)
   sensor.setInactTime(1);             //set time for how long a value has to be under inactivity threshold to be considered inactivity (1 sec/LSB)
   sensor.setActInactCtl(act_inact_tot);  //set the act and inact for the axes and compare data

   sensor.setFreeFallThresh(0);        //set freefall threshold (62.5 mg/LSB) 
   sensor.setFreeFallTime(0);          //set how long value must be under freefall threshold (5 ms/LSB)
   
   //interupt settings
   bool data_ready = 0;      
   bool single_tap = 0;
   bool double_tap = 0;
   bool activity = 0;
   bool inactivity = 0;
   bool freefall = 0;
   bool watermark = 0;
   bool overrun = 0;
   bool interrupts[8] = {overrun, watermark, freefall, inactivity, activity, double_tap, single_tap, data_ready};

   sensor.setInterrupts(interrupts);
   
   sensor.getAllSettings();
   hwlib::wait_ms(2000);
   //
   //application setup
   application app(sensor, display);
   app.run();
}