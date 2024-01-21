//
// Created by alejandro on 21/10/2023.
//

#include <iostream>
#include "Lists/CircularList.h"
#include "Lists/CircularList.cpp"

int main(){

    CircularList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    std::cout << list.name() << std::endl;
    std::cout << list.size() << std::endl;

    return 0;
}