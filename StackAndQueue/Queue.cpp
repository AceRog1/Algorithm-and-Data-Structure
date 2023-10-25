//
// Created by alejandro on 21/10/2023.
//

#include "Queue.h"
#include <iostream>


using namespace std;

template<typename T>
Queue<T>::Queue(){
    length = 0;
    head = nullptr;
    tale = nullptr;
}

template<typename T>
int Queue<T>::size(){
    return length;
}

template<typename T>
bool Queue<T>::empty(){
    if (length == 0)
        return true;
    else
        return false;
}

template<typename T>
T Queue<T>::front(){
    if (length == 0){
        throw runtime_error("No elements in the queue");
    } else {
        return head->data;
    }
}

template<typename T>
T Queue<T>::back(){
    if (length == 0){
        throw runtime_error("No elements in the queue");
    } else {
        return tale->data;
    }
}

template<typename T>
void Queue<T>::push(T value){
    Node* newNode = new Node(value);
    if (empty()){
        head = newNode;
        tale = newNode;
    } else{
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

template<typename T>
void Queue<T>::pop(){
    if (empty()){
        throw runtime_error("No elements in the queue");
    } else if (length == 1){
        Node* popNode = tale;
        tale = nullptr;
        head = nullptr;
        popNode->killSelf();
        length--;
    } else{
        Node* popNode = tale;
        tale = popNode->prev;
        tale->next = nullptr;
        popNode->killSelf();
        length--;
    }
}

/*
template<typename T>
void Queue<T>::printQueue(){
}
*/
template<typename T>
void Queue<T>::clear(){
    if (empty()){
        NULL;
    } else {
        for(int i = 0; i < length; i++){
            pop();
        }
    }
}

template<typename T>
Queue<T>::~Queue(){
    clear();
}

