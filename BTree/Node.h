//
// Created by alejandro on 30/05/2024.
//

#ifndef ALGORITHM_AND_DATA_STRUCTURES_NODE_H
#define ALGORITHM_AND_DATA_STRUCTURES_NODE_H

#endif //ALGORITHM_AND_DATA_STRUCTURES_NODE_H

template<typename TK>
struct Node {
    TK* keys; // Array de llaves
    Node** children; // Array de punteros a Nodos
    int count; // Cuenta de elementos hay
    bool leaf; // Si es hoja o no es hoja, basicamente si es que sus punteros son diferentes a NUll
    Node(){
        keys = nullptr;
        children = nullptr;
        count = 0;
    }
    Node(int M){
        keys = new TK[M-1];
        children = new Node<TK>*[M];
        count = 0;
        leaf = true;
    }
    void killSelf(){
        count = 0;
        delete[] keys;
        delete[] children;
    }
};