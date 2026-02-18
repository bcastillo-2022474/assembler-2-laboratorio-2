// Calculadora de puntos para torneo de videojuego
// NOTA: Contiene 5 errores relacionados con quirks y sintaxis de C++
#include <iostream>
#include <string>
using namespace std;

int main() {
    const int PUNTAJE_BASE = 100;
    string jugador;

    cout << "Nombre del jugador: ";
    cin >> jugador;

    // --- ERROR 1: unsigned int underflow ---
    // Si penalizacion > vidas, la resta produce wrapping: vidas pasa a ~4,000,000,000
    // porque unsigned no puede representar negativos, simplemente da la vuelta.
    unsigned int vidas = 3;
    int penalizacion;
    cout << "Ingrese penalizacion de vidas: ";
    cin >> penalizacion;
    vidas -= penalizacion;
    cout << "Vidas restantes: " << vidas << endl;

    // --- ERROR 2: Dangling else ---
    // La indentacion sugiere que el else corresponde al if (vidas > 0),
    // pero en C++ el else siempre se asocia al if mas cercano (if puntos > 50).
    // Si vidas == 0, no se imprime absolutamente nada.
    int puntos = PUNTAJE_BASE;
    if (vidas > 0)
        if (puntos > 50)
            cout << jugador << " avanza al siguiente nivel." << endl;
        else
            cout << "Puntos insuficientes." << endl;

    // --- ERROR 3: Switch fallthrough ---
    // Falta break en case 1: si rango es 1, imprime "Plata" y luego cae
    // directo al case 0 imprimiendo "Bronce" tambien.
    int rango = puntos / 50;
    switch (rango) {
        case 2:
            cout << "Rango: Oro" << endl;
            break;
        case 1:
            cout << "Rango: Plata" << endl;
            // falta break aqui
        case 0:
            cout << "Rango: Bronce" << endl;
            break;
        default:
            cout << "Rango: Sin clasificar" << endl;
    }

    // --- ERROR 4: Variable shadowing ---
    // Se declara un nuevo 'bonus' (int) dentro del bloque que oculta al exterior (double).
    // Las operaciones dentro del bloque modifican la copia interior, nunca la exterior.
    double bonus = 20.0;
    {
        int bonus = 5;
        bonus += 10;    // modifica la interior (5 -> 15), la de afuera sigue en 20.0
        cout << "Bonus aplicado: " << bonus << endl;
    }
    cout << "Bonus final del jugador: " << bonus << endl;  // imprime 20, no 15

    // --- ERROR 5: Comparacion signed/unsigned ---
    // jugador.size() retorna size_t (unsigned). Al comparar con un int negativo,
    // C++ convierte el int a unsigned: -1 se vuelve ~18 quintillones.
    // La condicion (enorme_numero < 6) es false, aunque -1 < 6 parece obvio.
    int intentos = 0;
    intentos--;  // intentos = -1
    if (intentos < jugador.size()) {
        cout << "Acceso permitido para: " << jugador << endl;
    } else {
        cout << "Acceso denegado." << endl;  // se ejecuta esto, inesperadamente
    }

    return 0;
}
