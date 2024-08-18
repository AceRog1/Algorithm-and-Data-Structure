//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_BTREE_H
#define ALGORITHMANDDATASTRUCTURE_BTREE_H

#include "Node.h"
#include <string>

template<typename TK>
class BTree {
private:
    Node<TK>* root; // Raiz del Arbol
    int M; // Orden del Arbol
    int lenght; // Longitud del Arbol
public:
    explicit BTree(int _M); // Constructor, recive el grado del arbol

    bool search(TK key); // Busqueda
    void insert(TK key); // Insercion
    void insertNonFull(Node<TK>* node, TK key);
    void splitChild(Node<TK>* parent, int i, Node<TK>* fullChild);
    void remove(TK key); // Eliminacion
    void removeFromNode(Node<TK>* node, TK key);
    TK getPred(Node<TK>* node);
    TK getSucc(Node<TK>* node);
    void merge(Node<TK>* node, int idx);
    void fill(Node<TK>* node, int idx);
    void borrowFromPrev(Node<TK>* node, int idx);
    void borrowFromNext(Node<TK>* node, int idx);
    int height(); // Altura
    std::string toString(const std::string& sep); // Recorrido InOrder
    void inOrderTraversal(Node<TK>* node, std::string& result, const std::string& sep);

    TK minKey(); // Minimo Valor del Arbol
    TK maxkey(); // Maximo Valor del Arbol
    void clear(); // Eliminar todos los valores del arbol
    void kill(Node<TK>* node); // Elimina los nodos recursivamente.
    int size(); // Tamanio del arbol
    ~BTree(); // Destructor
};


#endif //ALGORITHMANDDATASTRUCTURE_BTREE_H
