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
	this->_mainThread = 0;
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
	reinterpret_cast<MainThreads*>(var)->fThread();
	return 0;
}

/**
 * Funcionamiento del hilo de ejecución, en este metodo se declara
 * todas las acciones que debe de ejecutarse en el inicio.
 */
void MainThreads::fThread()
{

}

/**
 * Inicio de las funciones que debe realizar los hilos de ejecucion.
 */
void MainThreads::start()
{
	pthread_create(this->_mainThread, 0, MainThreads::functionThread, this);
}
