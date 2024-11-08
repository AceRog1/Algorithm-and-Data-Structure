//
// Created by alejandro on 21/10/2023.
//

#include "HashOpenAddressing.h"

using namespace std;

template<typename TK, typename TV>
HashOpenAddressing<TK, TV>::HashOpenAddressing(int cap) {
    capacity = cap;
    length = 0;
    hash_table = new std::tuple<TK, TV, state>*[capacity];
    for (size_t i = 0; i < capacity; i++)
        hash_table[i] = new std::tuple<TK, TV, state>(TK{}, TV{}, state::NTH);
}

template<typename TK, typename TV>
int HashOpenAddressing<TK, TV>::size() {
    return length;
}

template<typename TK, typename TV>
size_t HashOpenAddressing<TK, TV>::max_size() {
    return capacity;
}

template<typename TK, typename TV>
void HashOpenAddressing<TK, TV>::insert(TK key, TV value) {
    if (length >= capacity * MAXFILLFACTOR)
        rehashing();
    size_t pos = hashFunc(key);
    while (get<2>(*hash_table[pos % capacity]) == state::STH) {
        pos++;
        pos = pos % capacity;
    }
    *hash_table[pos % capacity] = std::make_tuple(key, value, state::STH);
    length++;
}


template<typename TK, typename TV>
bool HashOpenAddressing<TK , TV>::remove(TK key) { // TODO
    size_t pos = hashFunc(key);
    size_t initialPos = pos;
    while(get<2>(*hash_table[pos%capacity]) != state::STH && get<0>(*hash_table[pos%capacity]) != key){
         pos++;
         if ((pos+1)%capacity == initialPos)
             return false;
         pos = pos % capacity;
    }
  get<2>(*hash_table[pos]) = state::DLT;
    length--;
    return true;
}

template<typename TK, typename TV>
pair<TK, TV> HashOpenAddressing<TK, TV>::search(TK key) { // TODO
    size_t pos = hashFunc(key);
    if (get<0>(hash_table[pos]) == key && get<2>(hash_table[pos]) == state::STH){
        pair<TK, TV> element(get<0>(hash_table[pos]), get<1>(hash_table[pos]));
        return element;
    } else {
        throw runtime_error("The element do not exist");
    }
}

template<typename TK, typename TV>
void HashOpenAddressing<TK, TV>::clear() {
    for (size_t i = 0; i < capacity; i++)
        delete hash_table[i];
    delete[] hash_table;
}

template<typename TK, typename TV>
bool HashOpenAddressing<TK, TV>::empty() {
    return length == 0;
}

template<typename TK, typename TV>
TV HashOpenAddressing<TK, TV>::operator[](TK key) { // TODO
    size_t pos = hashFunc(key);
    if (get<0>(hash_table[pos]) == key && get<2>(hash_table[pos]) == state::STH){
        return get<1>(hash_table[pos]);
    } else {
        throw runtime_error("The element do not exist");
    }
}

template<typename T, typename K>
HashOpenAddressing<T, K>& HashOpenAddressing<T, K>::operator=(HashOpenAddressing<T, K> other) {
    // TODO
}

template<typename TK, typename TV>
pair<TK, TV> HashOpenAddressing<TK, TV>::extraxt(TK key) { // TODO
    size_t pos = hashFunc(key);
    if (get<0>(hash_table[pos]) == key && get<2>(hash_table[pos]) == state::STH){
        pair<TK, TV> elementDeleted(get<0>(hash_table[pos]), get<1>(hash_table[pos]));
        get<2>(hash_table[pos]) = state::DLT;
        length--;
        return elementDeleted;
    } else {
        throw runtime_error("The element do not exist");
    }
}

template<typename T, typename K>
HashOpenAddressing<T, K>::~HashOpenAddressing() {
    clear();
}

template<typename TK, typename TV>
void HashOpenAddressing<TK, TV>::rehashing() { // TODO
    int newCapacity = capacity*2;
    auto** newHash_table = new tuple<TK, TV, state>*[capacity];
    for (size_t i = 0; i < newCapacity; i++)
        newHash_table[i] = new tuple<TK, TV, state>(TK{}, TV{}, state::NTH);

    for (size_t i = 0; i < capacity; i++) {
        if (get<2>(*hash_table[i]) == state::STH) {
            size_t newPos = hashFunc(get<0>(*hash_table[i]));
            *newHash_table[newPos] = *hash_table[i];
        }
    }
    hash_table = newHash_table;
}

//template<typename T>
//size_t hashFuc(T key, int cap){
//    auto k = static_cast<size_t>(key);
//    if (k == 0) return 0;
//    else return k%cap;
//}
//
//template<>
//size_t hashFuc(int key, int cap){
//    if (key == 0) return 0;
//    else return key%cap;
//}
//
//template<>
//size_t hashFuc(char key, int cap){
//    auto k = static_cast<size_t>(key);
//    if (k == 0) return 0;
//    else return k%cap;
//}
//
//template<>
//size_t hashFuc(double key, int cap){
//    std::string s = std::to_string(key);
//    size_t k = 0;
//    for (char i : s)
//        k += static_cast<size_t>(i);
//    if (k == 0) return 0;
//    else return k%cap;
//}
//
//template<>
//size_t hashFuc(float key, int cap){
//    std::string s = std::to_string(key);
//    size_t k = 0;
//    for (char i : s) k += static_cast<size_t>(i);
//    if (k == 0) return 0;
//    else return k%cap;
//}
//
//template<>
//size_t hashFuc(std::string key, int cap){
//    size_t k = 0;
//    for (size_t i = 0; i < key.length(); i++)
//        k += static_cast<size_t>(key[i]);
//    if (k == 0) return 0;
//    else return k%cap;
//}
