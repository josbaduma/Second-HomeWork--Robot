/*
 * ImageVideoDetection.h
 *
 *  Created on: 16/03/2013
 *      Author: jose
 */

#ifndef IMAGEVIDEODETECTION_H_
#define IMAGEVIDEODETECTION_H_

#include <cv.h>
#include <highgui.h>
#include "MatrixNode.h"
#include <stdlib.h>

using namespace std;
using namespace cv;

class ImageVideoDetection {

private:
	MatrixNode* *_graph; //Matriz de nodos.

public:
	ImageVideoDetection(); //Constructor
	virtual ~ImageVideoDetection(); //Destructor
	void matrixImage(IplImage* img); //Obtiene la matriz de la imagen dada
	void videoMatrix(int pCamara); //Proceso para obtener una matriz a partir de la camara
	int getColor(int); //Limitador de colores
	void reconstructImage(int, int); //Reconstrucción de la imagen a partir de la matriz.
};

#endif /* IMAGEVIDEODETECTION_H_ */
