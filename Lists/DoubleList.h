//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_DOUBLELIST_H
#define ALGORITHMANDDATASTRUCTURE_DOUBLELIST_H

#include "List.h"


template<typename T>
class DoubleList;


template<typename T>
class DoubleListIterator {
private:
    typename DoubleList<T>::Node *current;
public:
    DoubleListIterator(){
        current = nullptr;
    }
    explicit DoubleListIterator(typename DoubleList<T>::Node *pointer){
        current = pointer;
    }
    bool operator!=(const DoubleListIterator<T> &other){
        return current != other.current;
    }
    DoubleListIterator &operator++(){
        current = current->next;
        return *this;
    }
    DoubleListIterator &operator--(){
        current = current->prev;
        return *this;
    }
    T operator*(){
        return current->data;
    }
};


template<typename T>
class DoubleList : public List<T>{
private:
    struct Node{
        T data;
        Node* next;
        Node* prev;
        Node(){
            next = nullptr;
            prev = nullptr;
        }
        explicit Node(T value){
            data = value;
            next = nullptr;
            prev = nullptr;
        }
        void killself(){
            next = nullptr;
            prev = nullptr;
            delete this;
        };
    };
private:
    int length;
    Node* head;
    Node* tail;
public:
    DoubleList();
    T front() override;
    T back() override;
    void push_front(T value) override;
    void push_back(T value) override;
    T pop_front() override;
    T pop_back() override;
    bool insert(T value, int pos) override;
    bool remove(int pos) override;
    T& operator[](int pos) override;
    bool is_empty() override;
    int size() override;
    void clear() override;
    void sort() override;
    bool is_sorted() override;
    void reverse() override;
    std::string print() override;
    ~DoubleList();
public:
    friend class DoubleListIterator<T>;
    typedef DoubleListIterator<T> iterator;
public:
    iterator beginFront(){
        return iterator(this->head);
    }
    iterator beginBack(){
        return iterator(this->tail);
    }
    iterator end(){
        return iterator(nullptr);
    }
};


#endif //ALGORITHMANDDATASTRUCTURE_DOUBLELIST_H
