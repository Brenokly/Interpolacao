#include <iostream>
#include <cmath>

using namespace std;

double f(double x, double y) {
    return x * x + y * y; // Exemplo de função, substitua pela sua função
}

double rungeKutta4(double x0, double y0, double x, double h) {
    int n = (int)((x - x0) / h);
    double k1, k2, k3, k4;

    double y = y0;
    for (int i = 1; i <= n; i++) {
        k1 = h * f(x0, y);
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1);
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2);
        k4 = h * f(x0 + h, y + k3);

        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        x0 = x0 + h;
    }

    return y;
}

int main() {
    system("chcp 1252 > nul");

    double x0 = 0, y = 1, x = 2, h = 0.2;

    cout << "O valor de y em x = " << x << " é " << rungeKutta4(x0, y, x, h) << endl;

    return 0;
}
