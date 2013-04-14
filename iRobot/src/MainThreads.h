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

class MainThreads
{
private:
	pthread_t * _mainThread;

public:
	MainThreads();
	virtual ~MainThreads();
	static void* functionThread(void* var);
	void fThread();
	void start();
};

#endif /* MAINTHREADS_H_ */
