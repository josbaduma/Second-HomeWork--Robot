/*
 * MainThreads.cpp
 *
 *  Created on: 13/04/2013
 *      Author: jose
 */

#include "MainThreads.h"

MainThreads::MainThreads()
{
	this->_mainThread = 0;
}

MainThreads::~MainThreads()
{
	free(this->_mainThread);
}

void* MainThreads::functionThread(void* var)
{
	reinterpret_cast<MainThreads*>(var)->fThread();
	return 0;
}

void MainThreads::fThread()
{

}

void MainThreads::start()
{
	pthread_create(this->_mainThread, 0, functionThread, this);
}
