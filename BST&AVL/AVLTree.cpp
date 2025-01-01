//
// Created by alejandro on 21/10/2023.
//

//ctrl + mayus + /
//ctrl + /

#include <iostream>
#include <queue>
#include <stack>
#include "AVLTree.h"

using namespace std;

template<typename T>
void AVLTree<T>::insert(T val, NodeBT<T> *&node) {
    if (node == nullptr){
        node = new NodeBT<T>(val);
        return;
    }
    (val < node->data)?(insert(val, node->left)):(insert(val, node->right));
    balance(node);
    updateHeight(node);
}

template<typename T>
bool AVLTree<T>::find(T val, NodeBT<T> *node) {
    if(node == nullptr)
        return false;
    if(node->data == val)
        return true;
    if (val < node->data){
        return find(val, node->left);
    } else {
        return find(val, node->right);
    }
}

template<typename T>
int AVLTree<T>::height(NodeBT<T> *node) {
    if (node == nullptr)
        return -1;
    else
        return node->height;
}

template<typename T>
T AVLTree<T>::minValue(NodeBT<T> *node) {
    if (node == nullptr)
        throw runtime_error("No elements in the Tree");
    if (node->left == nullptr)
        return node->data;
    return minValue(node->left);
}

template<typename T>
T AVLTree<T>::maxValue(NodeBT<T> *node) {
    if (node == nullptr)
        throw runtime_error("No elements in the Tree");
    if (node->right == nullptr)
        return node->data;
    return maxValue(node->right);
}

template<typename T>
int AVLTree<T>::size(NodeBT<T> *node) {
    if (node == nullptr){
        return 0;
    } else {
        return 1 + size(node->left) + size(node->right);
    }
}

template<typename T>
bool AVLTree<T>::isBalanced(NodeBT<T> *node) { /// TODO
   /* if (node->left == nullptr && node->right == nullptr)
        return true;
    if (balancingFactor(node) > 1 || balancingFactor(node) < -1)
        return false;
    if (node->left != nullptr)
        return isBalanced(node->left);
    if (node->right != nullptr)
        return isBalanced(node->right);*/
}

template<typename T>
void AVLTree<T>::remove(T val, NodeBT<T> *&node) {
    /// TODO
    /*if (size() == 0){
        throw runtime_error("No elements in the Tree");
    } else {
        if(node == nullptr){
            throw runtime_error("Invalid element");
        }
        if(node->data == val){
            if (node->)
        }
        if (val < node->data){
            return find(val, node->left);
        } else {
            return find(val, node->right);
        }
    }*/
}

template<typename T>
void AVLTree<T>::displayInOrder(NodeBT<T> *node) { // Test
    if (node == nullptr)
        throw runtime_error("No elements in the tree");
    if (node->left == nullptr && node->right == nullptr){
        cout << node->data << "\n";
        return;
    }
    vector<T> vec;
    inOrder(vec, node);
    for (size_t i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

template<typename T>
void AVLTree<T>::displayPreOrder(NodeBT<T> *node) { // Test
    if (node == nullptr)
        throw runtime_error("No elements in the tree");
    if (node->left == nullptr && node->right == nullptr){
        cout << node->data << "\n";
        return;
    }
    vector<T> vec;
    preOrder(vec, node);
    for (size_t i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

template<typename T>
void AVLTree<T>::displayPostOrder(NodeBT<T> *node) { // Test
    if (node == nullptr)
        throw runtime_error("No elements in the tree");
    if (node->left == nullptr && node->right == nullptr){
        cout << node->data << "\n";
        return;
    }
    vector<T> vec;
    postOrder(vec, node);
    for (size_t i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << "\n";
}

template<typename T>
void AVLTree<T>::displayBFS(NodeBT<T> *node) {
    queue<NodeBT<T>*> cola;
    cola.push(node);
    while (!cola.empty()){
        NodeBT<T> *nodo = cola.front();
        cola.pop();
        cout << nodo->data << " ";
        if (nodo->left != nullptr)
            cola.push(nodo->left);
        if (nodo->right != nullptr)
            cola.push(nodo->right);
    }
    cout << "\n";
}

template<typename T>
void AVLTree<T>::displayDFS(NodeBT<T> *node) {
    stack<NodeBT<T>*> pila;
    pila.push(node);
    while (!pila.empty()){
        NodeBT<T> *nodo = pila.top();
        pila.pop();
        cout << nodo->data << " ";
        if (nodo->right != nullptr)
            pila.push(nodo->right);
        if (nodo->left != nullptr)
            pila.push(nodo->left);
    }
    cout << "\n";
}


// ADD for AVL
template<typename T>
int AVLTree<T>::balancingFactor(NodeBT<T> *node) {
    return height(node->left) - height(node->right);
}

template<typename T>
void AVLTree<T>::updateHeight(NodeBT<T> *node) {
    node->height = max(height(node->right), height(node->left)) + 1;
}

template<typename T>
void AVLTree<T>::balance(NodeBT<T> *&node) {
    if (balancingFactor(node) >= 2){
        if (balancingFactor(node->left) <= -1)
            left_rota(node->left);
        right_rota(node);
    } else if (balancingFactor(node) <= -2) {
        if (balancingFactor(node->right) >= 1)
            right_rota(node->right);
        left_rota(node);
    }
}

template<typename T>
void AVLTree<T>::left_rota(NodeBT<T> *&node) {
    NodeBT<T> *temp = node->right;
    node->right = temp->left;
    temp->left = node;
    updateHeight(temp);
    updateHeight(node);
    node = temp;
}

template<typename T>
void AVLTree<T>::right_rota(NodeBT<T> *&node) {
    NodeBT<T> *temp = node->left;
    node->left = temp->right;
    temp->right = node;
    updateHeight(temp);
    updateHeight(node);
    node = temp;
}