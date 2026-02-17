// Calculadora de calificaciones estudiantiles
// NOTA: Este archivo contiene 5 errores intencionales para el ejercicio 5.
#include <iostream>
#include <string>
// ERROR 1: Falta #include <iomanip> necesario para fixed y setprecision

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

        // ERROR 2: Condicion usa asignacion (=) en lugar de comparacion (>=)
        if (nota = 0 && nota <= 100) {
            suma += nota;
        } else {
            cout << "Nota invalida, se usara 0." << endl;
        }
        i++;
    }

    // ERROR 3: Division entera: suma es double pero MAX_NOTAS es int,
    // sin embargo se convierte a int antes de dividir perdiendo decimales
    int sumaEntera = (int)suma;
    double promedio = sumaEntera / MAX_NOTAS;

    cout << fixed << setprecision(2);  // necesita <iomanip>
    cout << "\nEstudiante: " << nombre << endl;
    cout << "Promedio: " << promedio << endl;

    // ERROR 4: Logica invertida en la condicion de aprobacion
    if (promedio < NOTA_MINIMA) {
        cout << "Estado: APROBADO" << endl;
    } else {
        cout << "Estado: REPROBADO" << endl;
    }

    // ERROR 5: El ciclo imprime un rango incorrecto (empieza en 1 deberia ser 0,
    // y usa <= MAX_NOTAS accediendo un elemento fuera del rango logico)
    cout << "\nNotas posibles del 1 al " << MAX_NOTAS << ":" << endl;
    for (int j = 1; j <= MAX_NOTAS + 1; j++) {
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
