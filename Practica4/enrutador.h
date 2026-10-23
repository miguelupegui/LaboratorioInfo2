#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <string>
#include <map>


class Enrutador
{
private:
    std::string nombre;
    std::map<std::string, int> vecinos;
    std::map<std::string, int> tablaCostos;

public:
    Enrutador();
    Enrutador(std::string nombre);

    std::string getNombre() const;

    void agregarVecino(std::string vecino, int costo);
    void eliminarVecino(std::string vecino);
    bool esVecino(std::string vecino);
    int getCostoEnlace(std::string vecino);
    std::map<std::string, int> getVecinos();

    void limpiarTabla();
    void actualizarCosto(std::string destino, int costo);
    int getCosto(std::string destino);
    std::map<std::string, int> getTablaCostos();

    void imprimirVecinos();
    void imprimirTabla();
};

#endif