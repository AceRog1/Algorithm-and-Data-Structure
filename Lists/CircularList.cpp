//
// Created by alejandro on 21/10/2023.
//

#include <sstream>
#include <vector>
#include <algorithm>
#include <type_traits>
#include "CircularList.h"

using namespace std;

template<typename T>
CircularList<T>::CircularList() {
    length = 0;
    centinel.data = T();
    cptr = &centinel;
    cptr->next = nullptr;
    cptr->prev = nullptr;
}

template<typename T>
T CircularList<T>::front() {
    return centinel.next->data;
}

template<typename T>
T CircularList<T>::back() {
    return centinel.prev->data;
}

template<typename T>
void CircularList<T>::push_front(T value) {
    Node *newNode = new Node(value);
    if (length == 0){
        newNode->next = cptr;
        newNode->prev = cptr;
        cptr->next = newNode;
        cptr->prev = newNode;
    } else {
        newNode->next = cptr->next;
        newNode->prev = cptr;
        cptr->next->prev = newNode;
        cptr->next = newNode;
    }
    length++;
}

template<typename T>
void CircularList<T>::push_back(T value) {
    Node *newNode = new Node(value);
    if (length == 0){
        newNode->next = cptr;
        newNode->prev = cptr;
        cptr->next = newNode;
        cptr->prev = newNode;
    } else {
        newNode->next = cptr;
        newNode->prev = cptr->prev;
        cptr->prev->next = newNode;
        cptr->prev = newNode;
    }
    length++;
}

template<typename T>
T CircularList<T>::pop_front() {
    if (length == 0) {
        throw runtime_error("No elements in the list");
    } else if (length == 1) {
        Node *popNode = cptr->next;
        T val = popNode->data;
        cptr->next = cptr;
        cptr->prev = cptr;
        popNode->killself();
        length--;
        return val;
    } else {
        Node *popNode = cptr->next;
        T val = popNode->data;
        cptr->next = popNode->next;
        popNode->next->prev = cptr;
        popNode->killself();
        length--;
        return val;
    }
}

template<typename T>
T CircularList<T>::pop_back() {
    if (length == 0) {
        throw runtime_error("No elements in the list");
    } else if (length == 1) {
        Node *popNode = cptr->prev;
        T val = popNode->data;
        cptr->next = cptr;
        cptr->prev = cptr;
        popNode->killself();
        length--;
        return val;
    } else {
        Node *popNode = cptr->prev;
        T val = popNode->data;
        cptr->prev = popNode->prev;
        popNode->prev->next = cptr;
        popNode->killself();
        length--;
        return val;
    }
}

template<typename T>
bool CircularList<T>::insert(T value, int pos) {
    if (is_empty() == false) {
        if (pos < 0 || pos > size()){
            return false;
        } else if (pos == 0){
            push_front(value);
            return true;
        } else if (pos == size()){
            push_back(value);
            return true;
        } else {
            Node *newNode = new Node(value);
            Node *temp = cptr->next;
            for (int i = 0; i < pos-1; i++)
                temp = temp->next;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            length++;
            return true;
        }
    } else {
        return false;
    }
}

template<typename T>
bool CircularList<T>::remove(int pos) {
    if (is_empty() == false) {
        if (pos < 0 || pos >= size()){
            return false;
        } else if (pos == 0){
            pop_front();
            return true;
        } else if (pos == size()-1){
            pop_back();
            return true;
        } else {
            Node *popNode = cptr->next;
            for (int i = 0; i < pos; i++)
                popNode = popNode->next;
            popNode->next->prev = popNode->prev;
            popNode->prev->next = popNode->next;
            popNode->killself();
            length--;
            return true;
        }
    } else {
        return false;
    }
}

template<typename T>
T& CircularList<T>::operator[](int pos) {
    if (is_empty() == false){
        if (pos < length && pos >= 0){
            if (pos == 0){
                return cptr->next->data;
            } else if (pos == length-1){
                return cptr->prev->data;
            } else {
                Node *temp = cptr->next;
                for (int i = 0; i < pos; i++)
                    temp = temp->next;
                return temp->data;
            }
        } else {
            throw runtime_error("Invalid Position");
        }
    } else {
        throw runtime_error("No elements in the list");
    }
}

template<typename T>
bool CircularList<T>::is_empty() {
    if (length == 0)
        return true;
    else
        return false;
}

template<typename T>
int CircularList<T>::size() {
    return length;
}

template<typename T>
void CircularList<T>::clear() {
    while(cptr->next != cptr)
        pop_front();
}

template<typename T>
void CircularList<T>::sort() {
    if (is_same<T, int>::value || is_same<T, double>::value || is_same<T, float>::value){
        if (is_sorted() || is_empty())
            return;
        int t = length;
        vector<T> arr;
        Node* temp = cptr->next;
        size_t i = 0;
        while (temp != cptr){
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
bool CircularList<T>::is_sorted() {
    if (is_same<T, int>::value || is_same<T, double>::value || is_same<T, float>::value){
        Node* temp = cptr->next;
        while (temp != cptr){
            if (temp->prev != cptr && temp->prev->data > temp->data)
                return false;
            if (temp->next != cptr && temp->next->data < temp->data)
                return false;
            temp = temp->next;
        }
        return true;
    } else {
        throw runtime_error("The elements in the list are not numbers");
    }
}

template<typename T>
void CircularList<T>::reverse() {
    if (size() == 1){
        // In this circularList, if there is just one element in the list, there is nothing to change.
    } else if (is_empty() == false){
        Node *tempA = cptr->next;
        Node *tempB = cptr->next->next;
        do {
            Node *temp = tempA->prev;
            tempA->next = tempA->prev;
            tempA->prev = temp;
            tempA = tempB;
            tempB = tempB->next;
        } while (tempB->prev != cptr);
        Node *temp = cptr->next;
        cptr->next = cptr->prev;
        cptr->prev = temp;
    } else {
         throw runtime_error("No elements in the List");
    }
}

template<typename T>
string CircularList<T>::print() {
    stringstream ss;
    Node* temp = cptr->next;
    while(temp->next != cptr){
        ss << temp->data << " , ";
        temp = temp->next;
    }
    ss << temp->data;
    return ss.str();
}

template<typename T>
CircularList<T>::~CircularList() {
    clear();
}