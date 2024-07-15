#include <iostream>  
#include <iomanip>
#include <vector>
using namespace std;

#define e 2.71828
#define pi 3.14159

void linha(int num = 20, char ch = '=');
double Simpson38(const double n, const double a, const double b, vector<double>& Xs);
double funcao(double x) {
    return 1 / x;
}

int main() {
    system("chcp 1252 > nul");

    vector<double> Xs = { 1.0, 0.75, 0.6, 0.5, 0.4285, 0.375, 0.3333 }; // precisa ter um número ímpar de pontos

    cout << "Defina qual o intervalo [a,b]:" << endl;
    double a = 0, b = 0;
    cout << "A: ";
    cin >> a;
    cout << "B: ";
    cin >> b;

    linha(30);

    cout << "Qual o número de Partições? ";
    double n;
    cin >> n;

    linha(30);

    cout << "O cálculo da área da função definida é: " << fixed << setprecision(4) << Simpson38(n, a, b, Xs) << endl;

    return 0;
}

void linha(int num, char ch) {
    for (size_t i = 0; i < num; i++)
    {
        cout << ch;
    }
    cout << "\n";
}

double Simpson38(const double n, const double a, const double b, vector<double>& Xs) {
    double h = (b - a) / n, soma = funcao(a) + funcao(b), soma1 = 0.0, soma2 = 0.0;

    for (size_t i = 1; i < n; i++) {
        if (i % 3 == 0) {
            soma2 += funcao(a + h * i);
        }
        else {
            soma1 += funcao(a + h * i);
        }
    }

    for (double x : Xs) {
        soma += 2 * funcao(a + x * (b - a));
    }

    soma += 3 * soma1 + 2 * soma2;

    return (3 * h / 8) * soma;
}
