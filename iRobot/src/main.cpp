/*
 * main_2.cpp
 *
 *  Created on: 16/03/2013
 *      Author: jose
 */

#include "PathFinding.h"
#include "SimpleList.h"
#include <stdlib.h>
#include <stdio.h>

using namespace std;

int LENGHTX = 20;
int LENGHTY = 20;

MatrixNode** matriz;

int getColor(int);

int main(int argc, char **argv)
{
	srand(time(NULL));
	matriz = new MatrixNode*[LENGHTX * LENGHTY];
	for (int i = 0; i < LENGHTY; ++i)
	{
		for (int j = 0; j < LENGHTX; ++j)
		{
			int r = getColor(rand() % 255);
			int g = getColor(rand() % 255);
			int b = getColor(rand() % 255);
			cout << "Rojo: " << r << " Verde: " << g << " Azul: " << b << endl;
			matriz[j + (LENGHTX * i)] = new MatrixNode(j, i, r, g, b);
		}
	}

	MatrixNode* start = matriz[0 + (0 * LENGHTX)];
	MatrixNode* goal = matriz[17 + (12 * LENGHTX)];

	PathFinding* pathfinding = new PathFinding(matriz, LENGHTX, LENGHTY);

	cout << "Ejecutando" << endl;

	//SimpleList<MatrixNode*> * list = pathfinding->DistanceFirstSearch(start, goal);
	SimpleList<MatrixNode*> * list = pathfinding->AlgoritmInvented(start,goal);

	cout << list->length() << endl;
	int tmp = list->length();

	for (int i = 0; i < tmp; ++i) {
		MatrixNode* tmp2 = list->deleteFinal();
		cout << tmp2->getPosY() << "," << tmp2->getPosX() << endl;
	}
	cout << tmp << endl;

	return 0;
}

int getColor(int color) {
	if (color < 32) {
		return 0;
	} else if (color >= 32 && color < 64) {
		return 1;
	} else if (color >= 64 && color < 96) {
		return 2;
	} else if (color >= 96 && color < 128) {
		return 3;
	} else if (color >= 128 && color < 160) {
		return 4;
	} else if (color >= 160 && color < 192) {
		return 5;
	} else if (color >= 192 && color < 224) {
		return 6;
	} else {
		return 7;
	}
}
