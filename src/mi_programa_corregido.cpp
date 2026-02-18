// Calculadora de puntos para torneo de videojuego — VERSION CORREGIDA
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int PUNTAJE_BASE = 100;
    string jugador;

    cout << "Nombre del jugador: ";
    cin >> jugador;

    // CORRECCION 1: Usar int en lugar de unsigned int para permitir valores negativos
    // sin riesgo de wrapping aritmetico.
    int vidas = 3;
    int penalizacion;
    cout << "Ingrese penalizacion de vidas: ";
    cin >> penalizacion;
    vidas -= penalizacion;
    cout << "Vidas restantes: " << vidas << endl;

    // CORRECCION 2: Agregar llaves al cuerpo del if exterior para que el else
    // quede correctamente encerrado y no haya ambiguedad de a quien pertenece.
    int puntos = PUNTAJE_BASE;
    if (vidas > 0) {
        if (puntos > 50)
            cout << jugador << " avanza al siguiente nivel." << endl;
        else
            cout << "Puntos insuficientes." << endl;
    }

    // CORRECCION 3: Agregar break faltante en case 1 para evitar el fallthrough.
    int rango = puntos / 50;
    switch (rango) {
        case 2:
            cout << "Rango: Oro" << endl;
            break;
        case 1:
            cout << "Rango: Plata" << endl;
            break;  // break agregado
        case 0:
            cout << "Rango: Bronce" << endl;
            break;
        default:
            cout << "Rango: Sin clasificar" << endl;
    }

    // CORRECCION 4: Eliminar la redeclaracion de bonus dentro del bloque.
    // Se opera directamente sobre la variable exterior.
    double bonus = 20.0;
    {
        bonus += 10;    // modifica la variable exterior: 20.0 -> 30.0
        cout << "Bonus aplicado: " << bonus << endl;
    }
    cout << "Bonus final del jugador: " << bonus << endl;  // imprime 30

    // CORRECCION 5: Cast explicito de size_t a int para que la comparacion
    // sea entre dos tipos con signo y el comportamiento sea el esperado.
    int intentos = 0;
    intentos--;  // intentos = -1
    if (intentos < static_cast<int>(jugador.size())) {
        cout << "Acceso permitido para: " << jugador << endl;  // ahora se ejecuta correctamente
    } else {
        cout << "Acceso denegado." << endl;
    }

    return 0;
}
