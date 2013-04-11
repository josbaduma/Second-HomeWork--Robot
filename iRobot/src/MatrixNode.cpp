/*
 * MatrixNode.cpp
 *
 *  Created on: 21/03/2013
 *      Author: jose
 */

#include "MatrixNode.h"

/*
 * Constructor de la clase MatrizNode
 */
MatrixNode::MatrixNode(int x, int y, int Red, int Green, int Blue)
{
	this->_posX = x; //Columna en la matriz
	this->_posY = y; //Fila en la matriz
	this->_color[0] = Red; //Color rojo
	this->_color[1] = Green; //Color verde
	this->_color[2] = Blue; //Color azul
	this->_parent = NULL; //Nodo padre
}

/*
 * Destructor de la clase
 */
MatrixNode::~MatrixNode()
{
	free(this->_color); //Se libera la memoria del arreglo
	free(this->_parent); //Se libera la memoria del nodo padre
}

/*
 * Se obtiene la posicion en la columna de la matriz
 */
int MatrixNode::getPosX() const
{
	return this->_posX;
}

/*
 * Se odefine la posicion en la columna de la matriz
 */
void MatrixNode::setPosX(int posX)
{
	this->_posX = posX;
}

/*
 * Se obtiene la posicion en la fila de la matriz
 */
int MatrixNode::getPosY() const
{
	return this->_posY;
}

/*
 * Se define la posicion en la fila de la matriz
 */
void MatrixNode::setPosY(int posY)
{
	this->_posY = posY;
}

/*
 * Obtencion del peso del nodo
 */
int MatrixNode::getWeightOfWay()
{
	int tmp = (this->_color[0] + this->_color[1] + this->_color[2]);
	return tmp;
}

/*
 * Se obtiene el arreglo de colores
 */
int* MatrixNode::getColor()
{
	return this->_color;
}

/*
 * Se define el padre del nodo actual
 */
void MatrixNode::setParent(MatrixNode* pNode)
{
	this->_parent = pNode;
}

/*
 * Se obtiene el nodo padre del actual nodo
 */
MatrixNode* MatrixNode::getParent()
{
	return this->_parent;
}
