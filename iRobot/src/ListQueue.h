/*
 * ListQueue.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef LISTQUEUE_H_
#define LISTQUEUE_H_
#include "Queue.h"
#include "SimpleNode.h"
#include <iostream>
#include <stdlib.h>

/*
 * Clase de una estructura Cola
 * Es una clase con plantila.
 */
template<typename Data>
class ListQueue: public Queue<Data> {
private:
	SimpleNode<Data> * _top; // Puntero al primer nodo.
	SimpleNode<Data> * _tail; // Puntero al ultimo nodo.
	int _size; // Numero de elementos en la cola.

public:
	ListQueue(); //Constructor
	virtual ~ListQueue(); //Destructor
	void clear(); //Elimina todos los datos de la cola
	void enqueue(const Data& pData); //Inserta datos al final
	Data dequeue(); //Elimina al inicio de la cola
	int length() const; //Muestra el tamaño de la cola
	bool search(Data); //Busca un dato especifico
	bool isEmpty(); //Muestra si esta vacia.
};

#endif /* LISTQUEUE_H_ */
