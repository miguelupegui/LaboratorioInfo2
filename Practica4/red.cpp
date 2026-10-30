#include <iostream>
#include <fstream>
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
    }

    calcularCaminos();
}


void Red::calcularCaminos()
{
    std::map<std::string, Enrutador>::iterator it;

    for (it = enrutadores.begin(); it != enrutadores.end(); it++)
    {
        calcularCaminosDesde(it->first);
    }
}


void Red::calcularCaminosDesde(std::string origen)
{
    std::map<std::string, int> distancia;
    std::map<std::string, std::string> anterior;
    std::map<std::string, bool> visitado;

    std::map<std::string, Enrutador>::iterator it;

    for (it = enrutadores.begin(); it != enrutadores.end(); it++)
    {
        distancia[it->first] = -1;
        anterior[it->first] = "";
        visitado[it->first] = false;
    }

    distancia[origen] = 0;

    for (int i = 0; i < cantidadEnrutadores(); i++)
    {
        std::string actual = "";
        int menor = -1;

        std::map<std::string, int>::iterator d;

        for (d = distancia.begin(); d != distancia.end(); d++)
        {
            if (!visitado[d->first] && d->second != -1)
            {
                if (menor == -1 || d->second < menor)
                {
                    menor = d->second;
                    actual = d->first;
                }
            }
        }

        if (actual == "")
        {
            break;
        }

        visitado[actual] = true;

        std::map<std::string, int> vecinos = enrutadores[actual].getVecinos();
        std::map<std::string, int>::iterator v;

        for (v = vecinos.begin(); v != vecinos.end(); v++)
        {
            int nuevoCosto = menor + v->second;

            if (distancia[v->first] == -1 || nuevoCosto < distancia[v->first])
            {
                distancia[v->first] = nuevoCosto;
                anterior[v->first] = actual;
            }
        }
    }

    std::map<std::string, int>::iterator d;

    for (d = distancia.begin(); d != distancia.end(); d++)
    {
        if (d->second == -1 || d->first == origen)
        {
            continue;
        }

        std::list<std::string> camino;
        std::string paso = d->first;

        while (paso != "")
        {
            camino.push_front(paso);
            paso = anterior[paso];
        }

        enrutadores[origen].actualizarCosto(d->first, d->second);
        enrutadores[origen].guardarCamino(d->first, camino);
    }
}


bool Red::cargarDesdeArchivo(std::string ruta)
{
    std::ifstream archivo(ruta);

    if (!archivo)
    {
        return false;
    }

    enrutadores.clear();

    std::string origen;
    std::string destino;
    int costo;

    while (archivo >> origen >> destino >> costo)
    {
        if (!existeEnrutador(origen))
        {
            enrutadores[origen] = Enrutador(origen);
        }

        if (!existeEnrutador(destino))
        {
            enrutadores[destino] = Enrutador(destino);
        }

        if (origen != destino && costo > 0)
        {
            enrutadores[origen].agregarVecino(destino, costo);
            enrutadores[destino].agregarVecino(origen, costo);
        }
    }

    archivo.close();
    actualizarTablas();

    return true;
}


Camino Red::buscarCamino(std::string origen, std::string destino)
{
    Camino camino;

    if (!existeEnrutador(origen) || !existeEnrutador(destino))
    {
        return camino;
    }

    int costo = enrutadores[origen].getCosto(destino);

    if (costo == -1)
    {
        return camino;
    }

    std::list<std::string> nodos = enrutadores[origen].getCamino(destino);
    std::list<std::string>::iterator it;

    for (it = nodos.begin(); it != nodos.end(); it++)
    {
        camino.agregarNodo(*it);
    }

    camino.setCosto(costo);

    return camino;
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


void Red::imprimirTablaEnrutador(std::string nombre)
{
    if (!existeEnrutador(nombre))
    {
        std::cout << "Ese enrutador no existe." << std::endl;
        return;
    }

    enrutadores[nombre].imprimirTabla();
}