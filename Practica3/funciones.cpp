#include "funciones.h"


std::string comprimirRLE(std::string texto)
{
    std::string comprimido = "";

    if (texto.empty())
    {
        return comprimido;
    }

    int contador = 1;

    for (int i = 0; i < (int)texto.length() - 1; i++)
    {
        if (texto[i] == texto[i + 1])
        {
            contador++;
        }
        else
        {
            int numero = contador;
            std::string numeroTexto = "";

            while (numero > 0)
            {
                char digito = (char)('0' + (numero % 10));
                numeroTexto = digito + numeroTexto;
                numero = numero / 10;
            }

            comprimido = comprimido + numeroTexto;
            comprimido = comprimido + texto[i];

            contador = 1;
        }
    }

    int numero = contador;
    std::string numeroTexto = "";

    while (numero > 0)
    {
        char digito = (char)('0' + (numero % 10));
        numeroTexto = digito + numeroTexto;
        numero = numero / 10;
    }

    comprimido = comprimido + numeroTexto;
    comprimido = comprimido + texto[texto.length() - 1];

    return comprimido;
}


std::string descomprimirRLE(std::string texto)
{
    std::string descomprimido = "";

    int i = 0;

    while (i < (int)texto.length())
    {
        int contador = 0;

        while (i < (int)texto.length() && texto[i] >= '0' && texto[i] <= '9')
        {
            contador = contador * 10 + (texto[i] - '0');
            i++;
        }

        if (i >= (int)texto.length())
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


int longitudTexto(const char* texto)
{
    int longitud = 0;

    while (texto[longitud] != '\0')
    {
        longitud++;
    }

    return longitud;
}


int buscarEntrada(const EntradaDiccionario* diccionario, int cantidad,
                  int prefijo, char caracter)
{
    for (int i = 0; i < cantidad; i++)
    {
        if (diccionario[i].prefijo == prefijo &&
            diccionario[i].caracter == caracter)
        {
            return i + 1;
        }
    }

    return 0;
}


void escribirEntrada(int indice,
                     const EntradaDiccionario* diccionario,
                     char* salida,
                     int* posicion)
{
    if (indice == 0)
    {
        return;
    }

    escribirEntrada(diccionario[indice - 1].prefijo,
                    diccionario,
                    salida,
                    posicion);

    salida[*posicion] = diccionario[indice - 1].caracter;
    (*posicion)++;
}


ParLZ78* comprimirLZ78(const char* texto, int longitud, int* cantidadPares)
{
    int capacidad = longitud + 1;

    EntradaDiccionario* diccionario =
        new EntradaDiccionario[capacidad];

    ParLZ78* pares =
        new ParLZ78[capacidad];

    int cantidadDiccionario = 0;
    int posicion = 0;
    int indiceActual = 0;

    *cantidadPares = 0;

    while (posicion < longitud)
    {
        int encontrado = buscarEntrada(
            diccionario,
            cantidadDiccionario,
            indiceActual,
            texto[posicion]
            );

        if (encontrado != 0)
        {
            indiceActual = encontrado;
            posicion++;
        }
        else
        {
            diccionario[cantidadDiccionario].prefijo = indiceActual;
            diccionario[cantidadDiccionario].caracter = texto[posicion];

            cantidadDiccionario++;

            pares[*cantidadPares].indice = indiceActual;
            pares[*cantidadPares].caracter = texto[posicion];

            (*cantidadPares)++;

            indiceActual = 0;
            posicion++;
        }
    }

    /*
     Si el texto termina exactamente en una frase
     que ya estaba en el diccionario.
    */
    if (indiceActual != 0)
    {
        pares[*cantidadPares].indice = indiceActual;
        pares[*cantidadPares].caracter = '\0';

        (*cantidadPares)++;
    }

    delete[] diccionario;

    return pares;
}


char* descomprimirLZ78(const ParLZ78* pares,
                       int cantidadPares,
                       int longitudMaxima,
                       int* longitudSalida)
{
    EntradaDiccionario* diccionario =
        new EntradaDiccionario[longitudMaxima + 1];

    char* salida =
        new char[longitudMaxima + 1];

    int cantidadDiccionario = 0;
    int posicion = 0;

    for (int i = 0; i < cantidadPares; i++)
    {
        if (pares[i].caracter == '\0')
        {
            escribirEntrada(
                pares[i].indice,
                diccionario,
                salida,
                &posicion
                );
        }
        else
        {
            diccionario[cantidadDiccionario].prefijo =
                pares[i].indice;

            diccionario[cantidadDiccionario].caracter =
                pares[i].caracter;

            cantidadDiccionario++;

            escribirEntrada(
                cantidadDiccionario,
                diccionario,
                salida,
                &posicion
                );
        }
    }

    salida[posicion] = '\0';

    *longitudSalida = posicion;

    delete[] diccionario;

    return salida;
}


unsigned char rotarIzquierda(unsigned char byte, int cantidad)
{
    return (unsigned char)
    ((byte << cantidad) | (byte >> (8 - cantidad)));
}


unsigned char rotarDerecha(unsigned char byte, int cantidad)
{
    return (unsigned char)
    ((byte >> cantidad) | (byte << (8 - cantidad)));
}


void encriptar(unsigned char* datos,
               int cantidad,
               int rotacion,
               unsigned char clave)
{
    for (int i = 0; i < cantidad; i++)
    {
        datos[i] = rotarIzquierda(datos[i], rotacion);

        datos[i] = datos[i] ^ clave;
    }
}


void desencriptar(unsigned char* datos,
                  int cantidad,
                  int rotacion,
                  unsigned char clave)
{
    for (int i = 0; i < cantidad; i++)
    {
        datos[i] = datos[i] ^ clave;

        datos[i] = rotarDerecha(datos[i], rotacion);
    }
}