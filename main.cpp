//
// Created by alejandro on 21/10/2023.
//

#include <iostream>
#include "Lists/CircularList.h"
#include "Lists/CircularList.cpp"

int main(){

    CircularList<int> list;

    list.push_back(0);
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.push_back(9);

    std::cout << list.print() << std::endl;

    CircularListIterator<int> iter;

    for (iter = list.beginFront(); iter != list.end(); ++iter)
        std::cout << *iter << " -> ";
    std::cout << "\n";

    list.sort();

    for (iter = list.beginFront(); iter != list.end(); ++iter)
        std::cout << *iter << " -> ";
    std::cout << "\n";

    return 0;
}