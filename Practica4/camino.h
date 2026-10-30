#ifndef CAMINO_H
#define CAMINO_H

#include <string>
#include <list>


class Camino
{
private:
    std::list<std::string> nodos;
    int costo;

public:
    Camino();

    void agregarNodo(std::string nombre);
    std::list<std::string> getNodos();

    void setCosto(int costo);
    int getCosto();

    void imprimir();
};

#endif