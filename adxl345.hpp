#ifndef ADXL345_HPP
#define ADXL345_HPP

#include <hwlib.hpp>

//adxl345 registers
#define ADXL345_DEVID           0x00    //device id
#define ADXL345_RESERVED1       0x01    //reserved 1
#define ADXL345_RESERVED2       0x02    //reserved 2
#define ADXL345_RESERVED3       0x03    //reserved 3
#define ADXL345_RESERVED4       0x04    //reserved 4
#define ADXL345_RESERVED5       0x05    //reserved 5
#define ADXL345_RESERVED6       0x06    //reserved 6
#define ADXL345_RESERVED7       0x07    //reserved 7
#define ADXL345_RESERVED8       0x08    //reserved 8
#define ADXL345_RESERVED9       0x09    //reserved 9
#define ADXL345_RESERVED10      0x0a    //reserved 10
#define ADXL345_RESERVED11      0x0b    //reserved 11
#define ADXL345_RESERVED12      0x0c    //reserved 12
#define ADXL345_RESERVED13      0x0d    //reserved 13
#define ADXL345_RESERVED14      0x0e    //reserved 14
#define ADXL345_RESERVED15      0x0f    //reserved 15
#define ADXL345_RESERVED16      0x10    //reserved 16
#define ADXL345_RESERVED17      0x11    //reserved 17
#define ADXL345_RESERVED18      0x12    //reserved 18
#define ADXL345_RESERVED19      0x13    //reserved 19
#define ADXL345_RESERVED20      0x14    //reserved 20
#define ADXL345_RESERVED21      0x15    //reserved 21
#define ADXL345_RESERVED22      0x16    //reserved 22
#define ADXL345_RESERVED23      0x17    //reserved 23
#define ADXL345_RESERVED24      0x18    //reserved 24
#define ADXL345_RESERVED25      0x19    //reserved 25
#define ADXL345_RESERVED26      0x1a    //reserved 26
#define ADXL345_RESERVED27      0x1b    //reserved 27
#define ADXL345_RESERVED28      0x1c    //reserved 28
#define ADXL345_THRESH_TAP      0x1d    //Tap threshold
#define ADXL345_OFSX            0x1e    //X-axis offset 
#define ADXL345_OFSY            0x1f    //Y-axis offset 
#define ADXL345_OFSZ            0x20    //Z-axis offset 
#define ADXL345_DUR             0x21    //Tap duration 
#define ADXL345_LATENT          0x22    //Tap latency 
#define ADXL345_WINDOW          0x23    //Tap window 
#define ADXL345_THRESH_ACT      0x24    //Activity threshold 
#define ADXL345_THRESH_INACT    0x25    //Inactivity threshold 
#define ADXL345_TIME_INACT      0x26    //Inactivity time 
#define ADXL345_ACT_INACT_CTL   0x27    //Axis enable control for activity and inactivity detection
#define ADXL345_THRESH_FF       0x28    //Free-fall threshold 
#define ADXL345_TIME_FF         0x29    //Free-fall time 
#define ADXL345_TAP_AXES        0x2a    //Axis control for single tap/double tap 
#define ADXL345_ACT_TAP_STATUS  0x2b    //Source of single tap/double tap 
#define ADXL345_BW_RATE         0x2c    //Data rate and power mode control 
#define ADXL345_POWER_CTL       0x2d    //Power-saving features control 
#define ADXL345_INT_ENABLE      0x2e    //Interrupt enable control 
#define ADXL345_INT_MAP         0x2f    //Interrupt mapping control 
#define ADXL345_INT_SOURCE      0x30    //Source of interrupts
#define ADXL345_DATA_FORMAT     0x31    //Data format control 
#define ADXL345_DATAX0          0x32    //X-Axis Data 0 
#define ADXL345_DATAX1          0x33    //X-Axis Data 1
#define ADXL345_DATAY0          0x34    //Y-Axis Data 0 
#define ADXL345_DATAY1          0x35    //Y-Axis Data 1 
#define ADXL345_DATAZ0          0x36    //Z-Axis Data 0 
#define ADXL345_DATAZ1          0x37    //Z-Axis Data 1 
#define ADXL345_FIFO_CTL        0x38    //FIFO control 
#define ADXL345_FIFO_STATUS     0x39    //FIFO status 

#define ADXL345_BW_1600 0xF // 1111     1600hz bandwith 3200hz output
#define ADXL345_BW_800  0xE // 1110     800hz bandwith  1600hz output
#define ADXL345_BW_400  0xD // 1101     400hz bandwith  800hz output
#define ADXL345_BW_200  0xC // 1100     200hz bandwith  400hz output
#define ADXL345_BW_100  0xB // 1011     100hz bandwith  200hz output
#define ADXL345_BW_50   0xA // 1010     50hz bandwith   100hz output
#define ADXL345_BW_25   0x9 // 1001     25hz bandwith   50hz output
#define ADXL345_BW_12   0x8 // 1000     12hz bandwith   25hz output
#define ADXL345_BW_6    0x7 // 0111     6hz bandwith    12.5hz output
#define ADXL345_BW_3    0x6 // 0110     3hz bandwith    6.25hz output


//Interrupt PINs 
#define ADXL345_INT1_PIN 0x00   //INT1: 0
#define ADXL345_INT2_PIN 0x01   //INT2: 1

//Interrupt bit position
#define ADXL345_INT_DATA_READY_BIT 0x07
#define ADXL345_INT_SINGLE_TAP_BIT 0x06
#define ADXL345_INT_DOUBLE_TAP_BIT 0x05
#define ADXL345_INT_ACTIVITY_BIT   0x04
#define ADXL345_INT_INACTIVITY_BIT 0x03
#define ADXL345_INT_FREE_FALL_BIT  0x02
#define ADXL345_INT_WATERMARK_BIT  0x01
#define ADXL345_INT_OVERRUNY_BIT   0x00


class adxl345{
    private:
        /// the i2c channel
        hwlib::i2c_bus & bus;
        uint8_t address_base;
        

    public:
        /// construct with both read and write adress	
        adxl345( hwlib::i2c_bus & bus, uint8_t address_base =  0x53):
            bus( bus ),
            address_base( address_base )

    {}

    void writeReg( uint8_t reg, uint8_t value );
    int8_t read8( uint8_t reg );
    int16_t getX();
    int16_t getY();
    int16_t getZ();
    void getAxes(int & x, int & y, int & z);
    void showAxes();
    void powerOn();
    void setRangeSetting(int val = 2);
    void getRangeSetting();
    void setBitRate(int val =100);
    void getBitRate();
    void setAxisOffset(int x, int y, int z);
    void getAxisOffset();
    void setInterrupts(bool b[8]);
    void getInterrupts();
    void setTreshTap(unsigned int val);
    void getTreshTap();
    void setTapDetection(bool b[4]);
    void getTapDetection();
    void setTapDuration(unsigned int val);
    void getTapDuration();
    void setLatent(unsigned int val);
    void getLatent();
    void setWindow(unsigned int val);
    void getWindow();
    void setTreshAct(unsigned int val);
    void getTreshAct();
    void setTreshInact(unsigned int val);
    void getTreshInact();
    void setInactTime(unsigned int val);
    void getInactTime();
    void setActInactCtl(bool b[8]);
    void getActInactCtl();
    void setFreeFallThresh(unsigned int val);
    void getFreeFallThresh();
    void setFreeFallTime(unsigned int val);
    void getFreeFallTime();
    void getAllSettings();
};

#endif // ADXL345_HPP