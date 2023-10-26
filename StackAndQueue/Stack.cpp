//
// Created by alejandro on 21/10/2023.
//

#include "Stack.h"
#include <iostream>

using namespace std;


template<typename T>
Stack<T>::Stack(){ // Constructor del Stack
    length = 0; // Inicializamos el tamanio del stack en 0
    last = nullptr; // el ultimo elemento sera un nullptr, de esta manera el puntero no estara apuntando a cualquier lado
}


template<typename T>
T Stack<T>::top(){ // Muestra el ultimo nodo colocado
    if (empty())
        throw runtime_error("No elements in the stack"); // Si el Stack esta vacio interrumpira el proceso y mandara el mensaje que no hay elementos en el Stack
    return last->data; // En caso no este vacio, retornara la data del ultimo nodo colocado
}

template<typename T>
int Stack<T>::size(){ // El tamanio del Stack
    return length;
}

template<typename T>
void Stack<T>::push(T value){ // Agrega un nodo al Stack
    Node* newNode = new Node(value); // Creamos un nodo, con el nombre newNode y con el valor de value
    if(empty()){
        newNode->next = nullptr; // Si el Stack esta vacio, el next del newNode se volvera nullptr
        last = newNode; // El last apuntaria al nuevo nodo creado
    } else {
        newNode->next = last; // En este caso, si el Stack no esta vacio, el newNode, guardara en next un puntero al last, que fue el anterior nodo colocado
        last = newNode; // El last pasa a apuntar al nuevo nodo agregado.
    }
    length++; // Se aumenta la cantidad de nodos en el Stack
}

template<typename T>
void Stack<T>::pop(){ // Elimina un nodo del Stack
    if(empty()){
        throw runtime_error("No elements in the stack"); // Si el Stack esta vacio, el next del newNode se volvera nullptr
    } else {
        Node* popNode = last; // Creamos un puntero que apuntara al ultimo nodo colocado en el stack
        last = popNode->next; // El puntero last cambiara, es decir, dejara de apuntar al ultimo nodo colocado, y apuntara al siguiente a ese, por ello se igual al next del popNode
        popNode->killself(); // Elimina el popNode con el killself, de esa manera liberamos espacio en memoria
        length--; // El tamanio del Stack se reduce en 1
    }
}

template<typename T>
T Stack<T>::operator[](int position) {
    // TODO
}

template<typename T>
void Stack<T>::showStack(){ // Muestra todos los elementos del Stack, los imprime en consola
    Node* temp = last; // Creamos un puntero temporal, el cual usaremos para recorrer el Stack
    for(int i = 0; i < length; i++){ // usamos un loop for para poder recorrer el Stack de tamanio length
        cout << "Position " << length-i << " : " << temp->data << endl; // imprimimos la posicion del nodo en el stack, y la data que se encuentra en dicho nodo
        temp = temp->next; // Al final del bucle, el puntero temp pasa al siguiente nodo
    }
}

template<typename T>
bool Stack<T>::empty(){ // Verifica si el Stack tiene elementos o no
    if (length == 0){
        return true; // Si es que el manaio del Stack es 0, retornamos true
    } else { return false; } // si no lo es, retornamos false
}

template<typename T>
void Stack<T>::clear(){ // Elimina todos los nodos del Stack y lo limpia al 100%
    for(int i = 0; i < length; i++) // Creamos un contador que aumente hasta que alcance la cantiad de elementos del Stack
        pop(); // eliminamos todos los elementos del Stack
}

template<typename T>
Stack<T>::~Stack(){ // Destructor del Stack
    clear(); // Eliminamos todos los elementos del Stack
}
