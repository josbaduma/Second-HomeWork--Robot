/*
 * SimpleList.h
 *
 *  Created on: 20/03/2013
 *      Author: jose
 */

#ifndef SIMPLELIST_H_
#define SIMPLELIST_H_

#include "ListADT.h"
#include "SimpleNode.h"
#include "SimpleNode.cpp"
#include <stdlib.h>

/*
 * Clase de la lista simple enlazada
 * Utilizando nodos y es una clase con
 * plantillas.
 */
template<typename Data>
class SimpleList: public ListADT<Data> {
private:
	SimpleNode<Data>* _head; //Nodo incial de la lista
	SimpleNode<Data>* _tail; //Nodo final de la lista
	int _length; //Tamaño de la lista

public:
	SimpleList(); //Constructor
	virtual ~SimpleList(); //Destructor
	void insertFinal(const Data&); //Insercion al final de la lista
	void insertBegin(const Data&);  //Insercion al inicio de la lista
	void insertInOrder(const Data&); //Insercion en orden
	Data deleteFinal(); //Borrado del ultimo nodo
	Data deleteSpecific(const Data&); //Borrado de un nodo especifico
	Data deleteFirst(); //Borrado del primer nodo
	int length() const; //Devuelve el tamaño de la lista
	bool isEmpty(); //Indica si la lista esta vacia.
	bool search(const Data& pData); //Busca un nodo especifico
	Data get(int i); //Obtiene un dato por su indice
	void clear(); // Limpia la lista
};
#endif /* SIMPLELIST_H_ */
