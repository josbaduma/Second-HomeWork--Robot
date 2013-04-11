/*
 * ListADT.h
 *
 *  Created on: 03/04/2013
 *      Author: jose
 */

#ifndef LISTADT_H_
#define LISTADT_H_

template<typename Data>
class ListADT {
public:
	ListADT(){} //Constructor
	virtual ~ListADT(){} //Destructor

	// Limpia la cola eliminando todos sus elementos.
	virtual void clear() = 0;

	// Inserta al final los datos encolandolos.
	virtual void insertFinal(const Data&) = 0;

	//Inserta al inicio de la lista
	virtual void insertBegin(const Data&) = 0;

	//Inserta en orden en la lista
	virtual void insertInOrder(const Data&) = 0;

	// Elimina el primer elemento de la lista.
	virtual Data deleteFirst() = 0;

	//Elimina un nodo especifico
	virtual Data deleteSpecific(const Data&) = 0;

	//Elimina el nodo final
	virtual Data deleteFinal() = 0;

	// Devuelve el tamaño de la cola.
	virtual int length() const = 0;
};

#endif /* LISTADT_H_ */
