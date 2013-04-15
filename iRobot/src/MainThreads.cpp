/*
 * MainThreads.cpp
 *
 *  Created on: 13/04/2013
 *      Author: jose
 */

#include "MainThreads.h"

/**
 * Constructor
 */
MainThreads::MainThreads()
{
	this->_mainThread = NULL;
}

/**
 * Destructor
 */
MainThreads::~MainThreads()
{
	free(this->_mainThread); //Libera la memoria
}

/**
 * Método utilizado para la llamada a la funcion que debe realizar
 * el hilo de ejecucion aqui se determina que funcion debe realizar.
 */
void* MainThreads::functionThread(void* var)
{
	std::cout << "Ejecutando" << std::endl;
	reinterpret_cast<MainThreads*>(var)->fThread();
	return 0;
}

/**
 * Funcionamiento del hilo de ejecución, en este metodo se declara
 * todas las acciones que debe de ejecutarse en el inicio.
 */
void MainThreads::fThread()
{
	std::cout << "Creando ventana" << std::endl;
	cvNamedWindow("Ejemplo", CV_WINDOW_AUTOSIZE);
	IplImage* imgOriginal = cvLoadImage("image.jpg");
	IplImage* copyImage = cvCloneImage(imgOriginal);

	CvRect box;
	box.x = 5;
	box.y = 5;

	for (int i = 5; i < imgOriginal->height - 5; i += 5)
	{
		for (int j = 5; j < imgOriginal->width - 5; j += 5)
		{
			cvShowImage("Ejemplo", copyImage);
			copyImage = cvCloneImage(imgOriginal);
			cvRectangle(copyImage, cvPoint(box.x, box.y),
					cvPoint(box.x + 5, box.y + 5), cvScalar(210, 31, 16));
			box.x = i, box.y = 5;
			usleep(1000);
		}

	}
	cvReleaseImage(&copyImage);
	cvReleaseImage(&imgOriginal);
	cvDestroyAllWindows();
}

/**
 * Inicio de las funciones que debe realizar los hilos de ejecucion.
 */
void MainThreads::start()
{
	pthread_create(this->_mainThread, NULL, MainThreads::functionThread, this);
}
