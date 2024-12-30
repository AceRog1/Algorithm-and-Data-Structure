//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_HASHCHAINING_H
#define ALGORITHMANDDATASTRUCTURE_HASHCHAINING_H

#include <iostream>
#include <utility>
#include <string>
#include "List.h"

const double MAXFILLFACTOR = 0.2;
const int MAXCOLISION = 3;

template<typename TK, typename TV>
class HashChaining {
private:
    size_t length{};
    int capacity{};
    ListNode<std::pair<TK, TV>>** hash_table;
public:
    explicit HashChaining(int cap = 13);
    size_t size();
    int max_size();
    void insert(TK key, TV value);
    bool remove(TK key);
    std::pair<TK, TV> search(TK key);
    void clear();
    bool empty();
    TV operator [](TK key);
    std::pair<TK, TV> extract(TK key);
    ~HashChaining();
private:
    void rehashing();
    size_t hashFunc(TK key){
        if (key == 0) return 0;
        else return key%capacity;
    }
};

#endif //ALGORITHMANDDATASTRUCTURE_HASHCHAINING_H
