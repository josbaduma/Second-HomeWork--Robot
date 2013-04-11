/*
 * Queue.h
 *
 *  Created on: 14/02/2013
 *      Author: jose
 */

#ifndef QUEUE_H_
#define QUEUE_H_


template<typename E>
class Queue {

public:
	Queue() {
	}// Constructor

	virtual ~Queue() {
	} // Destructor

	// Limpia la cola eliminando todos sus elementos.
	virtual void clear() = 0;

	// Inserta al final los datos encolandolos.
	virtual void enqueue(const E&) = 0;

	// Elimina el primer elemento de la cola.
	virtual E dequeue() = 0;

	// Devuelve el tamaño de la cola.
	virtual int length() const = 0;
};
#endif /* QUEUE_H_ */
