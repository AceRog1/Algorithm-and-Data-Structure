//
// Created by alejandro on 21/10/2023.
//

#include <sstream>
#include <type_traits>
#include <algorithm>
#include <vector>
#include "DoubleList.h"

using namespace std;

template<typename T>
DoubleList<T>::DoubleList(){
    length = 0;
    head = nullptr;
    tail = nullptr;
}

template<typename T>
T DoubleList<T>::front(){
    if (is_empty()){
        throw runtime_error("No elements in the list");
    } else {
        return head->data;
    }
}

template<typename T>
T DoubleList<T>::back(){
    if (is_empty()){
        throw runtime_error("No elements in the list");
    } else {
        return tail->data;
    }
}

template<typename T>
void DoubleList<T>::push_front(T value){
    Node* newNode = new Node(value);
    if (size() == 0){
        tail = newNode;
        head = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    length++;
}

template<typename T>
void DoubleList<T>::push_back(T value){
    Node* newNode = new Node(value);
    if (size() == 0){
        tail = newNode;
        head = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    length++;
}

template<typename T>
T DoubleList<T>::pop_front(){
    if (size() >= 2){
        Node* popNode = head;
        T value = popNode->data;
        head = head->next;
        head->prev = nullptr;
        popNode->killself();
        length--;
        return value;
    } else if (size() == 1){
        Node* popNode = head;
        T value = popNode->data;
        head = nullptr;
        tail = nullptr;
        popNode->killself();
        length--;
        return value;
    } else {
        throw runtime_error("No elements in the list");
    }
}

template<typename T>
T DoubleList<T>::pop_back(){
    Node* popNode = tail;
    tail = tail->prev;
    tail->next = nullptr;
    T value = popNode->data;
    popNode->killself();
    length--;
    return value;
}

template<typename T>
bool DoubleList<T>::insert(T value, int pos){
    if (pos <= size()+1){
        if (pos == size()+1){
            push_back(value);
        } else if (pos == 1) {
            push_front(value);
        } else {
            Node* newNode = new Node(value);
            int index = size()/2;
            if (pos <= index){
                Node* temp = head;
                for (int i = 1; i < pos-1; i++)
                    temp = temp->next;
                newNode->next = temp->next;
                newNode->prev = temp;
                temp->next->prev = newNode;
                temp->next = newNode;
            } else if (pos > index) {
                Node* temp = tail;
                int tailPos = size() - pos;
                for (int i = 1; i < tailPos+1; i++)
                    temp = temp->prev;
                newNode->prev = temp->prev;
                newNode->next = temp;
                temp->prev->next = newNode;
                temp->prev = newNode;
            }
            length++;
        }
        return true;
    } else if (pos > size()+1){
        return false;
    }
}

template<typename T>
bool DoubleList<T>::remove(int pos){
    if (pos <= size()){
        if (pos == size()){
            pop_back();
        } else if (pos == 1) {
            pop_front();
        } else {
            Node* popNode;
            int index = size()/2;
            if (pos <= index){
                Node* temp = head;
                for (int i = 1; i < pos-1; i++)
                    temp = temp->next;
                popNode = temp->next;
                temp->next = popNode->next;
                popNode->next->prev = temp;
                popNode->killself();
            } else if (pos > index) {
                Node* temp = tail;
                int tailPos = size() - pos;
                for (int i = 1; i < tailPos; i++)
                    temp = temp->prev;
                popNode = temp->prev;
                temp->prev = popNode->prev;
                popNode->prev->next = temp;
                popNode->killself();
            }
            length--;
        }
        return true;
    } else if (pos > size()){
        return false;
    }
}

template<typename T>
T& DoubleList<T>::operator[](int pos){
    if (pos <= size()){
        if (pos == size()){
            return tail->data;
        } else if (pos == 1) {
            return head->data;
        } else {
            Node* showNode;
            int index = size()/2;
            if (pos <= index){
                Node* temp = head;
                for (int i = 1; i < pos-1; i++)
                    temp = temp->next;
                showNode = temp->next;
                return showNode->data;
            } else if (pos > index) {
                Node* temp = tail;
                int tailPos = size() - pos;
                for (int i = 1; i < tailPos; i++)
                    temp = temp->prev;
                showNode = temp->prev;
                return showNode->data;
            }
        }
    } else if (is_empty()){
        throw runtime_error("No elements in the list");
    } else if (pos > size()){
        throw runtime_error("Invalid position");
    }
}

template<typename T>
bool DoubleList<T>::is_empty(){
    if (size() == 0){
        return true;
    } else {
        return false;
    }
}

template<typename T>
int DoubleList<T>::size(){
    return length;
}

template<typename T>
void DoubleList<T>::clear(){
    int l = length;
    for (int i = 0; i < l; i++)
        pop_front();
}

template<typename T>
void DoubleList<T>::sort(){
    if (is_same<T, int>::value || is_same<T, double>::value || is_same<T, float>::value){
        if (is_sorted() || is_empty())
            return;
        int t = length;
        vector<T> arr;
        Node* temp = head;
        size_t i = 0;
        while (temp != nullptr){
            arr.push_back(temp->data);
            temp = temp->next;
            i++;
        }
        this->clear();
        std::sort(arr.begin(), arr.end());
        for (int j = 0; j < t; j++)
            this->push_front(arr[t-j-1]);
    } else {
        throw runtime_error("The elements in the list are not numbers");
    }
}

template<typename T>
bool DoubleList<T>::is_sorted(){
    if (is_same<T, int>::value || is_same<T, double>::value || is_same<T, float>::value){
        Node* temp = head;
        while (temp != nullptr){
            if (temp->prev != nullptr && temp->prev->data > temp->data)
                return false;
            if (temp->next != nullptr && temp->next->data < temp->data)
                return false;
            temp = temp->next;
        }
        return true;
    } else {
        throw runtime_error("The elements in the list are not numbers");
    }
}

template<typename T>
void DoubleList<T>::reverse(){
    if (size() >= 3){
        Node* temp = head;
        Node* newTail = head;
        int count = 0;
        Node* a = temp->next;
        Node* b = temp->prev;
        do {
            temp->next = b;
            temp->prev = a;
            b = temp;
            temp = a;
            if (a != nullptr)
                a = a->next;
            count++;
        } while (temp != nullptr);
        head = b;
        tail = newTail;
    } else if (size() == 2){
        Node* newTail = head;
        head = tail;
        tail = newTail;
        head->next = tail;
        head->prev = tail->next = nullptr;
        tail->prev = head;
    } else if (size() == 1){
        head->next = nullptr;
        head->prev = nullptr;
        tail->next = nullptr;
        tail->prev = nullptr;
    } else {
        throw runtime_error("No elements in the list");
    }
}

template<typename T>
string DoubleList<T>::print(){
    stringstream ss;
    Node* temp = head;
    do {
        if (temp == head)
            ss << temp->data;
        else
            ss << ", " << temp->data;
        temp = temp->next;
    } while (temp != nullptr);
    return ss.str();
}

template<typename T>
DoubleList<T>::~DoubleList(){
    clear();
}
