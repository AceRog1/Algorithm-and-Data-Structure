//
// Created by alejandro on 21/10/2023.
//

#include "ForwardList.h"

template<typename T>
ForwardList<T>::ForwardList(){
    length = 0;
    head = nullptr;
}

template<typename T>
T ForwardList<T>::front(){
    return head->data;
}

template<typename T>
T ForwardList<T>::back(){
    Node *temp = head;
    for(int i = 0; i < length-1; i++){
        temp = temp->next;
    }
    return temp->data;
}

template<typename T>
void ForwardList<T>::push_front(T value){
    Node* newNode = new Node(value);

}