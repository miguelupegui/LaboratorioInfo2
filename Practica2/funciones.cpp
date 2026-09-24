#include "funciones.h"
#include <iostream>

long long factorial(const long long* numero)
{
    long long resultado = 1;

    for (long long i = *numero; i > 1; i--)
    {
        resultado = resultado * i;
    }

    return resultado;
}

void llenarMatriz(int (*matriz)[5])
{
    int numero = 1;

    for (int fila = 0; fila < 5; fila++)
    {
        for (int columna = 0; columna < 5; columna++)
        {
            *(*(matriz + fila) + columna) = numero;
            numero++;
        }
    }
}

void imprimirMatriz(const int (*matriz)[5])
{
    for (int fila = 0; fila < 5; fila++)
    {
        for (int columna = 0; columna < 5; columna++)
        {
            std::cout << *(*(matriz + fila) + columna) << " ";
        }

        std::cout << std::endl;
    }
}

void rotar90(const int (*original)[5], int (*resultado)[5])
{
    for (int fila = 0; fila < 5; fila++)
    {
        for (int columna = 0; columna < 5; columna++)
        {
            *(*(resultado + columna) + (4 - fila)) =
                *(*(original + fila) + columna);
        }
    }
}

void rotar180(const int (*original)[5], int (*resultado)[5])
{
    for (int fila = 0; fila < 5; fila++)
    {
        for (int columna = 0; columna < 5; columna++)
        {
            *(*(resultado + (4 - fila)) + (4 - columna)) =
                *(*(original + fila) + columna);
        }
    }
}

void rotar270(const int (*original)[5], int (*resultado)[5])
{
    for (int fila = 0; fila < 5; fila++)
    {
        for (int columna = 0; columna < 5; columna++)
        {
            *(*(resultado + (4 - columna)) + fila) =
                *(*(original + fila) + columna);
        }
    }
}
