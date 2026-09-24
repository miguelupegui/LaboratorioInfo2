#include "funciones.h"

std::string comprimirRLE(std::string texto)
{
    std::string comprimido = "";

    if (texto.empty())
    {
        return comprimido;
    }

    int contador = 1;

    for (int i = 0; i < texto.length() - 1; i++)
    {
        if (texto[i] == texto[i + 1])
        {
            contador++;
        }
        else
        {
            comprimido = comprimido + std::to_string(contador);
            comprimido = comprimido + texto[i];

            contador = 1;
        }
    }

    comprimido = comprimido + std::to_string(contador);
    comprimido = comprimido + texto[texto.length() - 1];

    return comprimido;
}


std::string descomprimirRLE(std::string texto)
{
    std::string descomprimido = "";

    int i = 0;

    while (i < texto.length())
    {
        int contador = 0;

        while (i < texto.length() && texto[i] >= '0' && texto[i] <= '9')
        {
            contador = contador * 10 + (texto[i] - '0');
            i++;
        }

        if (i >= texto.length())
        {
            break;
        }

        char caracter = texto[i];

        for (int j = 0; j < contador; j++)
        {
            descomprimido = descomprimido + caracter;
        }

        i++;
    }

    return descomprimido;
}