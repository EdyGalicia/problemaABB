// problemaABB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include"ABB.h"
using namespace std;

int main()
{
    Nodo* arbol = NULL;
    ABB* arbolito = new ABB();
    /*arbolito->insertar(arbol, 0, "a", NULL);
    arbolito->insertar(arbol, 0, "b", NULL);
    arbolito->insertar(arbol, 0, "c", NULL);
    arbolito->preOrden(arbol);
    cout << "\n" << endl;
    arbolito->imprimir(arbol, 0);*/

    string entrada = "hola amigos ";//lleva un espacio al final
    string aux = "";
    string concat = "";
    int repeticiones = 0;
    for (int i = 0; i < entrada.length(); i++)
    {
        aux = entrada[i];
        if (!aux._Equal(" "))
        {
            concat = concat + aux;
        }
        else
        {
            cout << "La palabra: " << concat << endl;
            //arbolito->buscar(arbol, 0);//aqui tenia que mandar a buscar y aumentar el contador, ya no dio tiempo :)
            arbolito->insertar(arbol, repeticiones, concat, NULL);
            aux = " ";
            concat = " ";
        }
    }

    arbolito->preOrden(arbol);
}

