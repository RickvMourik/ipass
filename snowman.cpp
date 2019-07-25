#include <hwlib.hpp>
#include "filled_rectangle.hpp"
#include "rectangle.hpp"
#include "snowman.hpp"

/// \brief
/// images snowman
/// \details
/// This function draws a snowman on a screen 
void snowmanClass::draw(){
    display.clear();
    display.flush();

    auto font          = hwlib::font_default_8x8();
    auto display_font       = hwlib::terminal_from( display, font );
   
    display_font 
        << "\f" << "1" 
        << hwlib::flush;  

    //setup
    hwlib::circle top_circle({64, 24}, 10);
    hwlib::circle bot_circle({64, 54}, 20);

    hwlib::circle eyeL_circle({60,20}, 2);
    hwlib::circle eyeR_circle({68,20}, 2);

    hwlib::circle button1_circle({64,42}, 2);
    hwlib::circle button2_circle({64,50}, 2);
    hwlib::circle button3_circle({64,58}, 2);

    filled_rectangle top_hat( display, 59, 4, 69, 15);
    filled_rectangle bottom_hat( display, 55, 12, 73, 15);
    filled_rectangle mouth( display,62, 26, 66, 26);

    hwlib::line left_arm({35,20}, {48,42});
    


    //draw
    top_circle.draw(display); 
    bot_circle.draw(display);

    eyeL_circle.draw(display);
    eyeR_circle.draw(display);

    button1_circle.draw(display);
    button2_circle.draw(display);
    button3_circle.draw(display);

    top_hat.draw();
    bottom_hat.draw();
    mouth.draw();

    left_arm.draw(display);

    display.flush();
}

