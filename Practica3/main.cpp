#include <iostream>
#include "funciones.h"

using namespace std;


void pro1()
{
    string texto;

    cout << endl;
    cout << "Ingrese el texto: ";
    cin.ignore(1000, '\n');
    getline(cin, texto);

    string comprimido = comprimirRLE(texto);
    string descomprimido = descomprimirRLE(comprimido);

    cout << endl;
    cout << "Texto original: " << texto << endl;
    cout << "Texto comprimido: " << comprimido << endl;
    cout << "Texto descomprimido: " << descomprimido << endl;

    if (texto == descomprimido)
    {
        cout << "La descompresion fue correcta." << endl;
    }
    else
    {
        cout << "La descompresion fue incorrecta." << endl;
    }
}


void pro2()
{
    char texto[1000];

    cout << endl;
    cout << "Ingrese el texto: ";
    cin.ignore(1000, '\n');
    cin.getline(texto, 1000);

    int longitud = longitudTexto(texto);
    int cantidadPares = 0;

    ParLZ78* pares = comprimirLZ78(texto, longitud, &cantidadPares);

    cout << endl;
    cout << "Pares generados:" << endl;

    for (int i = 0; i < cantidadPares; i++)
    {
        cout << "(" << pares[i].indice << ", ";

        if (pares[i].caracter == '\0')
        {
            cout << "FIN";
        }
        else
        {
            cout << pares[i].caracter;
        }

        cout << ") ";
    }

    cout << endl;

    int longitudDescomprimida = 0;
    char* descomprimido = descomprimirLZ78(pares, cantidadPares,
                                           longitud, &longitudDescomprimida);

    cout << "Texto original: " << texto << endl;
    cout << "Texto descomprimido: " << descomprimido << endl;

    if (longitud == longitudDescomprimida)
    {
        bool iguales = true;

        for (int i = 0; i < longitud; i++)
        {
            if (texto[i] != descomprimido[i])
            {
                iguales = false;
            }
        }

        if (iguales)
        {
            cout << "La descompresion fue correcta." << endl;
        }
        else
        {
            cout << "La descompresion fue incorrecta." << endl;
        }
    }
    else
    {
        cout << "La descompresion fue incorrecta." << endl;
    }

    delete[] pares;
    delete[] descomprimido;
}


void pro3()
{
    char texto[1000];
    int rotacion;
    int claveNumero;

    cout << endl;
    cout << "Ingrese los datos comprimidos: ";
    cin.ignore(1000, '\n');
    cin.getline(texto, 1000);

    int cantidad = longitudTexto(texto);

    cout << "Ingrese la cantidad de rotaciones (1 a 7): ";
    cin >> rotacion;

    while (cin.fail() || rotacion <= 0 || rotacion >= 8)
    {
        cout << "Ingrese una cantidad valida entre 1 y 7: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> rotacion;
    }

    cout << "Ingrese la clave (0 a 255): ";
    cin >> claveNumero;

    while (cin.fail() || claveNumero < 0 || claveNumero > 255)
    {
        cout << "Ingrese una clave valida entre 0 y 255: ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> claveNumero;
    }

    unsigned char* datos = new unsigned char[cantidad];

    for (int i = 0; i < cantidad; i++)
    {
        datos[i] = (unsigned char)texto[i];
    }

    unsigned char clave = (unsigned char)claveNumero;

    encriptar(datos, cantidad, rotacion, clave);

    cout << endl;
    cout << "Datos originales: " << texto << endl;
    cout << "Datos encriptados:" << endl;

    for (int i = 0; i < cantidad; i++)
    {
        cout << (int)datos[i] << " ";
    }

    cout << endl;

    desencriptar(datos, cantidad, rotacion, clave);

    cout << "Datos desencriptados: ";

    for (int i = 0; i < cantidad; i++)
    {
        cout << (char)datos[i];
    }

    cout << endl;

    bool correcto = true;

    for (int i = 0; i < cantidad; i++)
    {
        if (datos[i] != (unsigned char)texto[i])
        {
            correcto = false;
        }
    }

    if (correcto)
    {
        cout << "La desencriptacion fue correcta." << endl;
    }
    else
    {
        cout << "La desencriptacion fue incorrecta." << endl;
    }

    delete[] datos;
}


int main()
{
    int x = 1;

    while (x != 0)
    {
        cout << "-------------------------------" << endl;
        cout << "         Ejercicios" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Compresion y descompresion RLE" << endl;
        cout << "2. Compresion y descompresion LZ78" << endl;
        cout << "3. Encriptacion y desencriptacion" << endl;
        cout << "0. Salir" << endl;

        cout << endl;
        cout << "Que ejercicio revisamos? ";
        cin >> x;

        while (cin.fail())
        {
            cout << "Ingrese una opcion valida: ";
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> x;
        }

        switch (x)
        {
        case 1:
            pro1();
            break;

        case 2:
            pro2();
            break;

        case 3:
            pro3();
            break;

        case 0:
            cout << "Chaolin Pinguin" << endl;
            break;

        default:
            cout << "Opcion invalida, sigue intentando." << endl;
        }

        cout << endl;
    }

    return 0;
}