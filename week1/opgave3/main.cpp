#include "hwlib.hpp"
extern "C" void application(void);

void uart_put_char( char c ){
   hwlib::cout << c;
}

extern "C" void change_word( char * l ){

   while( *l != '\0'){

      if( *l >= 65 && *l <= 90 ){
         *l += 32;

      } else if (*l >= 97 && *l <= 122){
         *l -= 32;

      }

      ++l;
   }

}

void print_asciz( const char * s ){
   while( *s != '\0'){
      uart_put_char( *s );
      ++s;
   }
}

int main( void ){	
   
   namespace target = hwlib::target;   
    
   // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application( "Hello world\n" );
}