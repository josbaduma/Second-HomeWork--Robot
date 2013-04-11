/*
 * ListSatck.cpp
 *
 *  Created on: 03/04/2013
 *      Author: jose
 */
#include <iostream>
#include "ListStack.h"

/**
 * Constructor
 */
template<typename Data>
ListStack<Data>::ListStack()
{
	this->_top = this->_tail = NULL; //Inicializacion en nulo
	this->_length = 0; //Tamaño igual a 0.
}

/**
 * Destructor
 */
template<typename Data>
ListStack<Data>::~ListStack()
{
	free(this->_top); //Libera la memoria
	free(this->_tail); //Libera la memoria
}

template<typename Data>
void ListStack<Data>::push(Data pData)
{
	//Varible nodo para la insercion.
	SimpleNode<Data>* node = new SimpleNode<Data>(pData);

	if (this->_top == NULL)
	{
		node->setNext(this->_top); //Se asigna como siguiente al inicial
		this->_top = node; //Definir como inicial al nodo a insertar
		this->_length++; //Incremento del tamaño
	}
	else
	{
		node->setNext(this->_top); //Definir como siguiente del nodo al inicial
		this->_top = node; //Asignacion del nodo
		this->_length++; //Incremento del tamño
	}
}

template<typename Data>
Data ListStack<Data>::pop()
{
	if (this->_top == NULL)
	{
		//No existe el dato
		return (Data) 0;
	}
	else
	{
		SimpleNode<Data>* tmp = this->_top; //Variable temporal
		Data returnData = tmp->getData(); //Variable temporal del dato
		this->_top = this->_top->getNext(); //Asigna como nodo inicial al siguiente
		free(tmp); //Libera la memoria
		this->_length--; //Reduce el tamaño
		return returnData; //Devolver el dato
	}
}

//Devuelve el valor del dato inicial de la pila
template<typename Data>
Data ListStack<Data>::top()
{
	return this->_top->getData(); //Devolver el dato
}

/**
 * Metodo para la devolucion del tamaño de la lista
 */
template<typename Data>
int ListStack<Data>::Length()
{
	return this->_length;
}

/**
 * Verifica que la lista este vacia
 */
template<typename Data>
bool ListStack<Data>::isEmpty()
{
	return this->_length == 0;
}

/**
 * Metodo de busqueda de un nodo o dato..
 * Devuelve un dato booleano si existe o no.
 */
template<typename Data>
bool ListStack<Data>::search(Data pData)
{
	SimpleNode<Data>* tmp = this->_top; // Nodo temporal
	if (tmp == NULL)
	{ // Caso de no haber ningun nodo
		return false;
	}
	while (tmp->getNext() != NULL && tmp->getData() != pData)
	{ // Recorre la pila hasta encontrar el dato o acabar de recorrer los nodos.
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
