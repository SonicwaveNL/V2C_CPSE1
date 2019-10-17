#include <iostream>
#include <array>

template <typename T, int M>
class collection{
private:

    int totalItems = 0;
    std::array<T, M> numbers;

public:

    void add( T value ){

        // Check if the numbers collection is full
        // If true, return and sent a message to terminal
        if( totalItems == M ){

        std::cout << "===>\tNumbers is full!" << std::endl;
        return;

        };

        // Check if value is already in collection
        // If true, return and sent a message to terminal
        for( auto n : numbers ){

            if( value == n ){
                std::cout << "===>\tNumber already in numbers collection!" << std::endl;
                return;
            }

        };

        // Add value to numbers collection
        numbers[totalItems] = value;
        totalItems++;

        std::cout << "ADD\tCollection: [";

        for( int i = 0; i < totalItems; i++ ){
            std::cout << numbers[i] << ", ";

        };

        std::cout << "]\n";

    };

    void remove( T value ){

        // Check if the numbers collection is empty
        // If true, return and sent a message to terminal
        if( numbers.size() == 0 ){

        std::cout << "===>\tNumbers is empty!" << std::endl;
        return;

        };

        bool inCollection = false;

        // Check if value excist in collection
        // If false, return and sent a message to terminal
        for( auto n : numbers ){

            if( value == n ){
                inCollection = true;
                break;   
            }

        };

        if( !inCollection ){

            std::cout << "===>\tValue isn't in numbers collection" << std::endl;
            return;

        };

        // Create a new array with with items within the numbers array
        // Skip the position that contains the given value and
        // Shift the next item one place back
        std::array<T, M> newArray;
        int pos = 0;

        for( int i = 0; i < totalItems; i++ ){
            
            if( value != numbers[i] ){
                newArray[i - pos] = numbers[i];
            } else {
                pos++;
            }

        };

        totalItems--;

        // Override the numbers array with the new array
        numbers = newArray;

        std::cout << "RMV\tCollection: [";

        for( int i = 0; i < totalItems; i++ ){
            std::cout << numbers[i] << ", ";

        };

        std::cout << "]\n";

    };


    bool contains( T value ){

        bool inCollection = false;

        // If the collection is empty, return false
        if( totalItems == 0 ) return false;

        // Check if value excist in collection
        // If false, break and stop looking
        for( auto n : numbers ){

            if( value == n ){
                inCollection = true;
                break;   
            }

        };

        std::cout << "CON\tCollection: [";

        for( int i = 0; i < totalItems; i++ ){
            std::cout << numbers[i] << ", ";

        };

        std::cout << "]\n";

        return inCollection;

    };
    
    friend std::ostream & operator<<( std::ostream & lhs, const collection & rhs ){

        // If the collection is empty, return false
        if( rhs.totalItems == 0 ){
            lhs << "[]";
            return lhs;
        };

        // Start making the ostream element
        lhs << '[';

        // Set every element of the array in the ostream element
        // Devided with decimal point, except the last element
        for( int i = 0; i < rhs.totalItems - 1; i++ ){
            lhs << rhs.numbers[i];
            lhs << ',';
        }

        // Set the last element of the array in the ostream element
        lhs << rhs.numbers[ rhs.totalItems - 1 ];

        lhs << ']';

        return lhs;
    }

    T max(){

        // If the collection is empty, return false
        if( totalItems == 0 ) return false;

        // Set the first element of the collection as Max
        T getMax = numbers[0];

        // Check if an element is greater then the current found Max
        // If the element is greater, set element to new Max
        for( int i = 0; i < totalItems; i++ ){
            
            if( getMax < numbers[i] ){
                getMax = numbers[i];      
            };

        };

        std::cout << "MAX\t" << getMax << std::endl;

        return getMax;

    };

};
