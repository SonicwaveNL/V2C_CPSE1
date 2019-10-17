#include "hwlib.hpp"
#include <cmath>
#include "positions.hpp"
#include "watch.hpp"

int main( void ){

    namespace target = hwlib::target;

    auto scl          = hwlib::target::pin_oc{ hwlib::target::pins::scl };
    auto sda          = hwlib::target::pin_oc{ hwlib::target::pins::sda };
    auto btn          = hwlib::target::pin_in( hwlib::target::pins::d7 );

    auto i2c_bus      = hwlib::i2c_bus_bit_banged_scl_sda( scl, sda );
    auto oled         = hwlib::glcd_oled( i2c_bus );

    // Create positions
    constexpr positions posHour( 12, 24 );
    constexpr positions posMinutes( 60, 20 );
    constexpr positions posSeconds( 60, 28 );
    constexpr positions posIcons( 12, 27 );

    // Draw the watch and run it
    watch watchface( oled, btn, posHour, posMinutes, posSeconds, posIcons );
    hwlib::cout << hwlib::endl << "Starting watch..." << hwlib::endl;
    watchface.run();

}