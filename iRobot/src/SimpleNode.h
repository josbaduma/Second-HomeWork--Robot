/*
 * SNode.h
 *
 *  Created on: 23/02/2013
 *      Author: jose
 */

#ifndef SIMPLENODE_H_
#define SIMPLENODE_H_

#include <iostream>
#include <stdlib.h>

template<typename E>
class SimpleNode
{
private:
	E _data;
	// Valor del nodo.
	SimpleNode *_next;
	// Puntero al nodo siguiente.
public:
	SimpleNode(const E& pData, SimpleNode* pNextNode); //Constructor
	SimpleNode(SimpleNode* pNextNode); //Constructor secundario
	virtual ~SimpleNode(); //Destructor
	void setNext(SimpleNode* pNode); //Define el nodo siguiente
	SimpleNode * getNext(); //Se obtiene el nodo siguiente
	E getData(); //Se obtiene el dato
};

#endif /* SIMPLENODE_H_ */
