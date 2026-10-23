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
};

#endif
