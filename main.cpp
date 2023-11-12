//
// Created by alejandro on 21/10/2023.
//

//#include <iostream>
//#include "Lists/List.h"
#include "Lists/ForwardList.h"
#include "Lists/ForwardList.cpp"

int main(){

    ForwardList<int> lista;
    lista.push_front(1);
    lista.push_front(2);
    lista.push_front(3);
    lista.push_front(4);
    //lista.push_front(5);
    //lista.push_front(6);
    //lista.push_front(7);
    //lista.push_front(8);
    //std::cout << lista.size() << std::endl;
    //lista.push_back(111);
    //std::cout << lista.size() << std::endl;
    lista.pop_back();
    //lista.pop_front();
    //lista.pop_back();
    //lista.pop_back();
    lista.insert(11, 2);
    //lista.remove(7);
    //lista.reverse();
    std::cout << lista.name() << std::endl;
    std::cout << lista[3] << std::endl;

    return 0;
}