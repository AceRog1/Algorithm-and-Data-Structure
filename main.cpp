//
// Created by alejandro on 21/10/2023.
//


//#include "Lists/List.h"
#include "Lists/DoubleList.h"
#include "Lists/DoubleList.cpp"

int main(){

    DoubleList<int> list;

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(6);
    list.push_back(7);
    list.push_back(8);

    std::cout << list.print() << std::endl;

    DoubleList<int>::iterator iter;

    for(iter = list.beginFront(); iter != list.end(); ++iter)
        std::cout << *iter << " - ";
    std::cout << "\n";

    list.sort();

    for(iter = list.beginFront(); iter != list.end(); ++iter)
        std::cout << *iter << " - ";
    std::cout << "\n";

    /*
    std::cout << "Front: " << list.front() << std::endl;
    std::cout << "Back: " << list.back() << std::endl;
    std::cout << "Size: " << list.size() << std::endl;

    std::cout << list.name() << std::endl;

    std::cout << std::endl;
    */


    return 0;
}