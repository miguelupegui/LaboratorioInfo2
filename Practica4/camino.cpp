#include <iostream>
#include "camino.h"


Camino::Camino()
{
    costo = -1;
}


void Camino::agregarNodo(std::string nombre)
{
    nodos.push_back(nombre);
}


std::list<std::string> Camino::getNodos()
{
    return nodos;
}


void Camino::setCosto(int costo)
{
    this->costo = costo;
}


int Camino::getCosto()
{
    return costo;
}


void Camino::imprimir()
{
    if (nodos.size() == 0 || costo == -1)
    {
        std::cout << "No existe un camino entre esos enrutadores." << std::endl;
        return;
    }

    std::cout << "Camino: ";

    std::list<std::string>::iterator it;

    for (it = nodos.begin(); it != nodos.end(); it++)
    {
        if (it != nodos.begin())
        {
            std::cout << " -> ";
        }

        std::cout << *it;
    }

    std::cout << std::endl;
    std::cout << "Costo total: " << costo << std::endl;
}