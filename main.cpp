//
// Created by acerog on 21/10/2023.
//

#include <iostream>
#include <string>
#include <utility>
#include "HashTable/HashChaining.h"
#include "HashTable/HashChaining.cpp"

int main(){

    HashChaining<int, std::string> hash;
    hash.insert(10, "hello");
    hash.insert(23, "the");
    hash.insert(36, "world");
    hash.insert(2, "hello");
    hash.insert(3, "the");
    std::cout << hash.max_size() << std::endl;
    hash.insert(6, "world");
    hash.insert(60, "hello");
    std::cout << hash.max_size() << std::endl;
    hash.insert(234, "the");
    std::cout << hash.max_size() << std::endl;
    hash.insert(368, "world");
    std::cout << hash.max_size() << std::endl;


//    pair<int, std::string> par = hash.search(23);
//
//    std::cout << par.first << std::endl;
//    std::cout << par.second << std::endl;
//
//    std::cout << std::endl;
//
//    hash.insert(49, "c fue");
//
//    pair<int, std::string> par2 = hash.search(49);
//
//    std::cout << par2.first << std::endl;
//    std::cout << par2.second << std::endl;
//
//    std::cout << std::endl;
//
//    pair<int, std::string> par3 = hash.extract(23);
//
//    std::cout << par3.first << std::endl;
//    std::cout << par3.second << std::endl;
//
//    std::cout << std::endl;
//
//    pair<int, std::string> par4 = hash.search(49);
//
//    std::cout << par4.first << std::endl;
//    std::cout << par4.second << std::endl;
//
//    std::cout << std::endl;




    return 0;
}