#include <iostream>
#include "red.h"


Red::Red()
{
}


bool Red::existeEnrutador(std::string nombre)
{
    if (enrutadores.count(nombre) > 0)
    {
        return true;
    }

    return false;
}


int Red::cantidadEnrutadores()
{
    return enrutadores.size();
}


bool Red::agregarEnrutador(std::string nombre)
{
    if (existeEnrutador(nombre))
    {
        return false;
    }

    enrutadores[nombre] = Enrutador(nombre);

    return true;
}


bool Red::eliminarEnrutador(std::string nombre)
{
    if (!existeEnrutador(nombre))
    {
        return false;
    }

    std::map<std::string, Enrutador>::iterator it;

    for (it = enrutadores.begin(); it != enrutadores.end(); it++)
    {
        it->second.eliminarVecino(nombre);
    }

    enrutadores.erase(nombre);

    return true;
}


bool Red::agregarEnlace(std::string origen, std::string destino, int costo)
{
    if (!existeEnrutador(origen) || !existeEnrutador(destino))
    {
        return false;
    }

    if (origen == destino || costo <= 0)
    {
        return false;
    }

    enrutadores[origen].agregarVecino(destino, costo);
    enrutadores[destino].agregarVecino(origen, costo);

    return true;
}


bool Red::eliminarEnlace(std::string origen, std::string destino)
{
    if (!existeEnrutador(origen) || !existeEnrutador(destino))
    {
        return false;
    }

    if (!enrutadores[origen].esVecino(destino))
    {
        return false;
    }

    enrutadores[origen].eliminarVecino(destino);
    enrutadores[destino].eliminarVecino(origen);

    return true;
}


void Red::imprimirTopologia()
{
    if (enrutadores.size() == 0)
    {
        std::cout << "La red esta vacia." << std::endl;
        return;
    }

    std::cout << "Enrutadores en la red: " << enrutadores.size() << std::endl;

    std::map<std::string, Enrutador>::iterator it;

    for (it = enrutadores.begin(); it != enrutadores.end(); it++)
    {
        it->second.imprimirVecinos();
    }
}
