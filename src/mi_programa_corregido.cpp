// Calculadora de calificaciones estudiantiles - VERSION CORREGIDA
#include <iostream>
#include <string>
#include <iomanip>  // CORRECCION 1: Se agrega include necesario para fixed y setprecision

using namespace std;

int main() {
    const int MAX_NOTAS = 5;
    const double NOTA_MINIMA = 61.0;

    string nombre;
    cout << "Nombre del estudiante: ";
    getline(cin, nombre);

    double suma = 0.0;
    int i = 0;

    while (i < MAX_NOTAS) {
        double nota;
        cout << "Ingrese nota " << (i + 1) << " (0-100): ";
        cin >> nota;

        // CORRECCION 2: Se usa >= en lugar de = para comparar correctamente
        if (nota >= 0 && nota <= 100) {
            suma += nota;
        } else {
            cout << "Nota invalida, se usara 0." << endl;
        }
        i++;
    }

    // CORRECCION 3: Se elimina la conversion a int para preservar los decimales
    double promedio = suma / MAX_NOTAS;

    cout << fixed << setprecision(2);
    cout << "\nEstudiante: " << nombre << endl;
    cout << "Promedio: " << promedio << endl;

    // CORRECCION 4: Logica corregida: aprobado si promedio >= NOTA_MINIMA
    if (promedio >= NOTA_MINIMA) {
        cout << "Estado: APROBADO" << endl;
    } else {
        cout << "Estado: REPROBADO" << endl;
    }

    // CORRECCION 5: El ciclo ahora va de 1 a MAX_NOTAS (sin el +1 extra)
    cout << "\nNotas posibles del 1 al " << MAX_NOTAS << ":" << endl;
    for (int j = 1; j <= MAX_NOTAS; j++) {
        cout << "  Nota #" << j << endl;
    }

    // Conversion de promedio a entero para mostrar categoria
    char categoria;
    if (promedio >= 90.0)      categoria = 'A';
    else if (promedio >= 80.0) categoria = 'B';
    else if (promedio >= 70.0) categoria = 'C';
    else if (promedio >= 61.0) categoria = 'D';
    else                       categoria = 'F';

    cout << "Categoria: " << categoria << endl;

    return 0;
}
