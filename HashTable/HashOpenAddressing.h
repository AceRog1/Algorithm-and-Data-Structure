//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_HASHOPENADDRESSING_H
#define ALGORITHMANDDATASTRUCTURE_HASHOPENADDRESSING_H

#include <iostream>
#include <utility>
#include <string>
#include <tuple>
#include <type_traits>

const double MAXFILLFACTOR = 0.7;

enum class state {
    NTH, BKT, DLT
};

template<typename T, typename K>
class HashOpenAddressing {
private:
    size_t length;
    int capacity;
    std::pair<T, K>* hashTable;
public:
    explicit HashOpenAddressing(int cap = 13);
    int size();
    size_t max_size();
    void insert(T key, K value);
    bool remove(T key);
    std::pair<T, K> search(T key);
    void clear();
    bool empty();
    std::pair<T, K> operator [](T key);
    HashOpenAddressing& operator=(HashOpenAddressing<T, K> other);
    std::pair<T, K> extraxt(T key);
    ~HashOpenAddressing();
private:
    void rehashing();
    size_t hash(T key);
};


#endif //ALGORITHMANDDATASTRUCTURE_HASHOPENADDRESSING_H
