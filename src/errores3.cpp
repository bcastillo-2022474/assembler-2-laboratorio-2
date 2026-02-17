#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Ingrese n (1..20): ";
    cin >> n;

    const int limite = n;
    if (n > 20) n = 20;

    vector<int> valores(limite);

    for (int i = 0; i < limite; i++) {
        valores[i] = i * i;
    }

    int suma = 0;
    for (int x : valores) {
        suma += x;
    }

    cout << "Suma de cuadrados: " << suma << endl;
    return 0;
}
