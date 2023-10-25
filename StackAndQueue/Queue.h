//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_QUEUE_H
#define ALGORITHMANDDATASTRUCTURE_QUEUE_H

template<typename T>
class Queue {
private:
    struct Node{
        T data;
        __attribute__((unused)) Node* next;
        Node* prev;
        Node(){
            next = nullptr;
            prev = nullptr;
        }
        explicit Node(T value){
            data = value;
            next = nullptr;
            prev = nullptr;
        }
        void killSelf(){
            next = nullptr;
            prev = nullptr;
            delete this;
        }
    };
private:
    int length;
    Node* head;
    Node* tale;
public:
    Queue();
    int size();
    bool empty();
    T front();
    T back();
    void push(T value);
    void pop();
    //void printQueue();
    void clear();
    ~Queue();
};


#endif //ALGORITHMANDDATASTRUCTURE_QUEUE_H
