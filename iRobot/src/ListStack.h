/*
 * ListStack.h
 *
 *  Created on: 28/03/2013
 *      Author: jose
 */

#ifndef LISTSTACK_H_
#define LISTSTACK_H_

#include "SimpleNode.h"

template<typename Data>
class ListStack
{
private:
	SimpleNode<Data>* _top, *_tail; //Nodos final e inicial
	int _length; //Tamaño de la pila

public:
	ListStack(); //Constructor
	virtual ~ListStack(); //Destructor
	void push(Data); //Insercion en la pila
	Data pop(); //Elimina el dato inicial
	Data top(); //Se obtiene el dato inicial
	int Length(); //Se obtiene el tamaño de la pila
	bool isEmpty(); //Verifica si esta vacio
	bool search(Data); //Busca un dato
};
//Fin de la clase
#endif /* LISTSTACK_H_ */
