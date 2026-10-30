#ifndef RED_H
#define RED_H

#include <string>
#include <map>
#include "enrutador.h"
#include "camino.h"


class Red
{
private:
    std::map<std::string, Enrutador> enrutadores;

    void calcularCaminosDesde(std::string origen);

public:
    Red();

    bool existeEnrutador(std::string nombre);
    int cantidadEnrutadores();

    bool agregarEnrutador(std::string nombre);
    bool eliminarEnrutador(std::string nombre);

    bool agregarEnlace(std::string origen, std::string destino, int costo);
    bool eliminarEnlace(std::string origen, std::string destino);

    void actualizarTablas();
    void calcularCaminos();

    Camino buscarCamino(std::string origen, std::string destino);

    void imprimirTopologia();
    void imprimirTablas();
    void imprimirTablaEnrutador(std::string nombre);
};

#endif