#ifndef _POSITIONS_HPP
#define _POSITIONS_HPP

#include "hwlib.hpp"
#include <cmath>
#include <vector>

using namespace std;

class positions {
protected:

    int value;
    int radiant;
 
public:

    int calcPositionsX[100];
    int calcPositionsY[100];

    constexpr positions( int value, int radiant ):

        value( value ),
        radiant( radiant ),
        calcPositionsX(),
        calcPositionsY()
    {
        genPositions();
    }


    // Calculate the 'X' line position with Cosinus
    template <typename T>
    constexpr T calcX( T givenAmount ) const {

        double deg     = 360 / value * givenAmount;
        double calcCos = cos(deg * 3.1415 / 180);

        return calcCos * radiant;

    }

    // Calculate the 'Y' position with Sinus
    template <typename T>
    constexpr T calcY( T givenAmount ) const {

        double deg     = 360 / value * givenAmount;
        double calcSin = sin(deg * 3.1415 / 180);

        return calcSin * radiant;

    }

    constexpr void genPositions(){

        int getValue = value + ( value / 4 );

        for( int i = 0; i < getValue; i++ ){

            const int x = calcX<int>( i );
            const int y = calcY<int>( i );

            calcPositionsX[i] = x;
            calcPositionsY[i] = y;

        }

    }

};

#endif