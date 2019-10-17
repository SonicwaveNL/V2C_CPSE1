#include <iostream>
#include "note_player_pc.hpp"
#include "fstream"
  
void note_player_pc::play( const char* song ){

    load_song( song );
    generate_melody( song );

    std::cout << std::endl << std::endl << std::endl;
    std::cout << "=========================START SONG=========================" << std::endl;

    int counter      = note_player_pc::start + 1;
    int note_counter = 1;
    bool found_note  = false;
    std::cout << "♪" << note_counter << '\t';

    while(true){

        if( song[counter] == '\0' ){
            break;

        } else if ( song[counter] == ',' ){
            found_note = false;
            note_counter++;
            std::cout << std::endl << "♪" << note_counter << '\t';

        } else if ( song[counter] >= 97 && song[counter] <= 122 ){
            found_note = true;
            int song_letter = song[counter] - 32;
            std::cout << (char)song_letter;

        } else if ( found_note && song[counter] != '.' ){
            std::cout << song[counter];

        }

        counter++;

    }
    
    std::cout << std::endl;
    std::cout << "==========================END SONG==========================" << std::endl;
    std::cout << std::endl << std::endl << std::endl;
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

    std::cout << std::endl << "===> \t Done loading!" << std::endl;

    note_player_pc::start = counter;
};

void note_player_pc::generate_melody( const char* song ){

    int counter      = note_player_pc::start + 1;
    int note_counter = 1;
    bool found_note  = false; 

    // Create a new file called 'melody.cpp' or overwrite the old one
    std::ofstream file;
    file.open( "melody.cpp", std::ios::out );

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

    }

    file << ",  note::dQ } );\n";

    file << "};";

    // Check if its possible to create a file, otherwise print error
    if(!file){
        std::cout << "===> \t Error creating Melody file" << std::endl;
    }

    std::cout << "===> \t Created Melody file succesfully!" << std::endl;
    file.close();

};