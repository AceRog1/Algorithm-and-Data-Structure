//
// Created by alejandro on 21/10/2023.
//

#include <iostream>
#include "StackAndQueue/Stack.h"
#include "StackAndQueue/Stack.cpp"
//#include "StackAndQueue/Queue.h"
//#include "StackAndQueue/Queue.cpp"
//#include "CircularArray/CircularArray.h"

int main(){

    //int i = 2;
    Stack<int> stack;
    stack.push(3); //1
    stack.push(4); //2
    stack.push(5); //3
    stack.push(6); //4
    stack.push(7); //5
    stack.push(8); //6
    stack.pop(); //5
    stack.pop(); //4
    stack.pop(); //3
    stack.pop(); //2
    stack.pop(); //1
    //stack.pop(); //0
    //stack.pop();
    std::cout << "TOP: " << stack.top() << std::endl;
    std::cout << "SIZE: " << stack.size() << std::endl;
    stack.showStack();

    return 0;
}