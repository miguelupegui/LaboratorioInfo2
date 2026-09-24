#ifndef FUNCIONES_H
#define FUNCIONES_H

long long factorial(const long long* numero);

void llenarMatriz(int (*matriz)[5]);
void imprimirMatriz(const int (*matriz)[5]);
void rotar90(const int (*original)[5], int (*resultado)[5]);
void rotar180(const int (*original)[5], int (*resultado)[5]);
void rotar270(const int (*original)[5], int (*resultado)[5]);

#endif
