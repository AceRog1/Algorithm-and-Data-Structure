//
// Created by alejandro on 21/10/2023.
//

#include "HashOpenAddressing.h"

using namespace std;

template<typename T, typename K>
HashOpenAddressing<T, K>::HashOpenAddressing(int cap) {
    capacity = cap;
    length = 0;
    hashTable = new pair<T, K>[capacity];
}

template<typename T, typename K>
int HashOpenAddressing<T, K>::size() {
    return length;
}

template<typename T, typename K>
size_t HashOpenAddressing<T, K>::max_size() {
    return capacity;
}

template<typename T, typename K>
void HashOpenAddressing<T, K>::insert(T key, K value) { // TODO
    if (length > 0){
        if (length/capacity > MAXFILLFACTOR)
            rehashing();
        size_t position = hash(key);
        hashTable[position] = value;
    } else {
        size_t position = hash(key);
        hashTable[position] = value;
    }
    length++;
}

template<typename T, typename K>
bool HashOpenAddressing<T , K>::remove(T key) {
    // TODO
}

template<typename T, typename K>
pair<T, K> HashOpenAddressing<T, K>::search(T key) {
    // TODO
}

template<typename T, typename K>
string HashOpenAddressing<T, K>::print() {
    // TODO
}

template<typename T, typename K>
void HashOpenAddressing<T, K>::clear() {
    // TODO
}

template<typename T, typename K>
bool HashOpenAddressing<T, K>::empty() {
    return length == 0;
}

template<typename T, typename K>
pair<T, K> HashOpenAddressing<T, K>::operator[](T key) {
    // TODO
}

template<typename T, typename K>
HashOpenAddressing<T, K>& HashOpenAddressing<T, K>::operator=(HashOpenAddressing<T, K> other) {
    // TODO
}

template<typename T, typename K>
pair<T, K> HashOpenAddressing<T, K>::extraxt(T key) {
    // TODO
}

template<typename T, typename K>
HashOpenAddressing<T, K>::~HashOpenAddressing() {
    // TODO
}

template<typename T, typename K>
void HashOpenAddressing<T, K>::rehashing() {
    // TODO
}

template<typename T, typename K>
size_t HashOpenAddressing<T, K>::hash(T key) {
    if (std::is_same<T, int>::value){
        if (key == 0) return 0;
        else return key%capacity;
    } else if (std::is_same<T, char>::value){
        auto k = static_cast<size_t>(key);
        if (k == 0) return 0;
        else return k%capacity;
    } else if (std::is_same<T, std::string>::value){
        size_t k = 0;
        for (size_t i = 0; i < key.size(); i++)
            k += static_cast<size_t>(key[i]);
        if (k == 0) return 0;
        else return k%capacity;
    } else if (std::is_same<T, double>::value){
        std::string s = std::to_string(key);
        size_t k = 0;
        for (char i : s)
            k += static_cast<size_t>(i);
        if (k == 0) return 0;
        else return k%capacity;
    } else if (std::is_same<T, float>::value){
        std::string s = std::to_string(key);
        size_t k = 0;
        for (char i : s) k += static_cast<size_t>(i);
        if (k == 0) return 0;
        else return k%capacity;
    } else {
        std::string s = std::to_string(key);
        size_t k = 0;
        for (char i : s) k += static_cast<size_t>(i);
        if (k == 0) return 0;
        else return k%capacity;
    }
}
