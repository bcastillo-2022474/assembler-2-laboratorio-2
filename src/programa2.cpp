#include <iostream>
using namespace std;

void intercambiar(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    int x, y;
    cout << "Ingrese x y y: ";
    cin >> x >> y;

    intercambiar(x, y);

    cout << "Despues del intercambio: x=" << x << " y=" << y << endl;
    return 0;
}
