//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_LIST_H
#define ALGORITHMANDDATASTRUCTURE_LIST_H

#include <iostream>
#include <string>

template<typename T>
class List{
public:
    virtual T front() = 0;
    virtual T back() = 0;
    virtual void push_front(T) = 0;
    virtual void push_back(T) = 0;
    virtual T pop_front() = 0;
    virtual T pop_back() = 0;
    virtual bool insert(T, int) = 0;
    virtual bool remove(int) = 0;
    virtual T& operator[](int) = 0;
    virtual bool is_empty() = 0;
    virtual int size() = 0;
    virtual void clear() = 0;
    virtual void sort() = 0;
    virtual bool is_sorted() = 0;
    virtual void reverse() = 0;
    virtual std::string print() = 0;
};

#endif //ALGORITHMANDDATASTRUCTURE_LIST_H
