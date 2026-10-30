#ifndef ENRUTADOR_H
#define ENRUTADOR_H

#include <string>
#include <map>
#include <list>


class Enrutador
{
private:
    std::string nombre;
    std::map<std::string, int> vecinos;
    std::map<std::string, int> tablaCostos;
    std::map<std::string, std::list<std::string>> caminos;

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

    void guardarCamino(std::string destino, std::list<std::string> camino);
    std::list<std::string> getCamino(std::string destino);

    void imprimirVecinos();
    void imprimirTabla();
};

#endif