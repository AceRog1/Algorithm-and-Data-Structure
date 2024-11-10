//
// Created by alejandro on 21/10/2023.
//

#include <iostream>
#include <string>
#include "HashTable/HashOpenAddressing.h"
#include "HashTable/HashOpenAddressing.cpp"

int main(){


    HashOpenAddressing<int, std::string> hash;
    hash.insert(1, "Alejandro");
    hash.insert(11, "Nahia");
    hash.insert(26, "Danna");
    hash.insert(29, "AlejandroR");
    hash.insert(100, "NahiaE");
    hash.insert(15, "DannaM");
    hash.insert(69, "AlejandroRO");
    hash.insert(9, "NahiaES");
    hash.insert(2611, "DannaME");
    hash.insert(7, "AlejandroROJ");
    hash.insert(110, "NahiaESC");
    hash.insert(66, "DannaMEN");
    hash.insert(12, "AlejandroROJA");
    hash.insert(16, "NahiaESCA");
    hash.insert(20, "DannaMEMD");
    hash.insert(30, "AlejandroROJAS");
    hash.insert(5, "NahiaESCAL");
    hash.insert(8, "DannaMENDE");

    std::pair<int, std::string> element = hash.extraxt(8);

    std::cout << element.first << " " << element.second;


    return 0;
}