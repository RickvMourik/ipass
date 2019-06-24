#include <hwlib.hpp>


class adxl345{
    private:
        i2c_bus & bus;
        uint_fast8_t address;

    public:
        /// construct by providing the i2c channel	
    adxl345( i2c_bus & bus, uint_fast8_t address = 0x3B ):
      bus( bus ),
      address( address )

   {
      // wait for the controller to be ready for the initialization       
      wait_ms( 20 );
   }
}

