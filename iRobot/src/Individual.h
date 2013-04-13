/*
 * Individual.h
 *
 *  Created on: 11/04/2013
 *      Author: jose
 */

#ifndef INDIVIDUAL_H_
#define INDIVIDUAL_H_
#include "MatrixNode.h"

/**
 * Clase individuo que posee las caracteristicas para poder moverse dentro de una imagen
 */
class Individual
{
private:
	int _row, _column; //Fila y columna actual donde se esta hubicado
	MatrixNode* _goalNode;
	MatrixNode* _currentNode;

public:
	Individual(); //Cpnstructor
	virtual ~Individual(); //Destructor
	int getColumn() const; //Obtener la columna de donde se encuentra en la matriz
	void setColumn(int column); //Define la columna en la matriz
	MatrixNode* getGoal(); //Obtener el nodo de llegada
	void setGoal(MatrixNode* goal); //Definir el nodo de llegada
	int getRow() const; //Obtener la fila de donde se encuentra en la matriz
	void setRow(int row); //Define la columna en la matriz
	MatrixNode* getCurrent(); //Obtener el nodo actual
	void setCurrent(MatrixNode* start); //Definir el nodo actual
};
//Fin de la clase
#endif /* INDIVIDUAL_H_ */
