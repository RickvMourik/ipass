#include "hwlib.hpp"
#include "adxl345.hpp"

/// \brief
/// adxl345 writeReg
/// \details
/// This is the function to write data to the sensor on the correct register.\n
/// all you need to give is the register and the value you want to set the register.
void adxl345::writeReg( uint8_t reg, uint8_t value ){
      auto transaction = bus.write( address_base );
      transaction.write( reg );
      transaction.write( value );
}  

/// \brief
/// adxl345 read 8 bits
/// \details
/// With this function you can read the byte of the register you define.
int8_t adxl345::read8( uint8_t reg ){
   bus.write( address_base ).write( reg );
   return bus.read( address_base ).read_byte();
}

/// \brief
/// adxl345 get acceleration from the x axis
/// \details
/// This function gets the acceleration the x axis and returns this value.
int16_t adxl345::getX(){
   bus.write( address_base ).write( ADXL345_DATAX0 );
   auto transaction = bus.read( address_base );
   auto b1 = transaction.read_byte();
   auto b2 = transaction.read_byte();
   return (int) ((b2 << 8 ) | ( b1 ));
}

/// \brief
/// adxl345 get acceleration from the y axis
/// \details
/// This function gets the acceleration the y axis and returns this value.
int16_t adxl345::getY(){
   bus.write( address_base ).write( ADXL345_DATAY0 );
   auto transaction = bus.read( address_base );
   auto b1 = transaction.read_byte();
   auto b2 = transaction.read_byte();
   return (int) ((b2 << 8 ) | ( b1 ));
}

/// \brief
/// adxl345 get acceleration from the z axis
/// \details
/// This function gets the acceleration the z axis and returns this value.
int16_t adxl345::getZ(){
   bus.write( address_base ).write( ADXL345_DATAZ0 );
   auto transaction = bus.read( address_base );
   auto b1 = transaction.read_byte();
   auto b2 = transaction.read_byte();
   return (int) ((b2 << 8 ) | ( b1 ));
}

/// \brief
/// adxl345 gets the acceleration from all axes
/// \details
/// This function gets the acceleration from all the axes and saves the data in the given variables.
void adxl345::getAxes(int & x, int & y, int & z){
   x = getX();
   y = getY();
   z = getZ();
}

/// \brief
/// adxl345 show acceleration all axes
/// \details
/// This function displays the acceleration of every axis.
void adxl345::showAxes(){
   int xAxis;
   int yAxis;
   int zAxis;
   getAxes(xAxis, yAxis, zAxis);
   hwlib::cout << "the x axis = " << hwlib::dec << xAxis << " the y axis = " << yAxis << " the z axis = "<< zAxis << "\n";
}


/// \brief
/// adxl345 powerOn
/// \details
/// This function powers on the sensor and the puts in measurement mode
void adxl345::powerOn() {
	//Turning on the ADXL345 with measurement mode on
	writeReg(ADXL345_POWER_CTL, 0x00);      
	writeReg(ADXL345_POWER_CTL, 0x08); 
}

/// \brief
/// adxl345 set range
/// \details
/// This function sets the range of the sensor in g's. \n
/// The options are 2, 4, 8 and 16 g's.\n
/// If an incorrect value is given the range is automatically set to 2g
void adxl345::setRangeSetting(int val) {
   uint8_t  byte_code;
	if(val == 4){
      byte_code = 0x01;
   }else if(val == 8){
      byte_code = 0x02;
   }else if (val == 16){
      byte_code = 0x03;
   }else{
      byte_code = 0x00;
   }
	writeReg(ADXL345_DATA_FORMAT, byte_code);
}

/// \brief
/// adxl345 get range
/// \details
/// With this function you can read the data set on the data_format register. \n
/// The output is in hex.
void adxl345::getRangeSetting() {
   int range;
   int rangeCode = read8(ADXL345_DATA_FORMAT);
   if(rangeCode == 3){
      range = 16;
   }if(rangeCode == 2){
      range = 8;
   }if(rangeCode == 1){
      range = 4;
   }if(rangeCode == 0){
      range = 2;
   }
   hwlib::cout << "the range is " << hwlib::dec << range << "g \n";
}

/// \brief
/// adxl345 set bit rate
/// \details
/// This function sets the bitrate for the sensor, the output rate of the sensor is double the bitrate. \n
/// If an incorrect value is given the bitrate is set to 100 hz. \n
/// The bitrate value is send to the correct register. \n
/// A couple of the low bitrates (lower than 3hz) are left out of this function.
void adxl345::setBitRate(int val){
   if(val == 1600){
      writeReg(ADXL345_BW_RATE, ADXL345_BW_1600);
   }else if(val == 800){
      writeReg(ADXL345_BW_RATE, ADXL345_BW_800);
   }else if(val == 400){
      writeReg(ADXL345_BW_RATE, ADXL345_BW_400);
   }else if(val == 200){
      writeReg(ADXL345_BW_RATE, ADXL345_BW_200);
   }else if(val == 50){
      writeReg(ADXL345_BW_RATE, ADXL345_BW_50);
   }else if(val == 25){
      writeReg(ADXL345_BW_RATE, ADXL345_BW_25);
   }else if(val == 12){
      writeReg(ADXL345_BW_RATE, ADXL345_BW_12);
   }else if(val == 6){
      writeReg(ADXL345_BW_RATE, ADXL345_BW_6);
   }else if(val == 3){
      writeReg(ADXL345_BW_RATE, ADXL345_BW_3);
   }else{
      writeReg(ADXL345_BW_RATE, ADXL345_BW_100);
   }
}

/// \brief
/// adxl345 get bitrate
/// \details
/// With this function you can read the data set on the bw_rate register. \n
/// The output is the bitrate.
void adxl345::getBitRate() {
   int bitrate;
   int bitrateCode = read8(ADXL345_BW_RATE);
   if(bitrateCode == 15){
      bitrate = 1600;
   }if(bitrateCode == 14){
      bitrate = 800;
   }if(bitrateCode == 13){
      bitrate = 400;
   }if(bitrateCode == 12){
      bitrate = 200;
   }if(bitrateCode == 11){
      bitrate =100;
   }if(bitrateCode == 10){
      bitrate = 50;
   }if(bitrateCode == 9){
      bitrate = 25;
   }if(bitrateCode == 8){
      bitrate = 12;
   }if(bitrateCode == 7){
      bitrate = 6;
   }if(bitrateCode == 6){
      bitrate = 3;
   }
   hwlib::cout << "the bitrate is " << hwlib::dec << bitrate << "hz \n";
}

/// \brief
/// adxl345 set axis offset
/// \details
/// With this function you can set the offset each individual axis. \n
/// The offset changes with 5.6 mg/LSB. \n
/// The max value you can give is 255.
void adxl345::setAxisOffset(int x, int y, int z) {
	writeReg(ADXL345_OFSX, (uint8_t) x);  
	writeReg(ADXL345_OFSY, (uint8_t) y);  
	writeReg(ADXL345_OFSZ, (uint8_t) z);  
}

/// \brief
/// adxl345 get offset
/// \details
/// With this function you can read the data set on the x,y and z offset registers. \n
/// The output is in integer.
void adxl345::getAxisOffset() {
   hwlib::cout << "the x offset integer is " <<  hwlib::dec << read8(ADXL345_OFSX) << "\n";
   hwlib::cout << "the y offset integer is " <<  hwlib::dec << read8(ADXL345_OFSY) << "\n";
   hwlib::cout << "the z offset integer is " <<  hwlib::dec << read8(ADXL345_OFSZ) << "\n";
}


/// \brief
/// adxl345 set interrupts
/// \details
/// This is the function enables or disbales the possiblity to generate interrupts. \n
/// when the bool is false the interrupt function is disabled \n
/// The bool order is DATA_READY (d7) SINGLE_TAP (d6) DOUBLE_TAP (d5) Activity (d4) Inactivity (d3) FREE_FALL (d2) Watermark (d1) Overrun (d0) 
void adxl345::setInterrupts(bool b[8]){
    unsigned char c = 0;
    for (int i=0; i < 8; ++i){
       if (b[i]){
          c |= 1 << i;
       }     
    }
    writeReg(ADXL345_INT_ENABLE, c);
}

/// \brief
/// adxl345 get interrupts
/// \details
/// With this function you can read the data set on the interrupt register. \n
/// The output is in hex.
void adxl345::getInterrupts(){
   hwlib::cout << "the interrupts binairy code is " << hwlib::bin << read8(ADXL345_INT_ENABLE) << "\n";
}

/// \brief
/// adxl345 set tap threshold
/// \details
/// This function sets the value which needs to be exceeded for tap interrupts. \n
/// The scale factor is 62.5 mg/LSB, this makes 0xff or 255 16g.
void adxl345::setTreshTap(unsigned int val = 0){
   if(val > 255){
      val = 255;
   }
   writeReg(ADXL345_THRESH_TAP, (uint8_t) val);
}

/// \brief
/// adxl345 get interrupts
/// \details
/// With this function you can read the data set on the tap threshold register. \n
/// The output is in integer.
void adxl345::getTreshTap(){
   hwlib::cout << "the tap threshold integer is " << hwlib::dec << read8(ADXL345_THRESH_TAP) << "\n";
}

/// \brief
/// adxl345 set tap detection
/// \details
/// This is the function enables or disables the axis from detection taps and enables or disables double tap.
void adxl345::setTapDetection(bool b[4]){
   unsigned char c = 0;
    for (int i=0; i < 8; ++i){
       if (b[i]){
          c |= 1 << i;
       }     
    }
    writeReg(ADXL345_TAP_AXES, (uint8_t) c);
}

/// \brief
/// adxl345 get tap detection
/// \details
/// With this function you can read the data set on the interrupt register. \n
/// The output is in hex.
void adxl345::getTapDetection(){
   hwlib::cout << "the tap detection binairy code is " << hwlib::bin << read8(ADXL345_TAP_AXES) << "\n";
}

/// \brief
/// adxl345 set tap duration
/// \details
/// This is the function sets how long it takes for a value to count as above the tap treshhold 0 disables tap threshold. \n
/// The scale factor is 625 μs/LSB. \n
/// When a acceleration last shorter than threshold it won't register.
void adxl345::setTapDuration(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_DUR, (uint8_t) val);
}

/// \brief
/// adxl345 get tap duration
/// \details
/// With this function you can read the data set on the tap duration register. \n
/// The output is in hex.
void adxl345::getTapDuration(){
   hwlib::cout << "the tap duration integer is " << hwlib::dec << read8(ADXL345_DUR) << "\n";
}

/// \brief
/// adxl345 set latent
/// \details
/// set the time window for the time between one tap and another where it doesn't register. \n
/// The scale factor is 1.25 ms/LSB. \n
/// The max value is 255 and 0 disables double tap.
void adxl345::setLatent(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_LATENT, (uint8_t) val);
}

/// \brief
/// adxl345 get latent
/// \details
/// With this function you can read the data set on the latent register. \n
/// The output is in interger.
void adxl345::getLatent(){
   hwlib::cout << "the latent integer is " << hwlib::dec << read8(ADXL345_LATENT) << "\n";
}

/// \brief
/// adxl345 set window
/// \details
/// This function sets the time window where double tap can be measured after the latent wait time. \n
/// The scale factor is 1.25 ms/LSB. \n
/// The max value is 255 and 0 disables double tap.
void adxl345::setWindow(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_WINDOW, (uint8_t) val);
}

/// \brief
/// adxl345 get window
/// \details
/// With this function you can read the data set on the window register. \n
/// The output is in interger.
void adxl345::getWindow(){
   hwlib::cout << "the window integer is " << hwlib::dec << read8(ADXL345_WINDOW) << "\n";
}

/// \brief
/// adxl345 set activity threshold
/// \details
/// This is the function sets the activity threshold. \n
/// The scale factor is 62.5 mg/LSB. \n
/// When zero is used don't enable the activity intterupt
void adxl345::setTreshAct(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_THRESH_ACT, (uint8_t) val);
}

/// \brief
/// adxl345 get activity threshold
/// \details
/// With this function you can read the data set on the activity threshold register. \n
/// The output is in interger.
void adxl345::getTreshAct(){
   hwlib::cout << "the window integer is " << hwlib::dec << read8(ADXL345_THRESH_ACT) << "\n";
}

/// \brief
/// adxl345 set inactivity threshold
/// \details
/// This is the function sets the inactivity threshold. \n
/// The scale factor is 62.5 mg/LSB. \n
/// When zero is used don't enable the inactivity intterupt
void adxl345::setTreshInact(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_THRESH_INACT, (uint8_t) val);
}

/// \brief
/// adxl345 get inactivity threshold
/// \details
/// With this function you can read the data set on the inactivity threshold register. \n
/// The output is in interger.
void adxl345::getTreshInact(){
   hwlib::cout << "the inactivity threshold integer is " << hwlib::dec << read8(ADXL345_THRESH_INACT) << "\n";
}

/// \brief
/// adxl345 sets the inactivity time
/// \details
/// This is the function set the time for how long a value has to be under the inactivity threshold before it is considered to be inactive. \n
/// The scale factor is  1 sec/LSB. \n
/// If the value is 0 it won't put write out any values under the threshold.
void adxl345::setInactTime(unsigned int val){
   writeReg(ADXL345_TIME_INACT, (uint8_t) val);
}

/// \brief
/// adxl345 get inactivity time
/// \details
/// With this function you can read the data set on the inactivity time register. \n
/// The output is in interger.
void adxl345::getInactTime(){
   hwlib::cout << "the inactivity time integer is " << hwlib::dec << read8(ADXL345_TIME_INACT) << "\n";
}

/// \brief
/// adxl345 set the activity and inactivity
/// \details
/// This is the function sets the active and inactive bits for each axis. \n
/// It also changes the value with which the next value is compared, this can be the threshold or the first value that is above the threshold.
void adxl345::setActInactCtl(bool b[8]){
   unsigned char c = 0;
    for (int i=0; i < 8; ++i){
       if (b[i]){
          c |= 1 << (i);
       }     
    }
    writeReg(ADXL345_ACT_INACT_CTL, c);
}

/// \brief
/// adxl345 get activity/inactivity control
/// \details
/// With this function you can read the data set on the activity/inactivity control register. \n
/// The output is in hex.
void adxl345::getActInactCtl(){
   hwlib::cout << "the activity/inactivity binairy code is " << hwlib::bin << read8(ADXL345_ACT_INACT_CTL) << "\n";
}

/// \brief
/// adxl345 set freefall threshold
/// \details
/// This is the function sets the freefall threshold. \n
/// The scale factor is  62.5 mg/LSB.
void adxl345::setFreeFallThresh(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_THRESH_FF, (uint8_t) val);
}

/// \brief
/// adxl345 get free fall threshold
/// \details
/// With this function you can read the data set on the free fall threshold register. \n
/// The output is in interger.
void adxl345::getFreeFallThresh(){
   hwlib::cout << "the free fall threshold integer is " << hwlib::dec << read8(ADXL345_THRESH_FF) << "\n";
}

/// \brief
/// adxl345 set freefall time
/// \details
/// This is the function sets the time for how long a value has to be above the freefall threshold to be in freefall
void adxl345::setFreeFallTime(unsigned int val){
   writeReg(ADXL345_TIME_FF, (uint8_t) val);
}

/// \brief
/// adxl345 get free fall time
/// \details
/// With this function you can read the data set on the free fall time register. \n
/// The output is in interger.
void adxl345::getFreeFallTime(){
   hwlib::cout << "the free fall time integer is " << hwlib::dec << read8(ADXL345_TIME_FF) << "\n";
}

/// \brief
/// adxl345 get all settings
/// \details
/// This function calls every get function for the settings.
void adxl345::getAllSettings(){
   getRangeSetting();
   getBitRate();
   getAxisOffset();
   getTreshTap();
   getTapDuration();
   getTapDetection();
   getLatent();
   getWindow();
   getTreshAct();
   getTreshInact();
   getInactTime();
   getActInactCtl();
   getFreeFallThresh();
   getFreeFallTime();
   getInterrupts();
}