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
    NTH, STH, DLT
};
/// NTH -> Nothing |
/// STH -> Something |
/// DLT -> Deleted

template<typename TK, typename TV>
class HashOpenAddressing {
private:
    size_t length;//Falta arreglar (tener en cuenta el size_t y el int que no se contradigan)
    int capacity;
    //std::pair<T, K>* hashTable;
    std::tuple<TK, TV, state>** hash_table;
public:
    explicit HashOpenAddressing(int cap = 13);
    int size();
    size_t max_size();
    void insert(TK key, TV value);
    bool remove(TK key);
    std::pair<TK, TV> search(TK key);
    void clear();
    bool empty();
    TV operator [](TK key);
    std::pair<TK, TV> extraxt(TK key);
    ~HashOpenAddressing();
private:
    void rehashing();
    //friend size_t hashFuc(int key, int cap);
    size_t hashFunc(TK key){
        if (key == 0) return 0;
        else return key%capacity;
    }
};

//template<typename T>
//size_t hashFuc(T key, int cap);
//
//template<>
//size_t hashFuc(int key, int cap);
//
//template<>
//size_t hashFuc(char key, int cap);
//
//template<>
//size_t hashFuc(double key, int cap);
//
//template<>
//size_t hashFuc(float key, int cap);
//
//template<>
//size_t hashFuc(std::string key, int cap);



#endif //ALGORITHMANDDATASTRUCTURE_HASHOPENADDRESSING_H
