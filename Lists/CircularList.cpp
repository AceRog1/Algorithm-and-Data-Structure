//
// Created by alejandro on 21/10/2023.
//

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
        /*
        tail->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = tail;
        head = newNode;
         */
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
        /*
        tail->next = newNode;
        head->prev = newNode;
        newNode->next = head;
        newNode->prev = tail;
        tail = newNode;
         */
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
    /* Intento con for loop
    for (int i = 0; i < length+1; i++)
        pop_front();
    */
    while(cptr->next != cptr)
        pop_front();
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
string CircularList<T>::name() {
    Node* temp = cptr;
    temp = temp->next;
    string list;
    while(temp->next != cptr){
        list = list + to_string(temp->data) + " , ";
        temp = temp->next;
    }
    list = list + to_string(temp->data);
    return list;
}

template<typename T>
CircularList<T>::~CircularList() {
    clear();
}