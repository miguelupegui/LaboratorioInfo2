#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <string>


std::string comprimirRLE(std::string texto);
std::string descomprimirRLE(std::string texto);


struct EntradaDiccionario
{
    int prefijo;
    char caracter;
};
struct ParLZ78
{
    int indice;
    char caracter;
};
int longitudTexto(const char* texto);
int buscarEntrada(const EntradaDiccionario* diccionario, int cantidad, int prefijo, char caracter);
void escribirEntrada(int indice, const EntradaDiccionario* diccionario, char* salida, int* posicion);
ParLZ78* comprimirLZ78(const char* texto, int longitud, int* cantidadPares);
char* descomprimirLZ78(const ParLZ78* pares, int cantidadPares, int longitudMaxima, int* longitudSalida);

unsigned char rotarIzquierda(unsigned char byte, int cantidad);
unsigned char rotarDerecha(unsigned char byte, int cantidad);
void encriptar(unsigned char* datos, int cantidad, int rotacion, unsigned char clave);
void desencriptar(unsigned char* datos, int cantidad, int rotacion, unsigned char clave);

#endif