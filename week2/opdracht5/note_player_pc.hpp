#ifndef _NOTE_PLAYER_PC_HPP
#define _NOTE_PLAYER_PC_HPP

class note_player_pc {
protected:   
   const char* notes;
   int start = 0;

public: 

   void play( const char* song );
   void load_song( const char* song );
   void generate_melody( const char* song );
   
};

#endif
