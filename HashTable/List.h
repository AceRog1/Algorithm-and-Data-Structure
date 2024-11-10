//
// Created by Alejandro on 10/11/24.
//

#ifndef ALGORITHM_AND_DATA_STRUCTURE_LIST_H
#define ALGORITHM_AND_DATA_STRUCTURE_LIST_H

template<typename T>
struct ListNode{
    T data;
    ListNode* next;
    ListNode() : next(nullptr) {}
    explicit ListNode(T val) : data(val), next(nullptr) {}
    void killNode(){
        next = nullptr;
        delete this;
    }
};

#endif //ALGORITHM_AND_DATA_STRUCTURE_LIST_H
