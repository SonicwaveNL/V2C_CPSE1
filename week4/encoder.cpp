#include <iostream>
#include <fstream>
#include <string>

#include "compressor.hpp" 

int main( void ){	
   lz_compressor< 4096 > compressor;

   std::cout << "\t=>\tGenerating encoder, generating files..." << std::endl << std::endl;
 
   std::ifstream f1;
   f1.open( "wilhelmus.txt" );
   if( ! f1.is_open()){
      std::cerr << "input file not opened\n";
      return -1;      
   }
   
   std::ofstream f2;
   f2.open( "encoded.asm" );
   if( ! f2.is_open()){
      std::cerr << "output file not opened\n";
      return -1;      
   }

   f2 << (std::string)".cpu cortex-m0\n";
   f2 << (std::string)".text\n";
   f2 << (std::string)"compressed_song: .asciz \"";

   compressor.compress( 
      [ &f1 ]()-> int { auto c = f1.get(); return f1.eof() ? '\0' : c; },
      [ &f2 ]( char c ){ c == '\n' ? f2.put('#') : f2.put( c ); }
   );

   f2 << (std::string)"\"\n";
   f2 << (std::string)".align 2\n";
   f2 << (std::string)".global compressed_song\n";
   f2 << (std::string)"\nset_song:";
   f2 << (std::string)"\n\tpush {r5, lr}";
   f2 << (std::string)"\n\tldr r5, =compressed_song";

   f1.close();
   f2.close();

   std::cout << "\t=>\tGenerated file, running ASM decoder..." << std::endl << std::endl;
   
}