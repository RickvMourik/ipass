#include "hwlib.hpp"
#include "adxl345.hpp"

/// \brief
/// adxl345 writeReg
/// \details
/// This is the function write data to the sensor on the correct register.
/// all you need to give is the register and the value you want to set the register
void adxl345::writeReg( uint8_t reg, uint8_t value ){
      auto transaction = bus.write( address_base );
      transaction.write( reg );
      transaction.write( value );
}  


uint8_t adxl345::read8( uint8_t reg ){
   bus.write( address_base ).write( reg );
   return bus.read( address_base ).read_byte();
}


int16_t adxl345::read16( uint8_t reg ){
   bus.write( address_base ).write( reg );
   auto transaction = bus.read( address_base );
   auto b1 = transaction.read_byte();
   auto b2 = transaction.read_byte();
   return ( b1 << 8 ) | ( b2 );
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
/// This function sets the range of the sensor in g's.
/// The options are 2, 4, 8 and 16 g's.
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
/// adxl345 set bit rate
/// \details
/// This function sets the bitrate for the sensor, output rate of the sensor is double the bitrate.
/// If an incorrect value is given the bitrate is set to 100 hz
/// The bitrate value is send to the correct register
/// a couple of the low bitrates (lower than 3hz) are left out of this function
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
/// adxl345 set axis offset
/// \details
/// With this function you can set the offset each individual axis.
/// The offset changes with 5.6 mg/LSB.
/// The max value you can give is 255.
void adxl345::setAxisOffset(int x, int y, int z) {
	writeReg(ADXL345_OFSX, (uint8_t) x);  
	writeReg(ADXL345_OFSY, (uint8_t) y);  
	writeReg(ADXL345_OFSZ, (uint8_t) z);  
}

/// \brief
/// adxl345 set interrupts
/// \details
/// This is the function enables or disbales the possiblity to generate interrupts.
/// when the bool is false the interrupt function is disabled
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
/// adxl345 set tap threshold
/// \details
/// This function sets the value which needs to be exceeded for tap interrupts.
/// The scale factor is 62.5 mg/LSB, this makes 0xff or 255 16g
void adxl345::setTreshTap(unsigned int val = 0){
   if(val > 255){
      val = 255;
   }
   writeReg(ADXL345_THRESH_TAP, (uint8_t) val);
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
/// adxl345 set tap duration
/// \details
/// This is the function sets how long it takes for a value to count as above the tap treshhold 0 disables tap threshold.
/// The scale factor is 625 μs/LSB
/// When a acceleration last shorter than threshold it won't register.
void adxl345::setTapDuration(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_DUR, (uint8_t) val);
}

/// \brief
/// adxl345 set latent
/// \details
/// set the time window for the time between one tap and another where it doesn't register.
/// The scale factor is 1.25 ms/LSB.
/// The max value is 255 and 0 disables double tap.
void adxl345::setLatent(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_LATENT, (uint8_t) val);
}

/// \brief
/// adxl345 set window
/// \details
/// This function sets the time window where double tap can be measured after the latent wait time.
/// The scale factor is 1.25 ms/LSB.
/// The max value is 255 and 0 disables double tap.
void adxl345::setWindow(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_WINDOW, (uint8_t) val);
}

/// \brief
/// adxl345 set activity threshold
/// \details
/// This is the function sets the activity threshold.
/// The scale factor is 62.5 mg/LSB.
/// When zero is used don't enable the activity intterupt
void adxl345::setTreshAct(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_THRESH_ACT, (uint8_t) val);
}

/// \brief
/// adxl345 set inactivity threshold
/// \details
/// This is the function sets the inactivity threshold.
/// The scale factor is 62.5 mg/LSB.
/// When zero is used don't enable the inactivity intterupt
void adxl345::setTreshInact(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_THRESH_INACT, (uint8_t) val);
}

/// \brief
/// adxl345 sets the inactivity time
/// \details
/// This is the function set the time for how long a value has to be under the inactivity threshold before it is considered to be inactive.
/// The scale factor is  1 sec/LSB.
/// If the value is 0 it won't put write out any values under the threshold.
void adxl345::setInactTime(unsigned int val){
   writeReg(ADXL345_TIME_INACT, (uint8_t) val);
}

/// \brief
/// adxl345 set the activity and inactivity
/// \details
/// This is the function sets the active and inactive bits for each axis.
/// It also changes the value with which the next value is compared, this can be the threshold or the first value that is above the threshold.
void adxl345::setActInactCtl(bool b[8]){
   unsigned char c = 0;
    for (int i=0; i < 8; ++i){
       if (b[i]){
          c |= 1 << i;
       }     
    }
    writeReg(ADXL345_ACT_INACT_CTL, c);
}

/// \brief
/// adxl345 set freefall threshold
/// \details
/// This is the function sets the freefall threshold.
/// The scale factor is  62.5 mg/LSB.
void adxl345::setFreeFallThresh(unsigned int val){
   if(val >255){
      val = 255;
   }
   writeReg(ADXL345_THRESH_FF, (uint8_t) val);
}

/// \brief
/// adxl345 set freefall time
/// \details
/// This is the function sets the time for how long a value has to be above the freefall threshold to be in freefall
void adxl345::setFreeFalltime(unsigned int val){

   writeReg(ADXL345_TIME_FF, (uint8_t) val);
}

