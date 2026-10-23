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
    actualizarTablas();

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
    actualizarTablas();

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
    actualizarTablas();

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
    actualizarTablas();

    return true;
}


void Red::actualizarTablas()
{
    std::map<std::string, Enrutador>::iterator it;
    std::map<std::string, Enrutador>::iterator otro;

    for (it = enrutadores.begin(); it != enrutadores.end(); it++)
    {
        it->second.limpiarTabla();

        for (otro = enrutadores.begin(); otro != enrutadores.end(); otro++)
        {
            if (otro->first != it->first)
            {
                it->second.actualizarCosto(otro->first, -1);
            }
        }

        std::map<std::string, int> vecinos = it->second.getVecinos();
        std::map<std::string, int>::iterator vecino;

        for (vecino = vecinos.begin(); vecino != vecinos.end(); vecino++)
        {
            it->second.actualizarCosto(vecino->first, vecino->second);
        }
    }
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


void Red::imprimirTablas()
{
    if (enrutadores.size() == 0)
    {
        std::cout << "La red esta vacia." << std::endl;
        return;
    }

    std::map<std::string, Enrutador>::iterator fila;
    std::map<std::string, Enrutador>::iterator columna;

    std::cout << "\t";

    for (columna = enrutadores.begin(); columna != enrutadores.end(); columna++)
    {
        std::cout << columna->first << "\t";
    }

    std::cout << std::endl;

    for (fila = enrutadores.begin(); fila != enrutadores.end(); fila++)
    {
        std::cout << fila->first << "\t";

        for (columna = enrutadores.begin(); columna != enrutadores.end(); columna++)
        {
            int costo = fila->second.getCosto(columna->first);

            if (costo == -1)
            {
                std::cout << "-\t";
            }
            else
            {
                std::cout << costo << "\t";
            }
        }

        std::cout << std::endl;
    }
}