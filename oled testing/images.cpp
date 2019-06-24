#include <hwlib.hpp>
#include "filled_rectangle.hpp"
#include "rectangle.hpp"
#include "images.hpp"

void images::snowman(){
    display.clear();
    display.flush();

    auto font          = hwlib::font_default_8x8();
    auto display_font       = hwlib::terminal_from( display, font );
   
    display_font 
        << "\f" << "1" 
        << hwlib::flush;  

    hwlib::circle top_circle({64, 24}, 10);
    hwlib::circle bot_circle({64, 54}, 20);
   
    top_circle.draw(display); 
    bot_circle.draw(display);

    hwlib::circle eyeL_circle({60,20}, 2);
    hwlib::circle eyeR_circle({68,20}, 2);
    eyeL_circle.draw(display);
    eyeR_circle.draw(display);

    hwlib::circle button1_circle({64,42}, 2);
    hwlib::circle button2_circle({64,50}, 2);
    hwlib::circle button3_circle({64,58}, 2);

    button1_circle.draw(display);
    button2_circle.draw(display);
    button3_circle.draw(display);

    filled_rectangle top_hat( display, 59, 4, 69, 15);
    filled_rectangle bottom_hat( display, 55, 12, 73, 15);
    filled_rectangle mouth( display,62, 26, 66, 26);
    top_hat.print();
    bottom_hat.print();
    mouth.print();

    hwlib::line left_arm({35,20}, {48,42});
    left_arm.draw(display);

    display.flush();

}

void images::train(){
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
    train_engine.print();
    train_control.print();
    train_smoker.print();
    train_top.print();
    train_top2.print();
    train_window.print();

    //display the train on the screen
    hwlib::line wheel_conector( {90,59}, {105,59});
    hwlib::circle train_wheel1( {75, 59}, 4);
    hwlib::circle train_wheel2( {90, 59}, 4);
    hwlib::circle train_wheel3( {105, 59}, 4);
    wheel_conector.draw(display);
    train_wheel1.draw(display);
    train_wheel2.draw(display);
    train_wheel3.draw(display);

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

    //display the train cart on the screen
    cart.print();
    cart_top.print();
    cart_topP2.print();
    cart_window1.print();
    cart_window2.print();
    cart_window3.print();
    cart_connector.draw(display);
    cart_wheel1.draw(display);
    cart_wheel2.draw(display);
    cart_wheel3.draw(display);
    cart_wheel4.draw(display);

    //setup smoke
    hwlib::circle smoke1({107, 25}, 3);
    hwlib::circle smoke2({105, 20}, 5);
    hwlib::circle smoke3({107, 20}, 4);
    hwlib::circle smoke4({102, 15}, 5);
    hwlib::circle smoke5({101, 10}, 6);
    hwlib::circle smoke6({95, 10}, 6);
    hwlib::circle smoke7({95, 12}, 4);

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

void images::house(){
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

    //display left house base on the screen
    house_base.print();
    house_door.print();
    house_window1.print();
    house_window2.print();
    house_window3.print();
    house_window4.draw(display);
    house_window_deco1.draw(display);
    house_window_deco2.draw(display);
    house_roofP1.draw(display);
    house_roofP2.draw(display);

    //setup left garage
    rectangle garage_base(display, 41, 45, 61, 63);
    rectangle garage_door1(display, 44, 48, 58, 63);
    rectangle garage_door2(display, 44, 51, 58, 54);
    rectangle garage_door3(display, 44, 57, 58, 60);
  

    //display left garage on the screen
    garage_base.print();
    garage_door1.print();
    garage_door2.print();
    garage_door3.print();

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

    //diplsay right house base on the screen
    house2_base.print();
    house2_door.print();
    house2_window1.print();
    house2_window2.print();
    house2_window3.print();
    house2_window4.draw(display);
    house2_window_deco1.draw(display);
    house2_window_deco2.draw(display);
    house2_roofP1.draw(display);
    house2_roofP2.draw(display);

    //setup garage right house
    rectangle garage2_base(display, 72, 45, 92, 63);
    rectangle garage2_door1(display, 75, 48, 89, 63);
    rectangle garage2_door2(display, 75, 51, 89, 54);
    rectangle garage2_door3(display, 75, 57, 89, 60);
  
    //display garage right house
    garage2_base.print();
    garage2_door1.print();
    garage2_door2.print();
    garage2_door3.print();

    //setup laternpost
    filled_rectangle latern_base(display, 66, 58, 68, 63);
    filled_rectangle latern_top_flat(display, 64, 40, 70, 41);
    hwlib::line lantern({67, 40}, {67, 63});
    hwlib::circle lantern_top( {67,42}, 2);

    //display laternpost on the screen
    latern_base.print();
    latern_top_flat.print();
    lantern_top.draw(display);
    lantern.draw(display);

    display.flush();
}