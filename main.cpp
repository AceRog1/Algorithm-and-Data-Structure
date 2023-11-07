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
    //std::cout << lista.size() << std::endl;
    //lista.push_back(111);
    //std::cout << lista.size() << std::endl;
    lista.pop_back();
    lista.pop_back();
    lista.pop_back();
    //lista.pop_back();
    std::cout << lista.name() << std::endl;

    return 0;
}