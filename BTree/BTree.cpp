//
// Created by alejandro on 21/10/2023.
//

#include <iostream>
#include "BTree.h"

using namespace std;

template<typename TK>
BTree<TK>::BTree(int _M){
    root = nullptr;
    M = _M;
    lenght = 0;
}

template<typename TK>
bool BTree<TK>::search(TK key){
    Node<TK> *temp = root;
    while(temp != nullptr){
        int i = 0;
        while (i < temp->count && temp->keys[i] < key)
            i++;
        if (i < temp->count && temp->keys[i] == key)
            return true;
        temp = temp->children[i];
    }
    return false;
}

template<typename TK>
void BTree<TK>::insert(TK key) {
    if (root == nullptr) {
        root = new Node<TK>(M);
        root->keys[0] = key;
        root->count = 1;
    } else {
        if (root->count == M - 1) {
            Node<TK>* newRoot = new Node<TK>(M);
            newRoot->children[0] = root;
            newRoot->leaf = false;
            splitChild(newRoot, 0, root);
            root = newRoot;
        }
        insertNonFull(root, key);
    }
    lenght++;
}

template<typename TK>
void BTree<TK>::insertNonFull(Node<TK>* node, TK key) {
    int i = node->count - 1;
    if (node->leaf) {
        // Inserta la nueva clave en el nodo hoja
        while (i >= 0 && node->keys[i] > key) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->count++;
    } else {
        while (i >= 0 && node->keys[i] > key)
            i--;
        i++;
        if (node->children[i]->count == M - 1) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i])
                i++;
        }
        insertNonFull(node->children[i], key);
    }
}

template<typename TK>
void BTree<TK>::splitChild(Node<TK>* parent, int i, Node<TK>* fullChild) {
    int t = M / 2;
    Node<TK>* newChild = new Node<TK>(M);
    newChild->leaf = fullChild->leaf;
    newChild->count = t - 1;
    for (int j = 0; j < t - 1; j++)
        newChild->keys[j] = fullChild->keys[j + t];
    if (!fullChild->leaf) {
        for (int j = 0; j < t; j++)
            newChild->children[j] = fullChild->children[j + t];
    }
    fullChild->count = t - 1;
    for (int j = parent->count; j >= i + 1; j--)
        parent->children[j + 1] = parent->children[j];
    parent->children[i + 1] = newChild;
    for (int j = parent->count - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];
    parent->keys[i] = fullChild->keys[t - 1];
    parent->count++;
}

template<typename TK>
void BTree<TK>::remove(TK key) {
    if (!root)
        throw runtime_error("No elements in the Tree");
    removeFromNode(root, key);
    if (root->count == 0) {
        Node<TK>* tmp = root;
        if (root->leaf)
            root = nullptr;
        else
            root = root->children[0];
        delete tmp;
    }
}

template<typename TK>
void BTree<TK>::removeFromNode(Node<TK>* node, TK key) {
    int idx = 0;
    while (idx < node->count && node->keys[idx] < key)
        ++idx;
    if (idx < node->count && node->keys[idx] == key) {
        if (node->leaf) {
            for (int i = idx + 1; i < node->count; ++i)
                node->keys[i - 1] = node->keys[i];
            node->count--;
        } else {
            if (node->children[idx]->count >= M / 2) {
                TK pred = getPred(node->children[idx]);
                node->keys[idx] = pred;
                removeFromNode(node->children[idx], pred);
            } else if (node->children[idx + 1]->count >= M / 2) {
                TK succ = getSucc(node->children[idx + 1]);
                node->keys[idx] = succ;
                removeFromNode(node->children[idx + 1], succ);
            } else {
                merge(node, idx);
                removeFromNode(node->children[idx], key);
            }
        }
    } else {
        if (node->leaf)
            throw runtime_error("No element in the Tree");
        bool flag = (idx == node->count);
        if (node->children[idx]->count < M / 2)
            fill(node, idx);
        if (flag && idx > node->count)
            removeFromNode(node->children[idx - 1], key);
        else
            removeFromNode(node->children[idx], key);
    }
}

template<typename TK>
TK BTree<TK>::getPred(Node<TK>* node) {
    while (!node->leaf)
        node = node->children[node->count];
    return node->keys[node->count - 1];
}

template<typename TK>
TK BTree<TK>::getSucc(Node<TK>* node) {
    while (!node->leaf)
        node = node->children[0];
    return node->keys[0];
}

template<typename TK>
void BTree<TK>::merge(Node<TK>* node, int idx) {
    Node<TK>* child = node->children[idx];
    Node<TK>* sibling = node->children[idx + 1];
    child->keys[M / 2 - 1] = node->keys[idx];
    for (int i = 0; i < sibling->count; ++i)
        child->keys[i + M / 2] = sibling->keys[i];
    if (!child->leaf) {
        for (int i = 0; i <= sibling->count; ++i)
            child->children[i + M / 2] = sibling->children[i];
    }
    for (int i = idx + 1; i < node->count; ++i)
        node->keys[i - 1] = node->keys[i];
    for (int i = idx + 2; i <= node->count; ++i)
        node->children[i - 1] = node->children[i];
    child->count += sibling->count + 1;
    node->count--;
    delete sibling;
}

template<typename TK>
void BTree<TK>::fill(Node<TK>* node, int idx) {
    if (idx != 0 && node->children[idx - 1]->count >= M / 2)
        borrowFromPrev(node, idx);
    else if (idx != node->count && node->children[idx + 1]->count >= M / 2)
        borrowFromNext(node, idx);
    else {
        if (idx != node->count)
            merge(node, idx);
        else
            merge(node, idx - 1);
    }
}

template<typename TK>
void BTree<TK>::borrowFromPrev(Node<TK>* node, int idx) {
    Node<TK>* child = node->children[idx];
    Node<TK>* sibling = node->children[idx - 1];
    for (int i = child->count - 1; i >= 0; --i)
        child->keys[i + 1] = child->keys[i];
    if (!child->leaf) {
        for (int i = child->count; i >= 0; --i)
            child->children[i + 1] = child->children[i];
    }
    child->keys[0] = node->keys[idx - 1];
    if (!child->leaf)
        child->children[0] = sibling->children[sibling->count];
    node->keys[idx - 1] = sibling->keys[sibling->count - 1];
    child->count++;
    sibling->count--;
}

template<typename TK>
void BTree<TK>::borrowFromNext(Node<TK>* node, int idx) {
    Node<TK>* child = node->children[idx];
    Node<TK>* sibling = node->children[idx + 1];
    child->keys[child->count] = node->keys[idx];
    if (!child->leaf)
        child->children[child->count + 1] = sibling->children[0];
    node->keys[idx] = sibling->keys[0];
    for (int i = 1; i < sibling->count; ++i)
        sibling->keys[i - 1] = sibling->keys[i];
    if (!sibling->leaf) {
        for (int i = 1; i <= sibling->count; ++i)
            sibling->children[i - 1] = sibling->children[i];
    }
    child->count++;
    sibling->count--;
}

template<typename TK>
int BTree<TK>::height() {
    if (root == nullptr)
        return 0;
    int h = 0;
    Node<TK>* temp = root;
    while (!temp->leaf) {
        h++;
        temp = temp->children[0];
    }
    return h + 1;
}

template<typename TK>
std::string BTree<TK>::toString(const std::string& sep) {
    std::string result;
    inOrderTraversal(root, result, sep);
    return result;
}

template<typename TK>
void BTree<TK>::inOrderTraversal(Node<TK>* node, std::string& result, const std::string& sep) {
    if (node != nullptr) {
        int i;
        for (i = 0; i < node->count; i++) {
            if (!node->leaf) {
                inOrderTraversal(node->children[i], result, sep);
            }
            result += std::to_string(node->keys[i]);
            if (i < node->count - 1 || !node->leaf) {
                result += sep;
            }
        }
        if (!node->leaf) {
            inOrderTraversal(node->children[i], result, sep);
        }
    }
}

template<typename TK>
TK BTree<TK>::minKey(){
    Node<TK> *temp = root;
    while (temp->leaf == false)
        temp = temp->children[0];
    return temp->keys[0];
}

template<typename TK>
TK BTree<TK>::maxkey() {
    Node<TK>* temp = root;
    while (!temp->leaf)
        temp = temp->children[temp->count];
    return temp->keys[temp->count - 1];
}


template<typename TK>
void BTree<TK>::clear(){
    kill(root);
    root = nullptr;
    lenght = 0;
}

template<typename TK>
void BTree<TK>::kill(Node<TK>* node) {
    if (node == nullptr) { return; }
    for (int i = 0; i <= node->count; i++)
        kill(node->children[i]);
    node->killSelf();
    delete node;
}

template<typename TK>
int BTree<TK>::size(){
    return lenght;
}

template<typename TK>
BTree<TK>::~BTree(){
    clear();
}