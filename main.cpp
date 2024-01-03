//
// Created by alejandro on 21/10/2023.
//


//#include "Lists/List.h"
#include "Lists/DoubleList.h"
#include "Lists/DoubleList.cpp"

int main(){

    DoubleList<int> list;
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.insert(6, 1);
    list.insert(0, 7);
    list.insert(99, 3);

    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;
    std::cout << "Size: " << list.size() << std::endl;

    std::cout << list.name() << std::endl;

    return 0;
}