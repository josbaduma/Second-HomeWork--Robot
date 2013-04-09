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

class MatrixNode {
private:
	int _posX;
	int _posY;
	int _color[3];
	MatrixNode* _parent;

public:
	MatrixNode(int x, int y, int Red, int Green, int Blue);
	virtual ~MatrixNode();
	int getPosX() const;
	void setPosX(int posX);
	int getPosY() const;
	void setPosY(int posY);
	int getWeightOfWay();
	int* getColor();
	void setParent(MatrixNode*);
	MatrixNode* getParent();
};

#endif /* MATRIXNODE_H_ */
