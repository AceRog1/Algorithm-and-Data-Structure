//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_CIRCULARLIST_H
#define ALGORITHMANDDATASTRUCTURE_CIRCULARLIST_H


#include "List.h"
#include <string>


template<typename T>
class CircularList;


template<typename T>
class CircularListIterator{
private:
    typename CircularList<T>::Node *current;
public:
    CircularListIterator(){
        current = nullptr;
    }
    explicit CircularListIterator(typename CircularList<T>::Node *pionter){
        current = pionter;
    }
    bool operator!=(const CircularListIterator<T> &other){
        return current != other.current;
    }
    CircularListIterator operator++(){
        current = current->next;
        return *this;
    }
    CircularListIterator operator--(){
        current = current->prev;
        return *this;
    }
    T operator*(){
        return current->data;
    }
};


template<typename T>
class CircularList : public List<T>{
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
    Node centinel;
    Node *cptr;
public:
    CircularList();
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
    ~CircularList();
public:
    friend class CircularListIterator<T>;
    typedef CircularListIterator<T> iterator;
public:
    iterator beginFront(){
        return iterator(centinel.next);
    }
    iterator beginBack(){
        return iterator(centinel.prev);
    }
    iterator end(){
        return iterator(cptr);
    }
};

#endif //ALGORITHMANDDATASTRUCTURE_CIRCULARLIST_H
