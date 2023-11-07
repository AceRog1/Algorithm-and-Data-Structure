//
// Created by alejandro on 21/10/2023.
//

#include "ForwardList.h"
#include <string>

using namespace std;

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
    if (size() == 0){
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }
    length++;
}

template<typename T>
void ForwardList<T>::push_back(T value){
    Node* newNode = new Node(value);
    if (size() == 0){
        head = newNode;
    } else {
        Node* temp = head;
        for(int i = length; i < size(); i++)
            temp = temp->next;
        temp->next = newNode;
    }
    length++;
}

template<typename T>
T ForwardList<T>::pop_front(){
    if (size() == 0){
        throw runtime_error("No elements in the list");
    } else {
        Node* popNode = head;
        head = popNode->next;
        T value = popNode->data;
        popNode->killself();
        length--;
        return value;
    }
}

template<typename T>
T ForwardList<T>::pop_back(){
    if (size() == 0){
        throw runtime_error("No elemntes in the list");
    } else if (size() == 1){
        Node* popNode = head;
        T value = popNode->data;
        popNode->killself();
        length--;
        return value;
    } else {
        Node* popNode = head;
        for(int i = 0; i < size()-1; i++)
            popNode = popNode->next;
        Node* lastNode = popNode;
        popNode->next;
        lastNode->next = nullptr;
        T value = popNode->data;
        popNode->killself();
        length--;
        return value;
    }
}

template<typename T>
bool ForwardList<T>::insert(T, int){
    //TODO
}

template<typename T>
bool ForwardList<T>::remove(int){
    //TODO
}

template<typename T>
T& ForwardList<T>::operator[](int){
    //TODO
}

template<typename T>
bool ForwardList<T>::is_empty(){
    if(size() == 0)
        return true;
    else
        return false;
}

template<typename T>
int ForwardList<T>::size(){
    return length;
}

template<typename T>
void ForwardList<T>::clear(){
    for(int i = 0; i < size(); i++){
        pop_front();
    }
}

template<typename T>
void ForwardList<T>::sort(){
    //TODO
}

template<typename T>
bool ForwardList<T>::is_sorted(){
    //TODO
}

template<typename T>
void ForwardList<T>::reverse(){
    //TODO
}

template<typename T>
string ForwardList<T>::name(){
    if (is_empty()){
        throw runtime_error("No elements in the list");
    } else {
        Node* temp = head;
        string nameString;
        for(int i = 0; i < size(); i++){
            string part = to_string(temp->data);
            if (i+1 == size()){
                nameString += part;
            } else {
                nameString += part + ", ";
            }
            temp = temp->next;
        }
        return nameString;
    }
}

template<typename T>
ForwardList<T>::~ForwardList(){
    clear();
}
