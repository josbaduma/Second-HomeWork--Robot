/*
 * ListQueue.cpp
 *
 *  Created on: 03/04/2013
 *      Author: jose
 */
#include "ListQueue.h"

/**
 * Constructor
 */
template<typename Data>
ListQueue<Data>::ListQueue()
{
	this->_top = this->_tail = NULL; //Asignar un puntero nulo
	this->_size = 0; //Tamaño igual 0.
}

/**
 * Destructor
 */
template<typename Data>
ListQueue<Data>::~ListQueue()
{
	clear(); //Limpia la lista
	delete this->_top; //Libera memria
	delete this->_tail; //Libera memoria
}

/**
 * Metodo para la limpieza de la lista.
 * Libera todos los nodos
 */
template<typename Data>
void ListQueue<Data>::clear()
{ // Limpia la cola
	while (this->_top != NULL)
	{ // Elimina todos los nodos.
		this->_tail = this->_top;
		delete this->_tail;
	}
	this->_tail = this->_top = NULL;
	this->_size = 0;
}

/**
 * Insertar al final de la cola un dato.
 */
template<typename Data>
void ListQueue<Data>::enqueue(const Data& pData)
{
	SimpleNode<Data> * nNode = new SimpleNode<Data>(pData, NULL); //Nodo a insertar
	//Verifica si la cola esta vacia
	if (this->_top == NULL)
	{
		this->_top = this->_tail = nNode;	//Asignacion del nodo
		this->_size++;	//Incremento del tamaño
	}
	else
	{
		_tail->setNext(nNode);//Se define como nodo siguiente al nodo a insertar
		_tail = nNode;	//Se asigna como nodo final
		this->_size++;	//Incremento del tamaño
	}
}

/**
 * Desencola, este elimina el nodo inicial y devuelve el valor del dato.
 */
template<typename Data>
Data ListQueue<Data>::dequeue()
{
	if (this->_top == NULL)
	{
		//La cola esta vacia
		return (Data) 0;
	}
	else
	{
		SimpleNode<Data>* tmp = this->_top; //Variable temporal
		Data returnData = tmp->getData(); //Variable temporal del dato
		//El nodo inicial se mueve al siguiente nodo
		this->_top = this->_top->getNext();
		//Verifica si esta vacia
		if (this->_top == NULL)
		{
			this->_top = this->_tail = NULL;		//Apunta a nulo
		}
		free(tmp);		//Libera la memoria
		this->_size--;		//Reducir el tamaño
		return returnData;		//Devolver el dato
	}
}

/**
 * Devuelve el tamaño de la cola
 */
template<typename Data>
int ListQueue<Data>::length() const
{
	return this->_size;
}

template<typename Data>
bool ListQueue<Data>::search(Data pData)
{
	SimpleNode<Data>* tmp = this->_top; // Nodo temporal
	if (tmp == NULL)
	{ // Caso de no haber ningun nodo
		return false;
	}
	while (tmp->getNext() != NULL && tmp->getData() != pData)
	{ // Recorre la cola hasta encontrar el dato o acabar de recorrer los nodos.
		tmp = tmp->getNext();
	}
	if (tmp->getData() == pData)
	{ // Encontro el dato.
		return true;
	}
	else
	{ //No se pudo encontrar el dato.
		return false;
	}
}

/**
 * Verifica que la cola este vacia o no.
 * Devuelve un valor booleano.
 */
template<typename Data>
bool ListQueue<Data>::isEmpty()
{
	return this->_size == 0;
}

