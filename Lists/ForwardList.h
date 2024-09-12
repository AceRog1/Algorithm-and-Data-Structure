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
private:
    friend void merge(ForwardList<T>* list, int left, int mid, int right);
    friend void mergeSort(ForwardList<T>* list, int left, int right);
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

template<typename T>
void merge(ForwardList<T>*& list, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    typename ForwardList<T>::Node* temp11 = list->head;
    typename ForwardList<T>::Node* temp12 = list->head;

    ForwardList<T>* L, R;

    for(size_t i = 0; i < n1; i++){
        T val = temp11->data;
        L->push_back(val);
        temp11 = temp11->next;
        temp12 = temp12->next;
    }
    for(size_t i = 0; i < n2; i++){
        T val = temp12->data;
        R->push_back(val);
        temp12 = temp12->next;
    }

    delete temp11;
    delete temp12;

    typename ForwardList<T>::Node* temp21 = list->head; // i
    typename ForwardList<T>::Node* temp22 = list->head; // j
    typename ForwardList<T>::Node* temp23 = list->head; // k

    int i = 0, j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            //arr[k] = L[i];
            temp21 = temp21->next;
            i++;
        }
        else {
            //arr[k] = R[j];
            temp22 = temp22->next;
            j++;
        }
        temp23 = temp23->next;
        k++;
    }

}

template<typename T>
void mergeSort(ForwardList<T>* list, int left, int right){
    if(left >= right)
        return;
    int mid = left + (right - left)/2;
    mergeSort(list, left, mid);
    mergeSort(list, mid, right);
    merge(list,left, mid, right);
}


#endif //ALGORITHMANDDATASTRUCTURE_FORWARDLIST_H
