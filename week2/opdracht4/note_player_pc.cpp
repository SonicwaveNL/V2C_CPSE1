#include "hwlib.hpp"
#include "note_player_pc.hpp"
#include "fstream"

using namespace std;
  
void note_player_pc::play( const char* song ){

    load_song( song );
    // generate_notes( song );
    generate_melody( song );

    hwlib::cout << hwlib::endl << hwlib::endl << hwlib::endl;
    hwlib::cout << "=========================START SONG=========================" << hwlib::endl;

    int counter      = note_player_pc::start + 1;
    int note_counter = 1;
    bool found_note  = false;
    hwlib::cout << "♪" << note_counter << '\t';

    while(true){

        if( song[counter] == '\0' ){
            break;

        } else if ( song[counter] == ',' ){
            found_note = false;
            note_counter++;
            hwlib::cout << hwlib::endl << "♪" << note_counter << '\t';

        } else if ( song[counter] >= 97 && song[counter] <= 122 ){
            found_note = true;
            int song_letter = song[counter] - 32;
            hwlib::cout << (char)song_letter;

        } else if ( found_note && song[counter] != '.' ){
            hwlib::cout << song[counter];

        }

        counter++;

        hwlib::wait_ms(50);

    }
    
    hwlib::cout << hwlib::endl;
    hwlib::cout << "==========================END SONG==========================" << hwlib::endl;
    hwlib::cout << hwlib::endl << hwlib::endl << hwlib::endl;
};

void note_player_pc::load_song( const char* song ){
 
    int counter     = 0;
    bool found_name = false;

    while(true){

        if( song[counter] == '\0' ){
            counter = 0;
            break;

        } else if( song[counter] == ':' && found_name == false ){
            found_name = true;

        } else if( song[counter] == ':' && found_name == true ){
            break;

        }

        counter++;

    }

    hwlib::cout << hwlib::endl << "===> \t Done loading!" << hwlib::endl;

    note_player_pc::start = counter;
};

void note_player_pc::generate_melody( const char* song ){

    int counter      = note_player_pc::start + 1;
    int note_counter = 1;
    bool found_note  = false; 

    // Create a new file called 'melody.cpp' or overwrite the old one
    ofstream file;
    file.open( "melody.cpp", ios::out );

    file << "\n";
    file << "#include \"melody.hpp\"\n";
    file << "\n";
    file << "void melody::play( note_player & p ){\n";
    file << "\tp.play( note{ note::";

    while(true){

        if( song[counter] == '\0' ){
            break;

        } else if ( song[counter] == ',' ){
            found_note = false;
            note_counter++;
            file << ",  note::dQ } );\n";
            file << "\tp.play( note{ note::";

        } else if ( song[counter] >= 97 && song[counter] <= 122 ){
            found_note = true;
            int song_letter = song[counter] - 32;
            file << (char)song_letter;
            

        } else if ( found_note && song[counter] != '.' ){
            file << song[counter];

        }

        counter++;

        hwlib::wait_ms(50);

    }

    file << ",  note::dQ } );\n";

    file << "};";

    // Check if its possible to create a file, otherwise print error
    if(!file){
        hwlib::cout << "===> \t Error creating Melody file" << hwlib::endl;
    }

    hwlib::cout << "===> \t Created Melody file succesfully!" << hwlib::endl;
    file.close();

};