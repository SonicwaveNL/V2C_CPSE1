#include "hwlib.hpp"

extern "C" void show_result( char c ){
   hwlib::cout << c;
}

extern "C" void start();

int main(){

   hwlib::wait_ms( 2000 );
   hwlib::cout << "=>\t Starting printing..." << hwlib::endl;
   start();

}