/*
 * Individual.cpp
 *
 *  Created on: 11/04/2013
 *      Author: jose
 */

#include "Individual.h"

/**
 * Constructo
 */
Individual::Individual()
{
	this->_goalNode = this->_currentNode = NULL;
	this->_row = this->_column = 0;
}

/**
 * Se obtiene el numero de columna en la cual se encuentra actualmente el individuo
 */
int Individual::getColumn() const
{
	return _column;
}

/**
 * Define la columna en la cual se encuentre el individuo
 */
void Individual::setColumn(int column)
{
	_column = column;
}

/**
 * Se obtiene el nodo de  llegada
 */
MatrixNode* Individual::getGoal()
{
	return _goalNode;
}

/**
 * Se define el nodo de llegada
 */
void Individual::setGoal( MatrixNode* goal)
{
	_goalNode = goal;
}

/**
 * Se obtiene la fila en la cual se encuentra el individuo
 */
int Individual::getRow() const
{
	return _row;
}

/**
 * Se define la fila en la cual se encuentra el individuo
 */
void Individual::setRow(int row)
{
	_row = row;
}

/**
 * Se obtiene el nodo actual
 */
MatrixNode* Individual::getCurrent()
{
	return _currentNode;
}

/**
 * Se define el nodo actual
 */
void Individual::setCurrent(MatrixNode* pNode)
{
	_currentNode = pNode;
}

/**
 * Destructor
 */
Individual::~Individual()
{
	free(this->_currentNode);
	free(this->_goalNode);
}

