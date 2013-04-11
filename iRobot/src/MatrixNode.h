/*
 * MatrixNode.h
 *
 *  Created on: 21/03/2013
 *      Author: jose
 */

#ifndef MATRIXNODE_H_
#define MATRIXNODE_H_
#include <iostream>
#include <stdlib.h>

/*
 * Clase de nodo en los cuales existe las caracteristicas de la imagen y otros.
 */
class MatrixNode
{
private:
	int _posX; //Posicion de la columna
	int _posY; //Posicion de la fila
	int _color[3]; //Arreglo con los colores RGB
	MatrixNode* _parent; //Nodo padre

public:
	MatrixNode(int x, int y, int Red, int Green, int Blue); //Constructor
	virtual ~MatrixNode(); //Destructor
	int getPosX() const; //Se obtiene la columna
	void setPosX(int posX); //Se define la columna
	int getPosY() const; //Se obtiene la fila
	void setPosY(int posY); //Se define la fila
	int getWeightOfWay(); //Se obtiene el peso del camino
	int* getColor(); // Se obtiene el arreglo de color
	void setParent(MatrixNode*); //Se define el nodo padre
	MatrixNode* getParent(); //Se obtiene el nodo padre
};
//Fin de la clase

#endif /* MATRIXNODE_H_ */
