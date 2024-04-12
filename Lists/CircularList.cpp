//
// Created by alejandro on 21/10/2023.
//

#include "CircularList.h"

using namespace std;

template<typename T>
CircularList<T>::CircularList() {
    head = nullptr;
    tail = nullptr;
    length = 0;
}

template<typename T>
T CircularList<T>::front() {
    return head->data;
}

template<typename T>
T CircularList<T>::back() {
    return tail->data;
}

template<typename T>
void CircularList<T>::push_front(T value) {
    Node *newNode = new Node(value);
    if (length == 0){
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = tail;
        head = newNode;
    }
    length++;
}

template<typename T>
void CircularList<T>::push_back(T value) {
    Node *newNode = new Node(value);
    if (length == 0){
        newNode->next = newNode;
        newNode->prev = newNode;
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = tail;
        tail = newNode;
    }
    length++;
}

template<typename T>
T CircularList<T>::pop_front() {
    if (length == 0) {
        throw runtime_error("No elements in the list");
    } else if (length == 1) {
        Node *popNode = head;
        T num = popNode->data;
        head = nullptr;
        tail = nullptr;
        popNode->killself();
        length--;
        return num;
    } else {
        Node *popNode = head;
        T num = popNode->data;
        head = popNode->next;
        head->prev = tail;
        tail->next = head;
        popNode->killself();
        length--;
        return num;
    }
}

template<typename T>
T CircularList<T>::pop_back() {
    if (length == 0) {
        throw runtime_error("No elements in the list");
    } else if (length == 1) {
        Node *popNode = tail;
        T num = popNode->data;
        head = nullptr;
        tail = nullptr;
        popNode->killself();
        length--;
        return num;
    } else {
        Node *popNode = tail;
        T num = popNode->data;
        tail = popNode->prev;
        tail->next = head;
        head->prev = tail;
        popNode->killself();
        length--;
        return num;
    }
}

template<typename T>
bool CircularList<T>::insert(T value, int pos) {
    if (is_empty()) {
        return false;
    } else {
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
            Node *temp = head;
            for (int i = 0; i < pos-1; i++)
                temp = temp->next;
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
            length++;
            return true;
        }
    }
}

template<typename T>
bool CircularList<T>::remove(int pos) {
    if (is_empty()) {
        return false;
    } else {
        if (pos < 0 || pos >= size()){
            return false;
        } else if (pos == 0){
            pop_front();
            return true;
        } else if (pos == size()-1){
            pop_back();
            return true;
        } else {
            Node *popNode = head;
            for (int i = 0; i < pos; i++)
                popNode = popNode->next;
            popNode->next->prev = popNode->prev;
            popNode->prev->next = popNode->next;
            popNode->killself();
            length--;
            return true;
        }
    }
}

template<typename T>
T& CircularList<T>::operator[](int pos) {
    if (pos <= length && pos >= 0){
        if (pos == 0){
            return head->data;
        } else if (pos == length){
            return tail->data;
        } else {
            Node *temp = head;
            for (int i = 0; i < pos; i++)
                temp = temp->next;
            return temp->data;
        }
    } else {
        if (pos > size() || pos < 0){
            throw runtime_error("Invalid Position");
        } else if (size() == 0){
            throw runtime_error("No elements in the list");
        }
        throw runtime_error("ERROR");
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
    for (int i = 0; i < length; i++){
        pop_front();
    }
}

template<typename T>
void CircularList<T>::sort() {
    //TODO
}

template<typename T>
bool CircularList<T>::is_sorted() {
    //TODO
}

template<typename T>
void CircularList<T>::reverse() {
     if (size() == 1){
        Node *temp = head->next;
        head->next = head->prev;
        head->prev = temp;
    } else if (size() == length){
        Node *tempA = head;
        Node *tempB = head->next;
        do {
            Node *temp = tempA->prev;
            tempA->next = tempA->prev;
            tempA->prev = temp;
            tempA = tempB;
            tempB = tempB->next;
        } while (tempB->prev != head);
        Node *temp = head;
        head = tail;
        tail = temp;
    } else {
         throw runtime_error("No elements in the List");
     }
}

template<typename T>
string CircularList<T>::name() {
    Node *temp = head;
    string list;
    for (int i = 0; i < length; i++){
        if (temp == tail){
            list = list + to_string(temp->data);
        } else {
            list = list + to_string(temp->data) + ", ";
        }
        temp = temp->next;
    }
    return list;
}

template<typename T>
CircularList<T>::~CircularList() {
    clear();
}