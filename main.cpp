//
// Created by alejandro on 21/10/2023.
//

#include <iostream>
#include "CircularArray/CircularArray.h"
#include "CircularArray/CircularArray.cpp"

int main() {

    CircularArray<int> arr;
    /*arr.push_back(0);
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.push_back(5);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(8);
    arr.push_back(9);*/

    arr.push_front(0);
    arr.push_back(1);
    arr.push_front(2);
    arr.push_back(3);
    arr.push_front(4);
    arr.push_back(5);
    arr.push_front(6);
    arr.push_back(7);
    arr.push_front(8);
    arr.push_back(9);

    std::cout << arr.to_string() << std::endl;

    arr.insert(99, -1);

    std::cout << arr.to_string() << std::endl;


    return 0;
}