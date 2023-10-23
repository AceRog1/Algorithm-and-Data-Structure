//
// Created by alejandro on 21/10/2023.
//

#include "Stack.h"
#include <iostream>

using namespace std;


template<typename T>
Stack<T>::Stack(){
    length = 0;
    last = nullptr;
}


template<typename T>
T Stack<T>::top(){
    if (empty())
        throw runtime_error("No elements in the stack");
    return last->data;
}

template<typename T>
int Stack<T>::size(){
    return length;
}

template<typename T>
void Stack<T>::push(T value){
    Node* newNode = new Node(value);
    if(empty()){
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
    if(empty()){
        throw runtime_error("No elements in the stack");
    } else {
        Node* popNode = last;
        last = popNode->next;
        popNode->killself();
        length--;
    }
}

template<typename T>
void Stack<T>::clear(){
    for(int i = 0; i < length; i++)
        pop();
}

template<typename T>
void Stack<T>::showStack(){
    Node* temp = last;
    for(int i = 0; i < length; i++){
        cout << "Position " << length-i << " : " << temp->data << endl;
        temp = temp->next;
    }
}

template<typename T>
bool Stack<T>::empty(){
    if (length == 0){
        return true;
    } else { return false; }
}

template<typename T>
Stack<T>::~Stack(){
    clear();
}
