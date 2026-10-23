#include <iostream>
#include <string>
#include "red.h"

using namespace std;


int leerCosto()
{
    int costo;

    cout << "Ingrese el costo del enlace: ";
    cin >> costo;

    while (cin.fail() || costo <= 0)
    {
        cout << "Ingrese un costo valido (mayor a 0): ";
        cin.clear();
        cin.ignore(1000, '\n');
        cin >> costo;
    }

    return costo;
}


void pro1(Red* red)
{
    string nombre;

    cout << endl;
    cout << "Ingrese el nombre del enrutador: ";
    cin >> nombre;

    if (red->agregarEnrutador(nombre))
    {
        cout << "Enrutador " << nombre << " agregado." << endl;
    }
    else
    {
        cout << "Ya existe un enrutador con ese nombre." << endl;
    }
}


void pro2(Red* red)
{
    string nombre;

    cout << endl;
    cout << "Ingrese el nombre del enrutador a eliminar: ";
    cin >> nombre;

    if (red->eliminarEnrutador(nombre))
    {
        cout << "Enrutador " << nombre << " eliminado junto con sus enlaces." << endl;
    }
    else
    {
        cout << "Ese enrutador no existe." << endl;
    }
}


void pro3(Red* red)
{
    string origen;
    string destino;

    cout << endl;
    cout << "Ingrese el primer enrutador: ";
    cin >> origen;
    cout << "Ingrese el segundo enrutador: ";
    cin >> destino;

    int costo = leerCosto();

    if (red->agregarEnlace(origen, destino, costo))
    {
        cout << "Enlace " << origen << " <-> " << destino
             << " con costo " << costo << " guardado." << endl;
    }
    else
    {
        cout << "No se pudo crear el enlace. Revise que ambos enrutadores existan y sean distintos." << endl;
    }
}


void pro4(Red* red)
{
    string origen;
    string destino;

    cout << endl;
    cout << "Ingrese el primer enrutador: ";
    cin >> origen;
    cout << "Ingrese el segundo enrutador: ";
    cin >> destino;

    if (red->eliminarEnlace(origen, destino))
    {
        cout << "Enlace " << origen << " <-> " << destino << " eliminado." << endl;
    }
    else
    {
        cout << "Ese enlace no existe." << endl;
    }
}


void pro5(Red* red)
{
    cout << endl;
    red->imprimirTopologia();
}


int main()
{
    Red red;
    int x = 1;

    while (x != 0)
    {
        cout << "-------------------------------" << endl;
        cout << "      Red de enrutadores" << endl;
        cout << "-------------------------------" << endl;
        cout << "1. Agregar enrutador" << endl;
        cout << "2. Eliminar enrutador" << endl;
        cout << "3. Agregar o modificar enlace" << endl;
        cout << "4. Eliminar enlace" << endl;
        cout << "5. Mostrar enrutadores y vecinos" << endl;
        cout << "0. Salir" << endl;

        cout << endl;
        cout << "Que hacemos? ";
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
            pro1(&red);
            break;

        case 2:
            pro2(&red);
            break;

        case 3:
            pro3(&red);
            break;

        case 4:
            pro4(&red);
            break;

        case 5:
            pro5(&red);
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
