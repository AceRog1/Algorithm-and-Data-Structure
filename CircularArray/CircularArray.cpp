//
// Created by alejandro on 21/10/2023.
//

#include "CircularArray.h"
#include <sstream>
#include <algorithm>

template<typename T>
CircularArray<T>::CircularArray(int _capacity) {
    capacity = _capacity;
    array = new T[capacity];
    back = front = -1;
}

template<typename T>
void CircularArray<T>::push_front(T data) {
    if (is_full()){ resize(); }
    if (this->back == -1 && this->front == -1){
        this->array[0] = data;
        back = front = 0;
    } else if (front == 0){
        int pos = capacity - 1;
        this->array[pos] = data;
        front = pos;
    } else {
        int pos = front - 1;
        this->array[pos] = data;
        front = pos;
    }
}

template<typename T>
void CircularArray<T>::push_back(T data) {
    if (is_full()){ resize(); }
    if (this->back == -1 && this->front == -1){
        this->array[0] = data;
        back = front = 0;
    } else if (back == capacity-1){
        int pos = 0;
        this->array[pos] = data;
        back = pos;
    } else {
        int pos = back + 1;
        this->array[pos] = data;
        back = pos;
    }
}

template<typename T>
void CircularArray<T>::insert(T data, int pos) {
    if (pos < 0 || pos > size()){
        throw runtime_error("Invalid position");
    } else if (is_empty() == false){
        if (pos == size()){
            push_back(data);
        } else if (pos == 0){
            push_front(data);
        } else {
            if (is_full()){ resize(); }
            T *newArray = new T[capacity];
            int newFront = 0;
            int newBack = size();
            int index = 0;
            for (int i = front; i != back; i++) {
                if (i == capacity) {
                    i = -1;
                } else if (index == pos){
                    newArray[index] = data;
                    index++;
                    i--;
                } else {
                    newArray[index] = array[i];
                    index++;
                }
            }
            if (pos == index){
                newArray[index] = data;
                newArray[index+1] = array[back];
            } else {
                newArray[index] = array[back];
            }
            clear();
            array = newArray;
            front = newFront;
            back = newBack;
        }
    } else {
        throw runtime_error("No elements in the List");
    }
}

template<typename T>
T CircularArray<T>::pop_front() {
    if (is_empty() == false){ // se puede colocar asi: (!is_empty())
        T val = array[front];
        if (back == 0 && front == 0 && back == front)
            back = front = -1;
        else if (front == capacity-1)
            front = 0;
        else
            front = next(front);
        return val;
    } else {
        throw runtime_error("No elements in the List");
    }
}

template<typename T>
T CircularArray<T>::pop_back() {
    if (is_empty() == false){
        T val = array[back];
        if (back == 0 && front == 0 && back == front)
            back = front = -1;
        else if (back == 0)
            back = capacity-1;
        else
            back = prev(back);
        return val;
    } else {
        throw runtime_error("No elements in the List");
    }
}

template<typename T>
bool CircularArray<T>::is_full() {
    return next(back) == front && prev(front) == back;
}

template<typename T>
bool CircularArray<T>::is_empty() {
    if (back == -1 && front == -1){
        return true;
    } else {
        return false;
    }
}

template<typename T>
int CircularArray<T>::size() {
    int s = 1;
    for (int i = front; i != back; i++){
        if (i == capacity){
            i = -1;
        } else {
            s++;
        }
    }
    return s;
}

template<typename T>
void CircularArray<T>::clear() {
    delete[] array;
}

template<typename T>
T& CircularArray<T>::operator[](int pos) {
    if (pos < 0 || pos >= size()){
        throw runtime_error("Invalid position");
    } else if (is_empty() == false) {
        if (pos == 0){
            return array[front];
        } else if (pos == size()-1){
            return array[back];
        } else {
            int index = 0;
            int i = front;
            while (index != pos){
                if (i == capacity-1){
                    index++;
                    i = -1;
                } else { index++; }
                i++;
            }
            T data = array[i];
            return data;
        }
    } else {
        throw runtime_error("No elements in the List");
    }
}

template<typename T>
void CircularArray<T>::sort() {
    if (is_empty() == false){
        if (size() == 1){
            return;
        } else {
            T *sortArray = new T[capacity];
            int newFront = 0;
            int newBack = size()-1;
            int index = 0;
            for (int i = front; i != back; i++) { // O (n)
                if (i == capacity) {
                    i = -1;
                } else {
                    sortArray[index] = array[i];
                    index++;
                }
            }
            sortArray[size()-1] = array[back];
            int n = index+1;
            std::sort(sortArray, sortArray + n); // O(n log n)
            clear();
            array = sortArray;
            front = newFront;
            back = newBack;
        }
    } else {
        throw runtime_error("No elements in the List");
    }
}

template<typename T>
bool CircularArray<T>::is_sorted() {
    if (is_empty() == false){
        if (size() == 1){
            return true;
        } else if (size() == 2){
            if (array[front] > array[back])
                return false;
            return true;
        } else {
            bool sort = true;
            for (int i = front; i != back; i++){
                if (i == capacity){
                    i = -1;
                } else {
                    if (i != front && array[i] < array[i-1]) {
                        sort = false;
                        break;
                    }
                }
            }
            if (array[back] < array[prev(back)])
                sort = false;
            return sort;
        }
    } else {
        throw runtime_error("No elements in the List");
    }
}

template<typename T>
void CircularArray<T>::reverse() {
    if (is_empty() == false){
        if (size() == 1){
            return;
        } else {
            T *reverseArray = new T[capacity];
            int newFront = 0;
            int newBack = size()-1;
            int index = 0;
            for (int i = back; i != front; i--) {
                if (i == -1) {
                    i = size()+1;
                } else {
                    reverseArray[index] = array[i];
                    index++;
                }
            }
            reverseArray[size()-1] = array[front];
            clear();
            array = reverseArray;
            front = newFront;
            back = newBack;
        }
    } else {
        throw runtime_error("No elements in the List");
    }
}

template<typename T>
string CircularArray<T>::to_string(std::string sep) {
    if (is_empty() == false){
        stringstream ss;
        for (int i = front; i != back; i++){
            if (i == capacity){
                i = -1;
            } else {
                ss << array[i] << sep;
            }
        }
        ss << array[back];
        return ss.str();
    } else {
        throw runtime_error("No elements in the Array");
    }
}

template<typename T>
CircularArray<T>::~CircularArray() {
    clear();
}

template<typename T>
void CircularArray<T>::resize() {
    int newCapacity = capacity + (capacity/2);
    T *resizeArray = new T[newCapacity];
    int newFront = 0;
    int newBack = size()-1;
    int index = 0;
    for (int i = front; i != back; i++) {
        if (i == capacity) {
            i = -1;
        } else {
            resizeArray[index] = array[i];
            index++;
        }
    }
    resizeArray[size()-1] = array[back];
    clear();
    array = resizeArray;
    front = newFront;
    back = newBack;
    capacity = newCapacity;
}
