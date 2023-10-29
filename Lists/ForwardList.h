//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_FORWARDLIST_H
#define ALGORITHMANDDATASTRUCTURE_FORWARDLIST_H

#include "List.h"

template<typename T>
class ForwardList : public List<T>{
private:
    struct Node{
        T data;
        Node* next;
        Node(){
            next = nullptr;
        }
        explicit Node(T value){
            data = value;
            next = nullptr;
        }
        void killself(){
            next = nullptr;
            delete this;
        };
    };
private:
    int length;
    Node* head;
public:
    ForwardList();
    T front() override;
    T back() override;
    void push_front(T value) override;
    void push_back(T value) override;
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
    ~ForwardList();
};


#endif //ALGORITHMANDDATASTRUCTURE_FORWARDLIST_H
