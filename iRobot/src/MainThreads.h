/*
 * MainThreads.h
 *
 *  Created on: 13/04/2013
 *      Author: jose
 */

#ifndef MAINTHREADS_H_
#define MAINTHREADS_H_
#include "pthread.h"
#include <stdlib.h>

/**
 * Clase principal para el funcionamiento de los movientos de los individuos,
 * usando hilos de ejecución para los cuales se haran las animaciones y otras
 * funciones necesarias para el funcionamiento en conjunto de todos los elementos.
 */
class MainThreads
{
private:
	//Hilo de ejecucion principal
	pthread_t * _mainThread;

public:
	MainThreads(); //Constructor
	virtual ~MainThreads(); //Destructor
	//Funcion hecha para el funcionamiento del hilo de ejecución
	static void* functionThread(void* var);
	//Funcionamiento de los hilos
	void fThread();
	//Ejecución de los hilos
	void start();
};

#endif /* MAINTHREADS_H_ */
