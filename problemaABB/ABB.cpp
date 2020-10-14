#include "ABB.h"

ABB::ABB() {}

void ABB::insertar(Nodo*& arbol, int dato, string palabra, Nodo* padre)
{
	if (arbol == NULL)//si el arbol esta vacio
	{
		Nodo* nuevo = new Nodo(palabra, dato, padre);//
		arbol = nuevo;
		cout << "El se ha insertado"<< endl;
	}
	else//si ya tiene nodos
	{
		int valorRaiz = arbol->getDato();
		string valorRa = arbol->getPalabra();
		if (palabra.compare(valorRa) < 0)//si el dato nuevo es menor al dato del nodo, se va a la izquierda
		{
			insertar(arbol->izq, dato, palabra, arbol);
		}
		else//sino, a la derecha
		{
			insertar(arbol->der, dato, palabra, arbol);
		}
	}
}


void ABB::imprimir(Nodo* arbol, int contador) {
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		imprimir(arbol->getDer(), contador + 1);
		for (int i = 0; i < contador; i++)
		{
			cout << "   ";
		}
		cout << arbol->getPalabra() << endl;
		imprimir(arbol->getIzq(), contador + 1);
	}
}

bool ABB::buscar(Nodo* arbol, int dato) {
	if (arbol == NULL)
	{
		return false;
	}
	else
	{
		if (arbol->getDato() == dato)
		{
			return true;
		}
		else
		{
			if (dato < arbol->getDato())
			{
				return buscar(arbol->getIzq(), dato);
			}
			else
			{
				return buscar(arbol->getDer(), dato);
			}
		}

	}
}

void ABB::preOrden(Nodo* arbol) {
	if (arbol == NULL)
	{
		return;
	}
	else
	{
		cout << "[" << arbol->getDato() << ", " << arbol->getPalabra() << "], ";
		preOrden(arbol->getIzq());
		preOrden(arbol->getDer());
	}
}