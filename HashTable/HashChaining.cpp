//
// Created by alejandro on 21/10/2023.
//

#include "HashChaining.h"
#include <cmath>

using namespace std;

template<typename TK, typename TV>
HashChaining<TK, TV>::HashChaining(int cap) {
    capacity = cap;
    length = 0;
    hash_table = new ListNode<std::pair<TK, TV>>*[capacity];
    for (size_t i = 0; i < capacity; i++)
        hash_table[i] = nullptr;
}

template<typename TK, typename TV>
size_t HashChaining<TK, TV>::size() {
    return length;
}

template<typename TK, typename TV>
int HashChaining<TK, TV>::max_size() {
    return capacity;
}

template<typename TK, typename TV>
void HashChaining<TK, TV>::insert(TK key, TV value) {
    if (length >= floor(capacity * (MAXFILLFACTOR * MAXCOLISION)))
        rehashing();
    size_t pos = hashFunc(key);
    auto node = new ListNode<pair<TK, TV>>();
    node->data.first = key;
    node->data.second = value;
    size_t posIter = pos;
    do {
        ListNode<pair<TK, TV>> *pivot = hash_table[posIter];
        for (size_t i = 0; i < MAXCOLISION-1; i++){
            if (hash_table[posIter] == nullptr){
                hash_table[posIter] = node;
                length++;
                return;
            }
            if (pivot->data.first == key)
                throw runtime_error("Repeated Key, the Key must be unique");
            if (pivot->next == nullptr){
                pivot->next = node;
                length++;
                return;
            }
            pivot = pivot->next;
        }
        posIter++;
        posIter = posIter % capacity;
    } while (posIter != pos);
}

template<typename TK, typename TV>
bool HashChaining<TK, TV>::remove(TK key) {
    size_t pos = hashFunc(key);
    size_t posIter = pos;
    do {
        ListNode<pair<TK, TV>> *pivot = hash_table[posIter];
        for (size_t i = 0; i < MAXCOLISION-1; i++){
            if (pivot == nullptr) break;
            if ((i == 0 && hash_table[posIter] != nullptr) && hash_table[posIter]->data.first == key){
                    ListNode<pair<TK, TV>>* temp = hash_table[posIter]->next;
                    hash_table[posIter]->killNode();
                    hash_table[posIter] = temp;
                    length--;
                    return true;
            } else if (pivot->next->data.first == key){
                ListNode<pair<TK, TV>>* temp = pivot->next;
                pivot->next = temp->next;
                temp->killNode();
                length--;
                return true;
            }
            pivot = pivot->next;
        }
        posIter++;
        posIter = posIter % capacity;
    } while (posIter != pos);
    return false;
}

template<typename TK, typename TV>
pair<TK, TV> HashChaining<TK, TV>::search(TK key) {
    size_t pos = hashFunc(key);
    size_t posIter = pos;
    do {
        ListNode<pair<TK, TV>> *pivot = hash_table[posIter];
        while (pivot != nullptr){
            if (pivot->data.first == key)
                return pivot->data;
            pivot = pivot->next;
        }
        posIter++;
        posIter = posIter % capacity;
    } while (posIter != pos);
    throw runtime_error("The element do not exist");
}

template<typename TK, typename TV>
void HashChaining<TK, TV>::clear() {
    for (size_t i = 0; i < capacity; i++){
        while (hash_table[i] != nullptr){
            ListNode<pair<TK, TV>>* pivot = hash_table[i];
            hash_table[i] = hash_table[i]->next;
            pivot->killNode();
            length--;
        }
    }
}

template<typename TK, typename TV>
bool HashChaining<TK, TV>::empty() {
    return length == 0;
}

template<typename TK, typename TV>
TV HashChaining<TK, TV>::operator[](TK key) {
    size_t pos = hashFunc(key);
    size_t posIter = pos;
    do {
        ListNode<pair<TK, TV>> *pivot = hash_table[posIter];
        while (pivot != nullptr){
            if (pivot->data.first == key)
                return pivot->data.second;
            pivot = pivot->next;
        }
        posIter++;
        posIter = posIter % capacity;
    } while (posIter != pos);
    throw runtime_error("The element do not exist");
}

template<typename TK, typename TV>
pair<TK, TV> HashChaining<TK, TV>::extract(TK key) {
    size_t pos = hashFunc(key);
    size_t posIter = pos;
    do {
        ListNode<pair<TK, TV>> *pivot = hash_table[posIter];
        for (size_t i = 0; i < MAXCOLISION-1; i++){
            if (pivot == nullptr) break;
            if ((i == 0 && hash_table[posIter] != nullptr) && hash_table[posIter]->data.first == key){
                ListNode<pair<TK, TV>>* temp = hash_table[posIter]->next;
                pair<TK, TV> n = hash_table[posIter]->data;
                hash_table[posIter]->killNode();
                hash_table[posIter] = temp;
                length--;
                return n;
            } else if (pivot->next->data.first == key){
                ListNode<pair<TK, TV>>* temp = pivot->next;
                pivot->next = temp->next;
                pair<TK, TV> n = temp->data;
                temp->killNode();
                length--;
                return n;
            }
            pivot = pivot->next;
        }
        posIter++;
        posIter = posIter % capacity;
    } while (posIter != pos);
    throw runtime_error("The element do not exist");
}

template<typename TK, typename TV>
HashChaining<TK, TV>::~HashChaining() {
    clear();
    delete [] hash_table;
    hash_table = nullptr;
    length = 0;
    capacity = 0;
}

template<typename TK, typename TV>
void HashChaining<TK, TV>::rehashing() {
    ListNode<pair<TK, TV>>** oldHash_table = hash_table;
    int oldCapacity = capacity;
    capacity *= 2;
    hash_table = new ListNode<pair<TK, TV>>*[capacity]();
    length = 0;
    for (size_t i = 0; i < oldCapacity; i++){
        ListNode<pair<TK, TV>>* pivot = oldHash_table[i];
        while(pivot != nullptr){
            insert(pivot->data.first, pivot->data.second);
            ListNode<pair<TK, TV>>* temp = pivot;
            pivot = pivot->next;
            temp->killNode();
        }
    }
    delete [] oldHash_table;
}