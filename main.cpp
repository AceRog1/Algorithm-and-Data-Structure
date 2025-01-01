//
// Created by alejandro on 21/10/2023.
//

#include <iostream>

#include"BST&AVL/AVLTree.h"
#include"BST&AVL/AVLTree.cpp"

using namespace std;

int main(){

    AVLTree<int> *avl = new AVLTree<int>();

    avl->insert(35);
    avl->insert(30);
    avl->insert(27);
    avl->insert(11);
    avl->insert(16);
    avl->insert(100);
    avl->insert(50);
    avl->insert(91);
    avl->insert(73);

    avl->displayInOrder();

    avl->remove(11);
    avl->remove(27);
    avl->remove(91);
    avl->remove(73);

    avl->displayInOrder();
    std::cout << avl->height();




    /*AVLTree<int> tree;

    tree.insert(7);
    tree.insert(4);
    tree.insert(10);
    tree.insert(8);
    tree.insert(15);
    tree.insert(85);

    cout << tree.maxValue() << endl;
    cout << tree.minValue() << endl;
    cout << tree.find(10) << endl;

    //cout << tree.size() << endl;

    //cout << tree.isBalanced() << endl;

    tree.displayBFS();
    tree.displayDFS();*/

    return 0;
}