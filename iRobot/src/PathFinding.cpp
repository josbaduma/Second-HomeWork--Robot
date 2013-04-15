/*
 * PathFinding.cpp
 *
 *  Created on: 04/04/2013
 *      Author: jose
 */

#include "PathFinding.h"

/*
 * Constructor
 */
PathFinding::PathFinding(MatrixNode** pGraph, int plengthX, int plengthY)
{
	this->_graph = pGraph;
	this->_lengthX = plengthX;
	this->_lengthY = plengthY;
}

/*
 * Destructor
 */
PathFinding::~PathFinding()
{
	free(this->_graph); //Libera la memoria de la matriz
}

/*
 * Método de busqueda del camino mas corto a travez de una matriz de nxm en tamaño,
 * este busca un camino entre dos nodos con una implementacion heuristica.
 * @param StartNode, GoalNode
 */
SimpleList<MatrixNode*>* PathFinding::AStar(MatrixNode* pStart,
		MatrixNode* pGoal)
{
	SimpleList<MatrixNode*>* _openList = new SimpleList<MatrixNode*>(); //Inicializacion de la lista abierta de nodos
	SimpleList<MatrixNode*>* _closeList = new SimpleList<MatrixNode*>(); //Inicializacion de la lista cerrada de nodos

	_openList->insertFinal(pStart); //Se inserta el nodo de inicio

	while (!_openList->isEmpty()) //Inicio de ciclo para encontrar el camino más corto
	{
		std::cout << _openList->length() << std::endl;
		MatrixNode* current = _openList->get(0); //Se obtiene el primer nodo
		for (int i = 0; i < _openList->length(); ++i) //Busqueda del nodo con la menor funcion heuristica
		{
			MatrixNode* tmp = _openList->get(i);
			int F1 = this->h(current, pGoal) + this->g(current);
			int F2 = this->h(tmp, pGoal) + this->g(tmp);
			if (F1 > F2)
			{
				current = tmp;
			}
		}

		_openList->deleteSpecific(current); //Se elimina el nodo de menor peso

		_closeList->insertFinal(current); //Se inserta a la lista de nodos cerrados

		if (current == pGoal) //Salir del ciclo en caso de encontrar el nodo final
		{
			break;
		}

		/*
		 * Añadir cada nodo adyacente al nodo actual
		 */
		for (int i = current->getPosY() - 1; i <= current->getPosY() + 1; ++i)
		{
			for (int j = current->getPosX() - 1; j <= current->getPosX() + 1;
					++j)
			{
				if (i < 0 || j < 0 || i >= this->_lengthY
						|| j >= this->_lengthX)
				{
					continue; //En caso de no estar dentro de la matriz
				}
				if (this->_graph[j + (i * this->_lengthX)]->getWeightOfWay()
						== 0)
				{
					continue; //El caso de tener un camino nulo
				}
				if (_openList->search(this->_graph[j + (i * _lengthX)]))
				{
					continue; //El caso de esta ya dentro de la lista abierta
				}
				else if (_closeList->search(this->_graph[j + (i * _lengthX)]))
				{
					continue; //El caso de estar en la lista cerrada
				}
				else
				{
					this->_graph[j + (i * _lengthX)]->setParent(current); //Definir al nodo adyacente el padre del cual proviene
					_openList->insertFinal(this->_graph[j + (i * _lengthX)]); //Insertar el nodo adyacente a la lista de abiertos
				}
			}
		}

	} //Fin del ciclo
	return this->reconstructWay(_closeList, pStart); //Devolver la lista de con el camino
}

/*
 Funcion heuristica que permite determinar el camino más corto entre el nodo y el nodo de llegada
 @param pNode, pGoalNode
 */
int PathFinding::h(MatrixNode* pNode, MatrixNode* pGoal)
{
	int D = pNode->getWeightOfWay(); //Se obtiene el peso del nodo
	int result = D * abs(pNode->getPosX() - pGoal->getPosX())
			+ abs(pNode->getPosY() - pGoal->getPosY()); //Se realiza el calculo de la funcion manhatan
	return result; //Se devuelve el valor del camino.
}

int PathFinding::g(MatrixNode* pNode)
{
	int tmp = 0;
	if (pNode->getParent() == NULL)
	{
		return tmp;
	}
	tmp = 1 + (this->g(pNode->getParent()) - 1);
	return tmp;
}

/*
 Funcion de busqueda de caminos con un recorrido en anchura de la matriz.
 @param StartNode, GoalNode
 */
SimpleList<MatrixNode*>* PathFinding::BreadthFirstSearch(MatrixNode* pStart,
		MatrixNode* pGoal)
{

	ListQueue<MatrixNode*>* _queue = new ListQueue<MatrixNode*>(); //Inicialización de la cola
	SimpleList<MatrixNode*>* _vistedList = new SimpleList<MatrixNode*>(); //Inicialización de una lista de nodos visitados

	if (pStart == pGoal) //En caso de ser el nodo el llegada se devuelve la lista vacia
	{
		return _vistedList;
	}

	_queue->enqueue(pStart); //Encolamos el nodo inicial

	while (!_queue->isEmpty()) //Ciclo de busqueda del camino
	{
		MatrixNode* tmp = _queue->dequeue(); //Desencolamos el nodo

		if (tmp == pGoal) //Verificar que sea el nodo de llegada
		{
			_vistedList->insertFinal(tmp); //Se inserta el nodo en la lista de visitados
			break; //Salir del ciclo
		}

		_vistedList->insertFinal(tmp); //Se inserta en la lista de visitados el nodo temporal

		for (int i = tmp->getPosY() - 1; i <= tmp->getPosY() + 1; ++i) //Ciclo de busqueda de nodos adyacentes al temporal
		{
			for (int j = tmp->getPosX() - 1; j <= tmp->getPosX() + 1; ++j)
			{
				//Verificar que se encuentra dentro de la matriz
				if (i < 0 || j < 0 || i >= this->_lengthY
						|| j >= this->_lengthX)
				{
					continue;
				}
				//Verificamos que no sea un camino nulo al cual no se pueda pasar
				if (this->_graph[j + (i * this->_lengthX)]->getWeightOfWay()
						== 0)
				{
					continue;
				}
				//Buscamos si este nodo ya se encuentra en la lista y en la cola para ser incluido o no.
				if (!(_vistedList->search(
						this->_graph[j + (i * this->_lengthX)])))
				{
					if (!(_queue->search(this->_graph[j + (i * this->_lengthX)])))
					{
						_queue->enqueue(this->_graph[j + (i * this->_lengthX)]); //Encolamos el nodo adyacente
						this->_graph[j + (i * this->_lengthX)]->setParent(tmp); //Definir al padre de este nodo
					}
				} //Fin del ciclo de busqueda de nodos adyacentes
			}
		} //Fin del ciclo de busqueda del camino
	}
	return this->reconstructWay(_vistedList, pStart); //Retornar la lista de nodos visitados
}

/**
 Funcion de busqueda de caminos mediante el recorrido en profuncidad o distancia.
 @param StartNode, GoalNode
 */
SimpleList<MatrixNode*>* PathFinding::DistanceFirstSearch(MatrixNode* pStart,
		MatrixNode* pGoal)
{

	//Inicializacion de la pila de nodos.
	ListStack<MatrixNode*>* _stack = new ListStack<MatrixNode*>();
	//Inicializacion de lista de nodos visitados
	SimpleList<MatrixNode*>* _visited = new SimpleList<MatrixNode*>();

	//Se inserta el nodo inicial en la pila
	_stack->push(pStart);

	//Ciclo de busqueda del camino
	while (!_stack->isEmpty())
	{
		//Se saca el primer nodo de la pila como temporal
		MatrixNode* tmp = _stack->pop();

		//verificar que se el nodo final
		if (tmp == pGoal)
		{
			//Se inserta el temporal en la lista de visitados
			_visited->insertFinal(tmp);
			break; //Salir del ciclo
		}

		//Se inserta el nodo temporal a la lista de nodos visitados
		_visited->insertFinal(tmp);

		//Busqueda de nodos adyacentes al nodo temporal
		for (int i = tmp->getPosY() - 1; i <= tmp->getPosY() + 1; ++i)
		{
			for (int j = tmp->getPosX() - 1; j <= tmp->getPosX() + 1; ++j)
			{
				//Verificar que se encuentra dentro de la matriz
				if (i < 0 || j < 0 || i >= this->_lengthY
						|| j >= this->_lengthX)
				{
					continue;
				}
				//Verificar y descartar si este nodo tiene un peso infinito
				if (this->_graph[j + (i * this->_lengthX)]->getWeightOfWay()
						== 0)
				{
					continue;
				}
				// Buscar si este nodo adyacente ya se encuentra en la lista y pila.
				else if (!_visited->search(
						this->_graph[j + (i * this->_lengthX)]))
				{
					//Definimos el padre del nodo adyacente
					this->_graph[j + (i * this->_lengthX)]->setParent(tmp);
					//Insertamos el nodo adyacente a la pila
					_stack->push(this->_graph[j + (i * this->_lengthX)]);
				}
			}
		} //Fin del ciclo de busqueda de nodos adyacentes
	} //Fin del ciclo de busqueda de caminos

	return this->reconstructWay(_visited, pStart); //Devolver la lista de nodos vistados
}

/*
 Funcion de busqueda de caminos basada en la aleatoriedad de alguna funcion especifica
 que determina a cual nodo movernos en cada iteración.
 @param StartNode, GoalNode
 */
SimpleList<MatrixNode*>* PathFinding::RandomBounce(MatrixNode* pStart,
		MatrixNode* pGoal)
{
	//Inicializacion de la lista de nodos visitados
	SimpleList<MatrixNode*>* _visited = new SimpleList<MatrixNode*>();

	//Declaracion de las posiciones random en la matriz
	int randX, randY;

	//Se inserta el nodo inicial en la lista de visitados
	_visited->insertFinal(pStart);

	//Hacemos al nodo inicial como un temporal
	MatrixNode* tmp = pStart;

	//Inicia un ciclo de busqueda del camino
	while (!_visited->search(pGoal))
	{

		//Se obtiene un número random para la obtencion de la columna en la matriz
		randX = this->getRandom(tmp->getPosX() - 1, tmp->getPosX() + 2);
		//Se obtiene un número random para la obtencion de la fila en la matriz
		randY = this->getRandom(tmp->getPosY() - 1, tmp->getPosY() + 2);

		//Ciclo para poder obtener un random más definido y que no produzca error de recorrido
		while (randX < 0 || randX >= this->_lengthX)
		{
			randX = this->getRandom(tmp->getPosX() - 1, tmp->getPosX() + 2);
		}
		while (randY < 0 || randY >= this->_lengthY)
		{
			randY = this->getRandom(tmp->getPosY() - 1, tmp->getPosY() + 2);
		}
		tmp = this->_graph[randX + (randY * this->_lengthX)];

		//Se inserta el nodo obtenido en el calculo
		//azar de la fila y columna de la matriz
		_visited->insertFinal(tmp);
	}

	//Devolver la lista de nodos vistados
	return _visited;
}

/*
 Funcion que devuelve un numero aleatorio entre dos numeros definidos.
 Entre un intervalo devuelve un número al azar.
 @param minimo, maximo
 */

int PathFinding::getRandom(int min, int max)
{
	int tmp = min + (rand() % (max - min)); //Calcula el número aleatorio
	return tmp; //Devulve el numero aleatorio
}

/*
 Funcion para la obtencion del camino mediante el rastreo del nodo objetivo.
 Este se va acercando siempre hacia el objetivo
 @param StartNode, GoalNode
 */
SimpleList<MatrixNode*>* PathFinding::ObjectTracing(MatrixNode* pStart,
		MatrixNode* pGoal)
{
	//Inicializacion de la lista de nodos visitados
	SimpleList<MatrixNode*>* _visitedList = new SimpleList<MatrixNode*>();

	//Insertar el nodo inicial
	_visitedList->insertFinal(pStart);

	//Declaracion de las posiciones columna y filas del actual nodo y el objetivo
	int posX, posY, destinationX, destinationY;

	//Obtencion de las posiciones en filas y columnas del actual
	posX = pStart->getPosX();
	posY = pStart->getPosY();

	//Obtencion de las posiciones en filas y columnas del objetivo
	destinationX = pGoal->getPosX();
	destinationY = pGoal->getPosY();

	//Ciclo de busqueda el camino
	while (!_visitedList->search(pGoal))
	{
		//Moverse en las columnas hacia la izquierda
		if (posX > destinationX
				&& this->_graph[(posX - 1) + (posY * this->_lengthX)]->getWeightOfWay()
						!= 0)
		{
			posX--;
		}
		//Moverse en las columnas hacia la derecha
		else if (posX < destinationX
				&& this->_graph[(posX + 1) + (posY * this->_lengthX)]->getWeightOfWay()
						!= 0)
		{
			posX++;
		}
		//Moverse en las filas hacia arriba
		if (posY > destinationY
				&& this->_graph[posX + ((posY - 1) * this->_lengthX)]->getWeightOfWay()
						!= 0)
		{
			posY--;
		}
		//Moverse en las filas hacia abajo
		else if (posY < destinationY
				&& this->_graph[posX + ((posY + 1) * this->_lengthX)]->getWeightOfWay()
						!= 0)
		{
			posY++;
		}

		//Insertar el nodo obtenido
		_visitedList->insertFinal(this->_graph[posX + (posY * this->_lengthX)]);
	}

	//Devolver la lista de nodos visitados
	return _visitedList;
}

/*
 Reconstruccion del camino a partir del nodo de llegada hacia atras devolviendose
 mediante la obtenicion del padre de los nodos.
 @param Lista, startNode
 */
SimpleList<MatrixNode*>* PathFinding::reconstructWay(
		SimpleList<MatrixNode*>* pList, MatrixNode* pStart)
{
	//Inicializa una lista temporal
	SimpleList<MatrixNode*>* tmpList = new SimpleList<MatrixNode*>();
	//Se obtiene el nodo objetivo
	MatrixNode* current = pList->deleteFinal();
	//Ciclo de busqueda del padre del nodo actual
	while (current != pStart)
	{
		tmpList->insertFinal(current); //Se inserta el nodo a la lista temporal
		current = current->getParent(); //Se obtiene el nodo padre
	}
	tmpList->insertFinal(pStart); //Se inserta el nodo inicial
	free(pList);//Libera la memoria de lista
	return tmpList; //Se devuelve la lista temporal
}
