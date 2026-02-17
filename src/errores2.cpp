#include <iostream>
using namespace std;

int main() {
    int opcion;

    cout << "Menu\n";
    cout << "1) Area de un cuadrado\n";
    cout << "2) Imprimir numeros del 1 al N\n";
    cout << "3) Salir\n";
    cout << "Seleccione una opcion: ";
    cin >> opcion;

    switch (opcion) {
        case 1:
            cout << "Ingrese el lado: ";
            double lado;
            cin >> lado;
            cout << "Area: " << lado * lado << endl;
            break;

        case 2: {
            int n;
            cout << "Ingrese N: ";
            cin >> n;

            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << endl;
            break;
        }

        case 3:
            cout << "Saliendo..." << endl;
            return 0;

        default:
            cout << "Opcion invalida" << endl;
    }

    cout << "Fin del programa" << endl
    return 0;
}
