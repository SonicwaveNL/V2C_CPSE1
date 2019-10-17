#include "hwlib.hpp"
extern "C" void print_asciz(void)

void uart_put_char( char c ){
   hwlib::cout << c;
}

void application(){
   print_asciz( "Hello world\n" );	
}

int main( void ){	
   
   namespace target = hwlib::target;   
    
      // wait for the PC console to start
   hwlib::wait_ms( 2000 );

   application();
}