// Cartas.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <list>
#include <time.h>
#include <iostream>


void ImprimirCartas(std::list<int> *cartas2);
int main(int argc, _TCHAR* argv[])
{
	std::list<int> *cartas = new std::list<int>();
	srand(time(NULL));
	
	for (int x = 0; x < 10; x++){
		cartas->push_back(std::rand() % 13 + 1);
	}
	std::cout << "Antes" << std::endl;
	ImprimirCartas(cartas);//Imprime Lista

	bool copia = true;
	for (std::list<int>::const_iterator a = cartas->begin(); a != cartas->end();)
	{
		for (std::list<int>::const_iterator b = a; b != cartas->end();)
			if (*a == *b && a != b)
			{
				if (copia)
				{
					copia= false;
				}
				b = cartas->erase(b);
			}
			else{
				++b;
			}
		++a;
	}

	if (copia) {
		std::cout << "No hay iguales";
		}
	std::cout << std::endl << "Despues";
	ImprimirCartas(cartas);//Imprime lista

	return 0;
}

void ImprimirCartas(std::list<int> *cartas){
	bool flag = true;
	for (std::list<int>::const_iterator a = cartas->begin(); a != cartas->end(); a++){
		if (flag) { //Se mira mas bonito
			std::cout << *a;
			flag = false;
		}
		else
			std::cout << *a;
		std::cout << std::endl << std::endl;
	}
}

