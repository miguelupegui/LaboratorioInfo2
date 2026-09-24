#include <iostream>
#include "funciones.h"

using namespace std;


void pro51()
{
    string texto;

    cout << endl;
    cout << "Ingrese el texto: ";
    cin.ignore();
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
            pro51();
            break;

        case 2:
            break;

        case 3:
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