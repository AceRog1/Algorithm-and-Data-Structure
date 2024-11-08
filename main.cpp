//
// Created by alejandro on 21/10/2023.
//

#include <iostream>
#include <string>
#include "HashTable/HashOpenAddressing.h"
#include "HashTable/HashOpenAddressing.cpp"

int main(){


    HashOpenAddressing<int, std::string> hash;
    hash.insert(4, "Hello");
    hash.insert(8, "Hello");
    hash.insert(1, "Hello");


    hash.remove(4);


    return 0;
}