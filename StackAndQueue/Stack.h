//
// Created by alejandro on 21/10/2023.
//

#ifndef ALGORITHMANDDATASTRUCTURE_STACK_H
#define ALGORITHMANDDATASTRUCTURE_STACK_H


template<typename T> // Usamos Template para permitir que el usuario use la estructura de datos con cualquier tipo de variable
class Stack {
private:
    struct Node{ // Para crear el Stack, y evitar usar un Array, creamos Nodos
        T data; // En esta variable se almacena la informacion que guardaremos en el Stack
        Node* next; // El nodo tendra un puntero hacia el siguiente nodo, para no perder ninguno, de esa manera todos estaran conectados
        Node(){ // El constructor del nodo inicializa el puntero next en nullptr
            next = nullptr;
        }
        explicit Node(T value){ // Este constructor tiene como parametro el value, con el cual iniciaremos el nodo con la data y con el puntero a nullptr
            data = value;
            next = nullptr;
        }
        void killself(){ // Este parametro eliminara el nodo por completo, con el delete this
            next = nullptr;
            delete this;
        }
    };
private:
    int length; // Se usa para saber cual es la cantidad de nodos que tiene el stack creado
    Node* last; // Un puntero que seniala el ultimo nodo que se coloco en el stack
public:
    Stack(); // Constructor del Stack
    T top(); // Muestra el ultimo nodo colocado
    int size(); // El tamanio del Stack
    void push(T value); // Agrega un nodo al Stack
    void pop(); // Elimina un nodo del Stack
    T operator [](int position);
    void showStack(); // Muestra todos los elementos del Stack, los imprime en consola
    bool empty(); // Verifica si el Stack tiene elementos o no
    void clear(); // Elimina todos los nodos del Stack y lo limpia al 100%
    ~Stack(); // Destructor del Stack
};


#endif //ALGORITHMANDDATASTRUCTURE_STACK_H
