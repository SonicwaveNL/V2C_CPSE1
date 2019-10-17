#include "hwlib.hpp"
#include "note_player_pc.hpp"

  
void note_player_pc::play( const char* song ){

    load_song( song );

    hwlib::cout << hwlib::endl << hwlib::endl << hwlib::endl;
    hwlib::cout << "=========================START SONG=========================" << hwlib::endl;

    int counter      = note_player_pc::start + 1;
    int note_counter = 1;
    hwlib::cout << "♪" << note_counter << '\t';

    while(true){

        if( song[counter] == '\0' ){
            break;

        } else if ( song[counter] == ',' ){
            note_counter++;
            hwlib::cout << hwlib::endl << "♪" << note_counter << '\t';

        } else {
            hwlib::cout << song[counter];

        }

        counter++;

        hwlib::wait_ms(50);

    }
    
    hwlib::cout << hwlib::endl;
    hwlib::cout << "==========================END SONG==========================" << hwlib::endl;
    hwlib::cout << hwlib::endl << hwlib::endl << hwlib::endl;
}

void note_player_pc::load_song( const char* song ){
 
    int counter = 0;

    while(true){

        if( song[counter] == '\0' ){
            counter = 0;
            break;

        } else if ( song[counter] == ':' ){
            break;

        }

        counter++;

    }

    note_player_pc::start = counter;
};
