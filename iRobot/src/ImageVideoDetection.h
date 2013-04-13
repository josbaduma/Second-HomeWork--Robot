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

/*
 *Clase para la deteccion de colores
 *Muestra una matriz en caso de imagen o video
 */
class ImageVideoDetection
{

private:
	MatrixNode* *_graph; //Matriz de nodos.
	int _lengthX, _lengthY; //Tamaño de la matriz

public:
	ImageVideoDetection(); //Constructor
	virtual ~ImageVideoDetection(); //Destructor
	void matrixImage(IplImage* img); //Obtiene la matriz de la imagen dada
	void videoMatrix(int pCamara); //Proceso para obtener una matriz a partir de la camara
	int getColor(int); //Limitador de colores
	void reconstructImage(); //Reconstrucción de la imagen a partir de la matriz.
};
//Fin de la clase

#endif /* IMAGEVIDEODETECTION_H_ */
