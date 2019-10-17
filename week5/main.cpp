#define CATCH_CONFIG_MAIN 
#include "catch.hpp"

#include <ostream>
#include "collection.hpp"

TEST_CASE( "add element" ){
    collection<int, 10> x;
    x.add(13);
    REQUIRE( x.contains(13) );
    x.add(12);
    x.add(11);
    REQUIRE( x.contains(12) );
    REQUIRE( x.contains(11) );
    std::cout << "====================\n";
}

TEST_CASE( "remove element" ){
    collection<int, 10> x;
    x.add(11);
    x.add(13);
    x.add(12);
    x.remove(13);
    REQUIRE( ! x.contains(13) );
    std::cout << "====================\n";
}

TEST_CASE( "steam operator" ){
    collection<int, 10> x;
    x.add(13);
    std::cout << x;
    std::cout << '\n';
    REQUIRE( x.contains(13) ); 
    std::cout << "====================\n";
}

TEST_CASE( "float collection" ){
    collection<float, 30> x;
    x.add(1.12);
    x.add(3.67);
    x.add(16.1);
    REQUIRE( x.contains(16.1) );
    std::cout << "====================\n";
}

TEST_CASE( "char collection" ){
    collection<char, 13> x;
    x.add('J');
    x.add('U');
    x.add('S');
    x.remove('U');
    REQUIRE( ! x.contains('U') );
    std::cout << "====================\n";
}

TEST_CASE( "max" ){
    collection<int, 10> x;
    x.add(11);
    x.add(13);
    x.add(12);
    REQUIRE( x.max() == 13 );
    std::cout << "====================\n";
}

TEST_CASE( "char max" ){
    collection<char, 13> x;
    x.add('J');
    x.add('U');
    x.add('S');
    REQUIRE( x.max() == 'U' );
    std::cout << "====================\n";
}

