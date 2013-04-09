/*
 * ImageVideoDetection.cpp
 *
 *  Created on: 16/03/2013
 *      Author: jose
 */

#include "ImageVideoDetection.h"

ImageVideoDetection::ImageVideoDetection() { //Constructor
	this->_graph = NULL; //Primera instancia es nula.
}

ImageVideoDetection::~ImageVideoDetection() { //Destructor
	free(this->_graph); //Se libera la memoria de la matriz.
}

/**
 Crea una matriz de nodos con los cuales se almacenan el color RGB y las posiciones de la fila y columna del nodo.
 @param Imagen
 */
void ImageVideoDetection::matrixImage(IplImage* img) {

	int lenghtX = img->width / 5; //Ancho de la matriz
	int lenghtY = img->height / 5; //Largo de la matriz

	this->_graph = new MatrixNode*[lenghtX * lenghtY]; //Crea la matriz

	int x = 0, y = 0; //Variables temporale para moverse dentro de la matriz

	CvScalar pixel; //Variable que va obteniendo los pixeles

	for (int i = 2; i < img->height; i += 5) {
		for (int j = 2; j < img->width; j += 5) {
			pixel = cvGet2D(img, i, j); // Se obtiene el pixel
			MatrixNode* tmp = new MatrixNode(x, y, getColor(pixel.val[2]), //Se crea el nodo con los colores y posiciones en la matriz
			getColor(pixel.val[1]), getColor(pixel.val[0]));
			this->_graph[x + (y * lenghtX)] = tmp; //Se asigna el nodo en la matriz
			x++; // Aumento de X
		}
		x = 0;
		y++; //Aumento de Y
	}
}

/*
 * Se obtiene la matriz con respecto a las capturas de imagen.
 */
void ImageVideoDetection::videoMatrix(int pCamara) {
	IplImage* frame; //Se define la imagen
	cvNamedWindow("Color detection", CV_WINDOW_AUTOSIZE); //Se crea la ventana
	CvCapture* capture = cvCaptureFromCAM(pCamara); //Se inicializa la captura de imagenes en la camara.
	frame = cvQueryFrame(capture); //Se hace una captura inicial

	int input;
	while ((input = cvWaitKey(200)) != 27) { //Ciclo de capturas de la camara
		frame = cvQueryFrame(capture); //Se obtiene la imagen a partir de la camara

		cvShowImage("Color detection", frame); //Se muestra en pantalla la captura

		matrixImage(frame); //Se llama a la funcion para que construya la matriz
	}
	cvDestroyAllWindows(); // Destruye toda ventana
	cvReleaseCapture(&capture);
	cvReleaseImage(&frame);
}

/*
 * Delimitador de colores
 * Según el rango en el que se encuentre el color este devolvera un número entre 0 y 7
 */
int ImageVideoDetection::getColor(int color) {
	if (color < 32) { //Verificacion de rango
		return 0;
	} else if (color >= 32 && color < 64) { //Verificacion de rango
		return 1;
	} else if (color >= 64 && color < 96) { //Verificacion de rango
		return 2;
	} else if (color >= 96 && color < 128) { //Verificacion de rango
		return 3;
	} else if (color >= 128 && color < 160) { //Verificacion de rango
		return 4;
	} else if (color >= 160 && color < 192) { //Verificacion de rango
		return 5;
	} else if (color >= 192 && color < 224) { //Verificacion de rango
		return 6;
	} else { //Verificacion de rango
		return 7;
	}
}

/*
 * Reconstructor de la imagen apartir de la matriz obtenida anteriormente.
 */
void ImageVideoDetection::reconstructImage(int lengthX, int lengthY) {
	cvNamedWindow("Reconstruccion", CV_WINDOW_AUTOSIZE);
	IplImage* reconst = cvCreateImage(cvSize(lengthX, lengthY), IPL_DEPTH_8U,
			3); //Se crea la imagen vacía para la reconstrucción
	for (int i = 0; i < lengthY; i++) { //Ciclo
		for (int j = 0; j < lengthX; j++) { //Ciclo

			((uchar *) (reconst->imageData + i * reconst->widthStep))[j
					* reconst->nChannels + 0] = 32
					* (this->_graph[j + (i * lengthX)]->getColor()[2]); //Se define el color azul del pixel
			((uchar *) (reconst->imageData + i * reconst->widthStep))[j
					* reconst->nChannels + 1] = 32
					* (this->_graph[j + (i * lengthX)]->getColor()[1]); //Se define el color verde del pixel
			((uchar *) (reconst->imageData + i * reconst->widthStep))[j
					* reconst->nChannels + 2] = 32
					* (this->_graph[j + (i * lengthX)]->getColor()[0]); //Se define el color rojo del pixel
		}
	}
	cvShowImage("Reconstruccion", reconst);
}
