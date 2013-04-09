/*
 * MatrixNode.cpp
 *
 *  Created on: 21/03/2013
 *      Author: jose
 */

#include "MatrixNode.h"

MatrixNode::MatrixNode(int x, int y, int Red, int Green, int Blue) {
	this->_posX = x;
	this->_posY = y;
	this->_color[0] = Red;
	this->_color[1] = Green;
	this->_color[2] = Blue;
	this->_parent = NULL;
}

MatrixNode::~MatrixNode() {
	free(this->_parent);
}

int MatrixNode::getPosX() const {
	return this->_posX;
}

void MatrixNode::setPosX(int posX) {
	this->_posX = posX;
}

int MatrixNode::getPosY() const {
	return this->_posY;
}

void MatrixNode::setPosY(int posY) {
	this->_posY = posY;
}

int MatrixNode::getWeightOfWay() {
	int tmp = (this->_color[0] + this->_color[1] + this->_color[2]);
	return tmp;
}

int* MatrixNode::getColor() {
	return this->_color;
}

void MatrixNode::setParent(MatrixNode* pNode) {
	this->_parent = pNode;
}

MatrixNode* MatrixNode::getParent() {
	return this->_parent;
}
