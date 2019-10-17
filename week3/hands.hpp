#ifndef _HANDS_HPP
#define _HANDS_HPP

#include "hwlib.hpp"
#include "positions.hpp"

class hands {
protected:

    hwlib::window & w;
    int radiant;
    int maxAmount;
    const positions & posValue;

public:

    hands( hwlib::window & w, int radiant, int maxAmount, const positions & posValue ):

        w( w ),
        radiant( radiant ),
        maxAmount( maxAmount ),
        posValue( posValue )

    {}

    void draw( int value ){

        hwlib::line lineHour( hwlib::xy( 64, 32 ) , hwlib::xy( 64 - posValue.calcPositionsX[ value ], 32 - posValue.calcPositionsY[ value ] ) );
        lineHour.draw( w );

    };

};

#endif