//
// Created by alejandro on 21/10/2023.
//

#include <string>
#include <sstream>
#include <type_traits>
#include "ForwardList.h"

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
    for(int i = 0; i < length-1; i++)
        temp = temp->next;
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
        for(int i = 1; i < size(); i++)
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
        throw runtime_error("No elements in the list");
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
        lastNode->next = nullptr;
        T value = popNode->data;
        popNode->killself();
        length--;
        return value;
    }
}

template<typename T>
bool ForwardList<T>::insert(T value, int pos){
    if (pos <= size()+1){
        if (pos == 1){
            push_back(value);
            return true;
        } else if (pos == length+1){
            push_front(value);
            return true;
        } else {
            Node* newNode = new Node(value);
            Node* temp = head;
            int realPos = length - pos;
            for (int i = 0; i < realPos; i++)
                temp = temp->next;
            newNode->next = temp->next;
            temp->next = newNode;
            length++;
            return true;
        }
    } else if (pos > size()+1){
        return false;
    }
    return false;
}

template<typename T>
bool ForwardList<T>::remove(int pos){
    if (pos <= size()){
        if (pos == 1){
            pop_back();
            return true;
        } else if (pos == length){
            pop_front();
            return true;
        } else {
            Node* prePopNode = head;
            int realPos = length - pos;
            for (int i = 0; i < realPos-1; i++)
                prePopNode = prePopNode->next;
            Node* popNode = prePopNode->next;
            prePopNode->next = popNode->next;
            popNode->killself();
            length--;
            return true;
        }
    } else if (pos > size()){
        return false;
    }
}

template<typename T>
T& ForwardList<T>::operator[](int pos) {
    if (pos < length+1 && 0 < pos) {
        if (pos == length) {
            return head->data;
        } else if (pos == 1) {
            Node *temp = head;
            for (int i = 0; i < length - 1; i++)
                temp = temp->next;
            return temp->data;
        } else {
            Node *selectNode = head;
            int realPos = length - pos;
            for (int i = 0; i <= realPos - 1; i++)
                selectNode = selectNode->next;
            return selectNode->data;
        }
    } else {
        if (pos > size()){
            throw runtime_error("Invalid Position");
        } else if (pos == 0){
            throw runtime_error("No elements in the list");
        }
        throw runtime_error("ERROR");
    }
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
    for(int i = 0; i < size(); i++)
        pop_front();
}

template<typename T>
void ForwardList<T>::sort(){
    if (is_same<T, int>::value || is_same<T, double>::value || is_same<T, float>::value){
        auto sortList = new ForwardList<T>();
        mergeSort(this, sortList, 0, length-1);
        Node* sortedNode = sortList->head;
        Node* originalNode = head;

        while (sortedNode != nullptr && originalNode != nullptr) {
            originalNode->data = sortedNode->data;
            sortedNode = sortedNode->next;
            originalNode = originalNode->next;
        }

        delete sortList;
    } else {
        throw runtime_error("The elements in the list are not numbers");
    }
}

template<typename T>
bool ForwardList<T>::is_sorted(){
    if (is_same<T, int>::value || is_same<T, double>::value || is_same<T, float>::value){
        Node* temp1 = head;
        Node* temp2 = head->next;

        while(temp2 != nullptr){
            if (temp1->data > temp2->data)
                return false;
            temp1 = temp2;
            temp2 = temp2->next;
        }
        return true;
    } else {
        throw runtime_error("The elements in the list are not numbers");
    }
}

template<typename T>
void ForwardList<T>::reverse(){
    if(size() >= 3){
        Node* a = head;
        Node* b = head->next;
        Node* c = head->next->next;
        while (c->next != nullptr){
            if (a == head)
                a->next = nullptr;
            b->next = a;
            a = b;
            b = c;
            c = c->next;
        }
        b->next = a;
        c->next = b;
        if(size() == 3)
            a->next = nullptr;
        head = c;
    } else if(size() == 2) {
        Node* temp = head->next;
        temp->next = head;
        head->next = nullptr;
        head = temp;
    } else if(size() == 1){
        head->next = nullptr;
    } else {
        throw runtime_error("No elements in the list");
    }
}

template<typename T>
string ForwardList<T>::name(){
    if (is_empty()){
        throw runtime_error("No elements in the list");
    } else {
        stringstream ss;
        Node* temp = head;
        for(int i = 0; i < size(); i++){
            if (i+1 == size())
                ss << temp->data;
            else
                ss << temp->data << ", ";
            temp = temp->next;
        }
        return ss.str();
    }
}

template<typename T>
ForwardList<T>::~ForwardList(){
    clear();
}
