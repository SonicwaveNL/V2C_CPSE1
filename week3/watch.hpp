#include "hwlib.hpp"
#include <ctime>
#include "positions.hpp"
#include "hands.hpp"

class watch {
protected:

   hwlib::window     & w;
   hwlib::pin_in     & btn;
   hwlib::circle     backplate;
   
   // Calculate hand positions within the watch
   const positions & posHour;
   const positions & posMinutes;
   const positions & posSeconds;
   const positions & posIcons;

   // Hands
   hands handHour;
   hands handMinutes;
   hands handSeconds;
   
   // Time specific counter
   int hourCounter   = 0;
   int minuteCounter = 0;
   int secondsCounter = 0;

public:

   watch( hwlib::window & w, hwlib::pin_in & btn, const positions & posHour, const positions & posMinutes, const positions & posSeconds, const positions & posIcons ):

      w( w ),
      btn( btn ),
      backplate( hwlib::xy( w.size.x / 2, w.size.y / 2 ), w.size.y / 2 - 2 ),
      posHour( posHour ),
      posMinutes( posMinutes ),
      posSeconds( posSeconds ),
      posIcons( posIcons ),
      handHour( w, w.size.y / 2, 12, posHour ),
      handMinutes( w, w.size.y / 2, 60, posMinutes ),
      handSeconds( w, w.size.y / 2, 60, posSeconds )

   {}

   void run(){

      uint64_t startTime = hwlib::now_us();
      uint64_t currentTime = 0;
      uint64_t checkTime = 900000;

      while(true){

         w.clear();

         currentTime = hwlib::now_us();

         if( btn.read() == false ){
            minuteCounter++;

            if( minuteCounter >= 60){
               minuteCounter = 0;
               hourCounter++;

            }

         }

         draw( hourCounter + 3, minuteCounter + 15, secondsCounter + 15 );
         
         if( currentTime - startTime >= checkTime ){
            startTime = hwlib::now_us();
            secondsCounter++;

         }

         if( secondsCounter >= 60 && minuteCounter >= 60 && hourCounter >= 12 ){
            minuteCounter = 0;
            hourCounter = 0;

         } else if( minuteCounter >= 60 && secondsCounter >= 60){
            minuteCounter = 0;
            secondsCounter = 0;
            hourCounter++;

         } else if( secondsCounter >= 60 ){
            secondsCounter = 0;
            minuteCounter++;

         }

         w.flush();

         hwlib::wait_ms( 100 );

         
         
      }

   }

   void setTime( int hour, int minute, int seconds ){

      while(true){

         w.clear();
         w.flush();
      
         draw( hour, minute, seconds );
         
         w.flush();
         hwlib::wait_ms( 100 );

      }


   }

   void draw( int hour, int minute, int seconds ) {

       backplate.draw( w );
       drawIcons();
       handHour.draw( hour );
       handMinutes.draw( minute );
       handSeconds.draw( seconds );

   }

   void drawIcons(){
      
      for( int i = 0; i < 12; i++){

         hwlib::circle icon( hwlib::xy( 64 - posIcons.calcPositionsX[ i ], 32 - posIcons.calcPositionsY[ i ] ), 1 );
         icon.draw( w );
      }

   }


};
