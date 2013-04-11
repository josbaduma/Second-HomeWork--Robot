/*
 * SimpleNode.cpp
 *
 *  Created on: 03/04/2013
 *      Author: jose
 */
#include "SimpleNode.h"

/*
 * Constructor de la clase Nodo Simple Enlazado
 */
template<typename E>
SimpleNode<E>::SimpleNode(const E& pData, SimpleNode* pNextNode = NULL)
{
	this->_data = pData; //Se asigna el dato
	this->_next = pNextNode; //Se asigna el nodo siguiente
}

/*
 * Constructor de la clase secundario
 */
template<typename E>
SimpleNode<E>::SimpleNode(SimpleNode* pNextNode = NULL)
{
	this->_data = 0; //Dato seria nulo
	this->_next = pNextNode; //Se define el nodo siguiente
}

/*
 * Destructor de la clase
 */
template<typename E>
SimpleNode<E>::~SimpleNode()
{
	free(this->_next); //Libera la memoria del nodo siguiente
}

/*
 *Funcion que define el nodo siguiente
 */
template<typename E>
void SimpleNode<E>::setNext(SimpleNode* pNode)
{
	this->_next = pNode; //Asignacion del nodo
}

/*
 * Funcion para obtener el nodo siguiente
 */
template<typename E>
SimpleNode<E> * SimpleNode<E>::getNext()
{
	return this->_next; //Devolver el nodo siguiente
}

/**
 * Se obtiene el dato almacenado en el nodo
 */
template<typename E>
E SimpleNode<E>::getData()
{
	return this->_data; //Devolver el dato
}
