#include <iostream>
#include "funciones.h"

using namespace std;

void pro12()
{
    int cuadrado[3][3];

    cout << "Ingrese los valores del cuadrado 3x3:" << endl;

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            int* posicion = &cuadrado[fila][columna];

            bool repetido;

            do
            {
                repetido = false;

                cout << "Posicion [" << fila << "][" << columna << "]: ";
                cin >> *posicion;

                for (int f = 0; f <= fila; f++)
                {
                    for (int c = 0; c < 3; c++)
                    {
                        if (f == fila && c >= columna)
                        {
                            continue;
                        }

                        int* anterior = &cuadrado[f][c];

                        if (*anterior == *posicion)
                        {
                            repetido = true;
                        }
                    }
                }

                if (repetido)
                {
                    cout << "Ese numero ya fue utilizado. Ingrese otro." << endl;
                }

            } while (repetido);
        }
    }

    cout << endl << "Matriz ingresada:" << endl;

    for (int fila = 0; fila < 3; fila++)
    {
        for (int columna = 0; columna < 3; columna++)
        {
            int* elemento = &cuadrado[fila][columna];
            cout << *elemento << " ";
        }

        cout << endl;
    }

    int sumaReferencia = 0;

    for (int columna = 0; columna < 3; columna++)
    {
        int* elemento = &cuadrado[0][columna];
        sumaReferencia = sumaReferencia + *elemento;
    }

    bool esMagico = true;

    for (int fila = 1; fila < 3; fila++)
    {
        int sumaFila = 0;

        for (int columna = 0; columna < 3; columna++)
        {
            int* elemento = &cuadrado[fila][columna];
            sumaFila = sumaFila + *elemento;
        }

        if (sumaFila != sumaReferencia)
        {
            esMagico = false;
        }
    }

    for (int columna = 0; columna < 3; columna++)
    {
        int sumaColumna = 0;

        for (int fila = 0; fila < 3; fila++)
        {
            int* elemento = &cuadrado[fila][columna];
            sumaColumna = sumaColumna + *elemento;
        }

        if (sumaColumna != sumaReferencia)
        {
            esMagico = false;
        }
    }

    int diagonal1 = 0;
    int diagonal2 = 0;

    for (int i = 0; i < 3; i++)
    {
        int* elemento1 = &cuadrado[i][i];
        int* elemento2 = &cuadrado[i][2 - i];

        diagonal1 = diagonal1 + *elemento1;
        diagonal2 = diagonal2 + *elemento2;
    }

    if (diagonal1 != sumaReferencia || diagonal2 != sumaReferencia)
    {
        esMagico = false;
    }

    cout << "Direccion de la primera posicion: "
         << (void*)&cuadrado[0][0] << endl;

    if (esMagico)
    {
        cout << "La matriz es un cuadrado magico." << endl;
    }
    else
    {
        cout << "La matriz no es un cuadrado magico." << endl;
    }
}

void pro14()
{
    int matriz[5][5];
    int matriz90[5][5];
    int matriz180[5][5];
    int matriz270[5][5];

    llenarMatriz(matriz);

    rotar90(matriz, matriz90);
    rotar180(matriz, matriz180);
    rotar270(matriz, matriz270);

    cout << "Matriz original:" << endl;
    imprimirMatriz(matriz);

    cout << endl << "Matriz rotada 90 grados:" << endl;
    imprimirMatriz(matriz90);

    cout << endl << "Matriz rotada 180 grados:" << endl;
    imprimirMatriz(matriz180);

    cout << endl << "Matriz rotada 270 grados:" << endl;
    imprimirMatriz(matriz270);

    int (*punteroMatriz)[5] = matriz;

    cout << endl << "Direccion de la matriz original: "
         << (void*)punteroMatriz << endl;
}

void pro16()
{
    long long tamano;

    cout << "Ingrese el tamaño de la malla: ";
    cin >> tamano;

    if (tamano < 0)
    {
        cout << "El tamaño no puede ser negativo." << endl;
        return;
    }

    long long dosN = tamano * 2;

    long long* pDosN = &dosN;
    long long* pN = &tamano;

    long long caminos = factorial(pDosN);
    long long parte = factorial(pN);

    caminos = caminos / (parte * parte);

    cout << "Para una malla de " << tamano << "x" << tamano << " hay " << caminos << " caminos." << endl;

    cout << "Direccion de la variable n: " << (void*)&tamano << endl;

    cout << "Tamano" << sizeof(caminos) << endl;
}

void pro18()
{
    long long numero;

    cout << "Ingrese el numero de la permutacion: ";
    cin >> numero;

    long long posicion = numero - 1;

    char digitos[10] = {'0', '1', '2', '3', '4',
                        '5', '6', '7', '8', '9'};

    char permutacion[11];

    for (int i = 0; i < 10; i++)
    {
        long long cantidad = 9 - i;
        long long* pCantidad = &cantidad;

        long long bloque = factorial(pCantidad);
        long long indice = posicion / bloque;

        permutacion[i] = digitos[indice];

        for (long long j = indice; j < 9 - i; j++)
        {
            digitos[j] = digitos[j + 1];
        }

        posicion = posicion % bloque;
    }

    permutacion[10] = '\0';

    char* resultado = permutacion;

    cout << "La permutacion numero " << numero
         << " es: " << resultado << endl;
}

int main()
{
    int x = 1;

    while (x != 0){

        cout << "-------------------------------" << endl;
        cout << "         Ejercicios" << endl;
        cout << "-------------------------------" << endl;
        cout << "12. Cuadrado Magico" << endl;
        cout << "14. Matriz 5x5 y rotaciones" << endl;
        cout << "16. Cantidad de caminos en una malla nxn" << endl;
        cout << "18. Enesima permutacion" << endl;
        cout << "0. Salir" << endl;
        cout << endl;
        cout << "Que ejercicio deseas revisar?" << endl;
        cin >> x;

        while (cin.fail()) {
            cout << "Ingrese una opcion valida: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> x;
        }

        switch(x){
        case 12: pro12(); break;
        case 14: pro14(); break;
        case 16: pro16(); break;
        case 18: pro18(); break;

        case 0:
            cout << "Chaolin Pinguin" << endl;
            break;
        default:
            cout << "Opcion invalida, Sigue intentando" << endl;
        }
    }

    return 0;
}
