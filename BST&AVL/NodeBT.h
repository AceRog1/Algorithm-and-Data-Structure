//
// Created by alejandro on 16/05/2024.
//

#ifndef ALGORITHM_AND_DATA_STRUCTURES_NODEBT_H
#define ALGORITHM_AND_DATA_STRUCTURES_NODEBT_H

template<typename T>
struct NodeBT{
    T data;
    int height;
    NodeBT* left;
    NodeBT* right;
    NodeBT(){
        height = 0;
        left = nullptr;
        right = nullptr;
    }
    NodeBT(T val) {
        data = val;
        height = 0;
        left = nullptr;
        right = nullptr;
    }
    void killself(){
        if (left != nullptr)
            left->killself();
        if (right != nullptr)
            right->killself();
        delete this;
    }
};

#endif //ALGORITHM_AND_DATA_STRUCTURES_NODEBT_H
