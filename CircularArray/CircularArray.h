//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_CIRCULARARRAY_H
#define ALGORITHMANDDATASTRUCTURE_CIRCULARARRAY_H

#include <iostream>

using namespace std;

template<typename T>
class CircularArray {
private:
    T *array; // Puntero a Array.
    int capacity; // Capasidad del Array.
    int back, front; // Senialan donde comienza y termina el Array.
public:
    explicit CircularArray(int _capacity = 10);
    void push_front(T data);
    void push_back(T data);
    void insert(T data, int pos);
    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();
    int size();
    void clear();
    T& operator[](int pos);
    void sort();
    bool is_sorted();
    void reverse();
    string to_string(string sep=" ");
    virtual ~CircularArray();
private:
    void resize();

    int next(int index){
        return (index + 1) % capacity;
    }
    int prev(int index){
        return (index != 0) ? (index-1) : (capacity-1);
    }
};


#endif //ALGORITHMANDDATASTRUCTURE_CIRCULARARRAY_H
