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
