//
// Created by alejandro on 21/10/2023.
//

#include <iostream>
//#include "StackAndQueue/Stack.h"
#include "StackAndQueue/Queue.h"
#include "StackAndQueue/Queue.cpp"

int main(){

    Queue<int> queue;
    queue.push(3);
    queue.push(7);
    queue.push(9);
    //queue.pop();
    //queue.pop();
    //queue.pop();
    //queue.pop();
    cout << queue.front() << endl;
    std::cout << queue.back() << std::endl;
    std::cout << queue.size() << std::endl;

    return 0;
}