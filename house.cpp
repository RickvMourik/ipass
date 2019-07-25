#include <hwlib.hpp>
#include "filled_rectangle.hpp"
#include "rectangle.hpp"
#include "house.hpp"

/// \brief
/// images house
/// \details
/// This function draws a house on a screen
void houseClass::draw(){
    //clear display
    display.clear();
    display.flush();

    //setup for text
    auto font          = hwlib::font_default_8x8();
    auto display_font       = hwlib::terminal_from( display, font );
   
    display_font 
        << "\f" << "3" 
        << hwlib::flush;  

    //setup for left house base
    rectangle house_base(display, 10, 25, 41, 63);
    rectangle house_door(display, 29, 48, 36, 63);
    filled_rectangle house_window1(display, 15, 50, 22, 55);
    filled_rectangle house_window2(display, 15, 33, 22, 38);
    filled_rectangle house_window3(display, 29, 33, 36, 38);
    hwlib::circle house_window4({26, 17}, 3);
    hwlib::line house_window_deco1({23,17}, {29,17});
    hwlib::line house_window_deco2({26,14}, {26,20});
    hwlib::line house_roofP1({5,30},{26, 5});
    hwlib::line house_roofP2({46,30},{26, 5});

    //setup left garage
    rectangle garage_base(display, 41, 45, 61, 63);
    rectangle garage_door1(display, 44, 48, 58, 63);
    rectangle garage_door2(display, 44, 51, 58, 54);
    rectangle garage_door3(display, 44, 57, 58, 60);
  

    //display left garage on the screen
    garage_base.draw();
    garage_door1.draw();
    garage_door2.draw();
    garage_door3.draw();

    //setup right house base
    rectangle house2_base(display, 92, 25, 123, 63);
    rectangle house2_door(display, 97, 48, 105, 63);
    filled_rectangle house2_window1(display, 109, 50, 116, 55);
    filled_rectangle house2_window2(display, 109, 33, 116, 38);
    filled_rectangle house2_window3(display, 98, 33, 105, 38);
    hwlib::circle house2_window4({107, 17}, 3);
    hwlib::line house2_window_deco1({104,17}, {110,17});
    hwlib::line house2_window_deco2({107,14}, {107,20});
    hwlib::line house2_roofP1({86,30},{107, 5});
    hwlib::line house2_roofP2({126,30},{107, 5});

    //setup garage right house
    rectangle garage2_base(display, 72, 45, 92, 63);
    rectangle garage2_door1(display, 75, 48, 89, 63);
    rectangle garage2_door2(display, 75, 51, 89, 54);
    rectangle garage2_door3(display, 75, 57, 89, 60);

    //setup laternpost
    filled_rectangle latern_base(display, 66, 58, 68, 63);
    filled_rectangle latern_top_flat(display, 64, 40, 70, 41);
    hwlib::line lantern({67, 40}, {67, 63});
    hwlib::circle lantern_top( {67,42}, 2);

    //display everything
    //display left house base on the screen
    house_base.draw();
    house_door.draw();
    house_window1.draw();
    house_window2.draw();
    house_window3.draw();
    house_window4.draw(display);
    house_window_deco1.draw(display);
    house_window_deco2.draw(display);
    house_roofP1.draw(display);
    house_roofP2.draw(display);

    //diplsay right house base on the screen
    house2_base.draw();
    house2_door.draw();
    house2_window1.draw();
    house2_window2.draw();
    house2_window3.draw();
    house2_window4.draw(display);
    house2_window_deco1.draw(display);
    house2_window_deco2.draw(display);
    house2_roofP1.draw(display);
    house2_roofP2.draw(display);

    //display laternpost on the screen
    latern_base.draw();
    latern_top_flat.draw();
    lantern_top.draw(display);
    lantern.draw(display);

    //display garage right house
    garage2_base.draw();
    garage2_door1.draw();
    garage2_door2.draw();
    garage2_door3.draw();

    display.flush();
}