//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_FORWARDLIST_H
#define ALGORITHMANDDATASTRUCTURE_FORWARDLIST_H

#include "List.h"

template<typename T>
class ForwardList;

template <typename T>
class ForwardListInterator{
private:
    typename ForwardList<T>::Node* current;
public:
    ForwardListInterator(){
        current = nullptr;
    }
    explicit ForwardListInterator(typename ForwardList<T>::Node* head){
        current = head;
    }
    bool operator!=(const ForwardListInterator<T> &other){
        return current != other.current;
    }
    ForwardListInterator &operator++() {
        current = current->next;
        return *this;
    }
    T operator*(){
        return current->data;
    }
};

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
    bool insert(T value, int pos) override;
    bool remove(int pos) override;
    T& operator[](int pos) override;
    bool is_empty() override;
    int size() override;
    void clear() override;
    void sort() override;
    bool is_sorted() override;
    void reverse() override;
    std::string name() override;
    ~ForwardList();
public:
    friend class ForwardListInterator<T>;
    typedef ForwardListInterator<T> iterator;
public:
    iterator begin() {
        return iterator(this->head);
    }
    iterator end() {
        return iterator(nullptr);
    }
};


#endif //ALGORITHMANDDATASTRUCTURE_FORWARDLIST_H
