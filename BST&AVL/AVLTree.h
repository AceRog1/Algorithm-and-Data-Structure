//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_AVLTREE_H
#define ALGORITHMANDDATASTRUCTURE_AVLTREE_H

#include "NodeBT.h"

template<typename T>
class AVLTree {
private:
    NodeBT<T> *root;
public:
    AVLTree(){
        root = nullptr;
    }
    void insert(T val){
        insert(val, this->root);
    }
    bool find(T val){
        return find(val, this->root);
    }
    int height(){
        return height(this->root);
    }
    T minValue(){
        return minValue(this->root);
    }
    T maxValue(){
        return maxValue(this->root);
    }
    int size(){
        return size(this->root);
    }
    bool isBalanced(){
        return isBalanced(this->root);
    }
    void remove(T val){
        remove(val, this->root);
    }
    void displayInOrder(){
        displayInOrder(this->root);
    }
    void displayPreOrder(){
        displayPreOrder(this->root);
    }
    void displayPostOrder(){
        displayPostOrder(this->root);
    }
    void displayBFS(){
        displayBFS(this->root);
    }
    void displayDFS(){
        displayDFS(this->root);
    }
    void displayPretty(){
        displayPretty(this->root);
    }
    ~AVLTree(){
        root->killself();
    }
private:
    void insert(T val, NodeBT<T> *&node); // Insert
    bool find(T val, NodeBT<T> *node); // encontrar
    int height(NodeBT<T> *node); // altura
    T minValue(NodeBT<T> *node); // valor minimo
    T maxValue(NodeBT<T> *node); // valor maximo
    int size(NodeBT<T> *node); // Tamanio del arbol
    bool isBalanced(NodeBT<T> *node); // Si esta Balanceado
    void remove(T val, NodeBT<T> *&node); // remove
    void displayInOrder(NodeBT<T> *node); // inOrder
    void displayPreOrder(NodeBT<T> *node); // preOrder
    void displayPostOrder(NodeBT<T> *node); // postOrder
    void displayBFS(NodeBT<T> *node); // BFS
    void displayDFS(NodeBT<T> *node); // DFS
    void displayPretty(NodeBT<T> *node); // Pretty
private:
    int balancingFactor(NodeBT<T> *node);
    void updateHeight(NodeBT<T> *node);
    void balance(NodeBT<T> *&node);
    void left_rota(NodeBT<T> *&node);
    void right_rota(NodeBT<T> *&node);
};


#endif //ALGORITHMANDDATASTRUCTURE_AVLTREE_H
