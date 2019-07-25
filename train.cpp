#include <hwlib.hpp>
#include "filled_rectangle.hpp"
#include "rectangle.hpp"
#include "train.hpp"

/// \brief
/// images train
/// \details
/// This function draws a train on a screen 
void trainClass::draw(){
    //clear the display
    display.clear();
    display.flush();

    //setup for text
    auto font          = hwlib::font_default_8x8();
    auto display_font       = hwlib::terminal_from( display, font );
   
    display_font 
        << "\f" << "2" 
        << hwlib::flush;  

    //setup for the train
    rectangle train_engine(display, 85, 40, 116, 55);
    rectangle train_control(display, 69, 25, 85, 55);
    rectangle train_smoker(display, 105, 30, 110, 40);
    filled_rectangle train_top(display, 66, 24, 88, 26);
    filled_rectangle train_top2(display, 69, 22, 85, 26);
    filled_rectangle train_window(display, 74, 32, 80, 40);

    //display the train on the screen
    hwlib::line wheel_conector( {90,59}, {105,59});
    hwlib::circle train_wheel1( {75, 59}, 4);
    hwlib::circle train_wheel2( {90, 59}, 4);
    hwlib::circle train_wheel3( {105, 59}, 4);
    

    //setup for the train cart
    rectangle cart(display, 5, 30, 53, 55);
    filled_rectangle cart_top(display, 2, 28, 56, 30);
    filled_rectangle cart_topP2(display, 5, 26, 53, 30);
    filled_rectangle cart_window1(display, 10, 35, 18, 45);
    filled_rectangle cart_window2(display, 23, 35, 35, 45);
    filled_rectangle cart_window3(display, 40, 35, 48, 45);
    hwlib::line cart_connector({55,51}, {69, 51});
    hwlib::circle cart_wheel1( {11, 59}, 4);
    hwlib::circle cart_wheel2( {23, 59}, 4);
    hwlib::circle cart_wheel3( {35, 59}, 4);
    hwlib::circle cart_wheel4( {47, 59}, 4);

    //setup smoke
    hwlib::circle smoke1({107, 25}, 3);
    hwlib::circle smoke2({105, 20}, 5);
    hwlib::circle smoke3({107, 20}, 4);
    hwlib::circle smoke4({102, 15}, 5);
    hwlib::circle smoke5({101, 10}, 6);
    hwlib::circle smoke6({95, 10}, 6);
    hwlib::circle smoke7({95, 12}, 4);

    //draw everything
    //dislpay train
    train_engine.draw();
    train_control.draw();
    train_smoker.draw();
    train_top.draw();
    train_top2.draw();
    train_window.draw();
    wheel_conector.draw(display);
    train_wheel1.draw(display);
    train_wheel2.draw(display);
    train_wheel3.draw(display);

    //display the train cart on the screen
    cart.draw();
    cart_top.draw();
    cart_topP2.draw();
    cart_window1.draw();
    cart_window2.draw();
    cart_window3.draw();
    cart_connector.draw(display);
    cart_wheel1.draw(display);
    cart_wheel2.draw(display);
    cart_wheel3.draw(display);
    cart_wheel4.draw(display);

    //display smoke on the screen
    smoke1.draw(display);
    smoke2.draw(display);
    smoke3.draw(display);
    smoke4.draw(display);
    smoke5.draw(display);
    smoke6.draw(display);
    smoke7.draw(display);


    display.flush();

}