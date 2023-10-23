//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_STACK_H
#define ALGORITHMANDDATASTRUCTURE_STACK_H


template<typename T>
class Stack {
private:
    struct Node{
        T data;
        Node* next;
        Node(){
            next = nullptr;
        }
        Node(T value){
            data = value;
            next = nullptr;
        }
        void killself(){
            next = nullptr;
            delete this;
        }
    };
private:
    int length;
    Node* last;
public:
    Stack();
    T top();
    int size();
    void push(T value);
    void pop();
    //T operator [](int position);
    void showStack();
    bool empty();
    void clear();
    ~Stack();
};


#endif //ALGORITHMANDDATASTRUCTURE_STACK_H
