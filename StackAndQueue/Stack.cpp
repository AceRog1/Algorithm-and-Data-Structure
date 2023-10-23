//
// Created by alejandro on 21/10/2023.
//

#include "Stack.h"
#include <iostream>

using namespace std;

template<typename T>
Stack<T>::Stack(){
    length = 0;
    this->last = nullptr;
}

template<typename T>
T Stack<T>::top(){
    return last->data;
}

template<typename T>
int Stack<T>::size(){
    return length;
}

template<typename T>
void Stack<T>::push(T value){
    Node* newNode = new Node(value);
    if(length == 0){
        newNode->next = nullptr;
        last = newNode;
    } else {
        newNode->next = last;
        last = newNode;
    }
    length++;
}

template<typename T>
void Stack<T>::pop(){
    if(length == 0){
        cout << "No elements in the stack" << endl;
    } else {
        Node* popNode = last;
        last = popNode->next;
        popNode->killself();
        length--;
    }
}

template<typename T>
void Stack<T>::clear(){
    for(int i = 0; i < length; i++){
        pop();
    }
}

template<typename T>
Stack<T>::~Stack(){
    clear();
}