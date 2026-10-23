#include <iostream>
#include "enrutador.h"


Enrutador::Enrutador()
{
    nombre = "";
}


Enrutador::Enrutador(std::string nombre)
{
    this->nombre = nombre;
    tablaCostos[nombre] = 0;
}


std::string Enrutador::getNombre() const
{
    return nombre;
}


void Enrutador::agregarVecino(std::string vecino, int costo)
{
    vecinos[vecino] = costo;
}


void Enrutador::eliminarVecino(std::string vecino)
{
    vecinos.erase(vecino);
}


bool Enrutador::esVecino(std::string vecino)
{
    if (vecinos.count(vecino) > 0)
    {
        return true;
    }

    return false;
}


int Enrutador::getCostoEnlace(std::string vecino)
{
    if (vecinos.count(vecino) == 0)
    {
        return -1;
    }

    return vecinos[vecino];
}


std::map<std::string, int> Enrutador::getVecinos()
{
    return vecinos;
}


void Enrutador::limpiarTabla()
{
    tablaCostos.clear();
    tablaCostos[nombre] = 0;
}


void Enrutador::actualizarCosto(std::string destino, int costo)
{
    tablaCostos[destino] = costo;
}


int Enrutador::getCosto(std::string destino)
{
    if (tablaCostos.count(destino) == 0)
    {
        return -1;
    }

    return tablaCostos[destino];
}


std::map<std::string, int> Enrutador::getTablaCostos()
{
    return tablaCostos;
}


void Enrutador::imprimirVecinos()
{
    std::cout << "Enrutador " << nombre << " -> ";

    if (vecinos.size() == 0)
    {
        std::cout << "sin vecinos";
    }

    std::map<std::string, int>::iterator it;

    for (it = vecinos.begin(); it != vecinos.end(); it++)
    {
        std::cout << it->first << "(" << it->second << ") ";
    }

    std::cout << std::endl;
}


void Enrutador::imprimirTabla()
{
    std::cout << "Tabla de costos de " << nombre << ":" << std::endl;

    std::map<std::string, int>::iterator it;

    for (it = tablaCostos.begin(); it != tablaCostos.end(); it++)
    {
        std::cout << "  " << it->first << ": ";

        if (it->second == -1)
        {
            std::cout << "-";
        }
        else
        {
            std::cout << it->second;
        }

        std::cout << std::endl;
    }
}
