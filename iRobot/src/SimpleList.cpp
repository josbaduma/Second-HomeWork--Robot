/*
 * SimpleList.cpp
 *
 *  Created on: 03/04/2013
 *      Author: jose
 */
#include "SimpleList.h"

/**
 * Constructor de la clase Lista Simple Enlazada
 */
template<typename Data>
SimpleList<Data>::SimpleList()
{
	//Se inicializa los punteros en nulo
	this->_head = this->_tail = NULL;
	//Tamaño de la lista iniciando es igual a 0.
	this->_length = 0;
}

//Destructor de la clase
template<typename Data>
SimpleList<Data>::~SimpleList()
{
	clear(); //Limpia la lista
	free(this->_head); //Libera la memoria
	free(this->_tail); //Libera la memoria
}

/**
 * Funcion para insertar un dato al final de la lista
 * @param Data
 */
template<typename Data>
void SimpleList<Data>::insertFinal(const Data& pData)
{
	SimpleNode<Data>* node = new SimpleNode<Data>(pData); //Inicializacion del nodo
	if (this->_head == NULL) //Verificar si esta vacia
	{
		this->_head = this->_tail = node; //Asignacion del nodo
		this->_length++; //Incremento al tamaño de la lista
	}
	else
	{
		//Añadir el nodo al final
		this->_tail->setNext(node);
		//Indicar que el nodo sera el ultimo dato
		this->_tail = node;
		//Incremento al tamaño de la lista
		this->_length++;
	}
}

/**
 * Funcion de insercion de un dato al inicio de la lista enlazada
 * @param Data
 */
template<typename Data>
void SimpleList<Data>::insertBegin(const Data& pData)
{
	SimpleNode<Data>* nNodo = new SimpleNode<Data>(pData); //Inicializacion del nodo
	if (this->_head == NULL) //Verificar si esta vacia la lista
	{
		//Asignar el nodo al inicio y al final
		this->_head = this->_tail = nNodo;
		//Incremento en el taamaño de la lista
		this->_length++;
	}
	else
	{
		//Asignacion del nodo siguiente
		nNodo->setNext(this->_head);
		//Definir el inicio como el nuevo nodo
		this->_head = nNodo;
		//Incremento en el tamaño de la lista
		this->_length++;
	}
}

/**
 *Funcion para la insercion en orden de los datos en la lista
 *@Param Data
 */
template<typename Data>
void SimpleList<Data>::insertInOrder(const Data& pData)
{
	SimpleNode<Data>* nNodo = new SimpleNode<Data>(pData); //Inicializacion del nodo
	if (this->_head == NULL) //Verifica si la lista esta vacia
	{
		this->_head = this->_tail = nNodo; //Se asigna el nodo
		this->_length++; //Incremento del tamaño
	}
	else if (this->_head->getData() > pData) //Caso de ser un dato menor al dato del nodo inicial
	{
		nNodo->setNext(this->_head); //Se define el siguiente nodo
		this->_head = nNodo; //Asignacion del nodo como nodo inicial
		this->_length++; //Incremento en el tamaño
	}
	else
	{
		SimpleNode<Data>* tmp = this->_head; //Variable temporal
		while (tmp->getNext() != NULL && tmp->getNext()->getData() < pData) //Ciclo en busqueda de la posicion a insertar
		{
			tmp = tmp->getNext(); //Movimiento de referencia
		}
		if (tmp->getNext() == NULL) //Verificar si es el ultimo dato
		{
			this->_tail = nNodo; //Definir el ultimo nodo
		}
		nNodo->setNext(tmp->getNext()); //Se asigna el nodo siguiente
		tmp->setNext(nNodo); //Se define como nodo siguiente al nodo a insertat
		this->_length++; //Incremente en el tamaño
	}
}

/*
 * Metodo para la eliminacion de datos que se encuentren al final de la lista.
 */
template<typename Data>
Data SimpleList<Data>::deleteFinal()
{
	//Verifica si la lista esta vacia.
	if (this->_head == NULL)
	{
		return (Data) 0;
	}
	//Verfica si solamente hay un dato almacenado
	else if (this->_head == this->_tail)
	{
		Data tmp = this->_head->getData(); //Dato en variable temporal
		free(this->_head); //Libera la memoria
		this->_head = this->_tail = NULL; //Asigna un puntero nulo
		this->_length--; //Reduce el tamaño
		return tmp; //Devuelve el dato
	}
	else
	{
		//Variable temporal
		SimpleNode<Data>* tmp = this->_head;
		while (tmp->getNext() != this->_tail) //Ciclo para recorrer la lista hasta el final
		{
			tmp = tmp->getNext();
		}
		Data tmpReturn = tmp->getNext()->getData(); //Variable temporal
		free(tmp->getNext()); //Libera la memoria del nodo temporal
		tmp->setNext(NULL); //Define nulo el nodo siguiente
		this->_tail = tmp; //Define como ultimo nodo al temporal
		this->_length--; //Reduce el tamaño
		return tmpReturn; //Devuelve el dato
	}
}

/*
 * Devuelve el tamaño de la lista
 */
template<typename Data>
int SimpleList<Data>::length() const
{
	return this->_length;
}

/**
 * Verificacion si la lista esta vacia.
 */
template<typename Data>
bool SimpleList<Data>::isEmpty()
{
	return this->_length == 0;
}

/**
 * Se obtiene un dato en la lista en una posicion dada.
 * @param indice
 */
template<typename Data>
Data SimpleList<Data>::get(int i)
{
	if (i >= this->_length) //Verica si el indice es correcto
	{
		return (Data) 0;
	}
	SimpleNode<Data>* tmp = this->_head; //Define una variable temporal
	int index = 0; //Indice para moverse en la lista
	while (index < i) //Ciclo de busqueda
	{
		index++; //Incremento en el indice
		tmp = tmp->getNext(); //Movimiento de referencias
	}
	return tmp->getData(); //Devuelve el dato
}

/**
 * Busqueda de un dato especifico en la lista
 * Devuelve un valor booleano
 */
template<typename Data>
bool SimpleList<Data>::search(const Data& pData)
{
	SimpleNode<Data>* tmp = this->_head; //Variable temporal
	if (tmp == NULL) //Verifica si la lista esta vacia
	{
		return false;
	}
	while (tmp->getNext() != NULL && tmp->getData() != pData) //Ciclo de busqueda
	{
		tmp = tmp->getNext(); //Movimiento de referencias
	}
	if (tmp->getData() == pData) //Si existe el dato
	{
		return true;
	}
	else //No existe el dato
	{
		return false;
	}
}

/**
 * Borrar un dato en una posicion especifica mediante un dato que se da.
 * Devuelve el valor del dato.
 */
template<typename Data>
Data SimpleList<Data>::deleteSpecific(const Data& pData)
{
	//Verifica en caso de estar vacia la lista
	if (this->_head == NULL)
	{
		return (Data) 0;
	}
	SimpleNode<Data>* tmp = this->_head; //Variable temporal
	while (tmp->getNext() != NULL && tmp->getNext()->getData() != pData) //Ciclo de busqueda
	{
		tmp = tmp->getNext(); //Movimiento de referencias
	}
	//Verifica si es el primer nodo y que sea el dato a eliminar
	if (tmp == this->_head && tmp->getData() == pData)
	{
		Data returnData = tmp->getData(); //Variable temporal
		free(tmp); //Libera la memoria
		this->_head = NULL; //Nodo inicial apunta a nulo
		this->_length--; //Reduce el tamaño
		return returnData; //Devuelve el tamaño
	}
	//Verifica si el dato corresponde al nodo
	else if (tmp->getNext()->getData() == pData)
	{
		if (tmp->getNext() == _tail) //Verificar si es el ultimo elemento
		{
			//Veriable temporal
			Data returnData = tmp->getNext()->getData();
			//Libera la memoria
			free(tmp->getNext());
			//Asigna como ultimo nodo al temporal
			this->_tail = tmp;
			//Se define como siguiente a nulo
			tmp->setNext(NULL);
			this->_length--; //Reducir el tamaño
			return returnData; //Devolver el dato
		}
		else
		{
			Data returnData = tmp->getNext()->getData(); //Variable temporal
			SimpleNode<Data>* tmp_2 = tmp->getNext()->getNext(); //Segundo temporal para la asignacion
			free(tmp->getNext()); //Libera la memoria
			tmp->setNext(tmp_2); //Se define como siguiente al segundo temporal
			this->_length--; //Reduccion del tamaño
			return returnData; //Devolver el dato
		}
	}
	else
	{
		//No existe el dato
		return (Data) 0;
	}
}

//Metodo para eliminar el primer nodo de la lista
template<typename Data>
Data SimpleList<Data>::deleteFirst()
{
	Data returnData; //Variable temporal del dato
	SimpleNode<Data>* tmp; //Variable temporal del nodo
	if (this->_head == NULL) //Verifica si esta vacia la lista
	{
		return (Data) 0;
	}
	else
	{
		if (this->_head == this->_tail) //Caso de ser el mismo nodo inicial y final
		{
			returnData = this->_head->getData(); //Dato del nodo a borrar
			free(this->_head); //Liberar la memoria
			this->_head = this->_tail = NULL; //Define como punteros nulos
			return returnData; //Devuelve el dato
		}
		else
		{
			tmp = this->_head; //Variable temporal como el primer nodo
			returnData = this->_head->getData(); //Valor del dato a borrar
			this->_head = this->_head->getNext(); //Asigna como inicial al siguiente nodo
			free(tmp); //Libera la memoria
			return returnData; //Devuelve el dato.
		}
	}
}

/**
 * Metodo para limpiar la lista.
 * Elimina todos los nodos.
 */
template<typename Data>
void SimpleList<Data>::clear()
{ // Elimina todos los nodos.
	while (this->_head->getNext() != NULL)
	{
		this->_tail = this->_head;
		free(this->_tail); // Libera memoria
	}
	this->_tail = this->_head = NULL; //Define nulo los nodos inicial y final
	this->_length = 0; //Define el tamaño en 0.
}

