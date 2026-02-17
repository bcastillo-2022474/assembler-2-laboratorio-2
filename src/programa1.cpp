#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    int n;
    cout << "Cuantos valores desea ingresar? ";
    cin >> n;

    int suma = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cout << "Valor " << (i + 1) << ": ";
        cin >> x;
        suma += x;
    }

    double promedio = suma / n;

    cout << fixed << setprecision(2);
    cout << "Promedio: " << promedio << endl;

    return 0;
}
