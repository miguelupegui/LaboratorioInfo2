#ifndef RED_H
#define RED_H

#include <string>
#include <map>
#include "enrutador.h"


class Red
{
private:
    std::map<std::string, Enrutador> enrutadores;

public:
    Red();

    bool existeEnrutador(std::string nombre);
    int cantidadEnrutadores();

    bool agregarEnrutador(std::string nombre);
    bool eliminarEnrutador(std::string nombre);

    bool agregarEnlace(std::string origen, std::string destino, int costo);
    bool eliminarEnlace(std::string origen, std::string destino);

    void imprimirTopologia();
};

#endif
