//
// Created by alejandro on 21/10/2023.
//

#include <iostream>
#include <string>
//#include "Lists/List.h"
#include "Lists/ForwardList.h"
#include "Lists/ForwardList.cpp"



int main(){
    ForwardList<int> lista;
    lista.push_front(8);
    lista.push_front(7);
    lista.push_front(6);
    lista.push_front(5);
    lista.push_front(4);
    lista.push_front(3);
    lista.push_front(2);
    lista.push_front(1);

    std::cout << lista.print() << std::endl;

    ForwardList<int>::iterator iter;

    for (iter = lista.begin(); iter != lista.end(); ++iter){
        std::cout << *iter << " -> ";
    }
    std::cout << "nullptr\n";

    lista.sort();

    for (iter = lista.begin(); iter != lista.end(); ++iter){
        std::cout << *iter << " -> ";
    }
    std::cout << "nullptr\n";

    return 0;
}