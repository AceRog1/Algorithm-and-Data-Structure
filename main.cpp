//
// Created by alejandro on 21/10/2023.
//


//#include "Lists/List.h"
#include "Lists/DoubleList.h"
#include "Lists/DoubleList.cpp"

int main(){

    DoubleList<int> list;
    list.push_front(1);
    std::cout << list.pop_front() << std::endl;
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;
    std::cout << list.name() << std::endl;
    list.reverse();
    std::cout << list.name() << std::endl;

    return 0;
}