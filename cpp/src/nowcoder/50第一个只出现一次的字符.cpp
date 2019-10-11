#include <iostream>

using namespace std;

//50
char first(const char* str){
    if(str == nullptr){
        return '\0';
    }

    const int tableSize= 256;
    unsigned int hashTable[tableSize] = {0};

    const char* pointer = str;

    while (*pointer != '\0')
    {
        hashTable[*pointer]++;
        pointer++;
    }
    
    pointer=str;
    while (*pointer != '\0')
    {
        if(hashTable[*pointer] == 1){
            return *pointer;
        }

        pointer++;
    }
    

    return '\0';
} 