//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_DOUBLELIST_H
#define ALGORITHMANDDATASTRUCTURE_DOUBLELIST_H

#include "List.h"

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
    void push_front(T) override;
    void push_back(T) override;
    T pop_front() override;
    T pop_back() override;
    bool insert(T, int) override;
    bool remove(int) override;
    T& operator[](int) override;
    bool is_empty() override;
    int size() override;
    void clear() override;
    void sort() override;
    bool is_sorted() override;
    void reverse() override;
    std::string name() override;
    ~DoubleList();
};


#endif //ALGORITHMANDDATASTRUCTURE_DOUBLELIST_H
