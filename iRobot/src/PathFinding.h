/*
 * PathFinding.h
 *
 *  Created on: 04/04/2013
 *      Author: jose
 */

#ifndef PATHFINDING_H_
#define PATHFINDING_H_

/**
 * Librerias incluidas
 */
#include "MatrixNode.h"
#include "SimpleList.h"
#include "SimpleList.cpp"
#include "ListQueue.h"
#include "ListQueue.cpp"
#include "ListStack.h"
#include "ListStack.cpp"
#include <stdio.h>

//Clase de busqueda de camino dentro de una matriz
class PathFinding {
	int _lengthX, _lengthY; //Dimensiones de la matriz
	MatrixNode** _graph; //Matriz de nodos

public:
	PathFinding(MatrixNode**, int, int); //Constructor
	virtual ~PathFinding(); //Destructor

	SimpleList<MatrixNode*>* AStar(MatrixNode*, MatrixNode*); // Busqueda de camino Algoritmo A*
	int h(MatrixNode*, MatrixNode*); //Funcion heuristica

	SimpleList<MatrixNode*>* BreadthFirstSearch(MatrixNode*, MatrixNode*); //Algoritmo de recorrido en anchura

	SimpleList<MatrixNode*>* DistanceFirstSearch(MatrixNode*, MatrixNode*); //Algoritmo de recorrido en distancia

	SimpleList<MatrixNode*>* RandomBounce(MatrixNode*, MatrixNode*); //Algoritmo de busqueda de camino random
	int getRandom(int, int); //Funcion random

	SimpleList<MatrixNode*>* ObjectTracing(MatrixNode*, MatrixNode*); //Algoritmo de busqueda por seguimiento

	SimpleList<MatrixNode*>* reconstructWay(SimpleList<MatrixNode*>*,
			MatrixNode*); //Reconstruccion del camino
};
//Fin de la clase

#endif /* PATHFINDING_H_ */
