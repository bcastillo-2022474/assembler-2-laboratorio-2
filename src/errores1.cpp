#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int pedirEntero(const string& msg) {
    int x;
    cout << msg;
    cin >> x;
    return x;
}

int main() {
    int n = pedirEntero("Cuantas notas desea ingresar? ");
    int suma = 0;

    for (int i = 1; i <= n; i++) {
        int nota = pedirEntero("Nota " + to_string(i) + ": ");
        suma += nota;
    }

    double promedio = (double)suma / n;
    cout << "Promedio: " << fixed << setprecision(2) << promedio << endl;

    return 0;
}
