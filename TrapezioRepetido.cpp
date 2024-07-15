#include <iostream>	
#include <iomanip>
#include <vector>
using namespace std;
#define e = 2.71828;
#define pi = 3,14159;

void linha(int num = 20, char ch = '=');
double trapezioSimples(vector<double> vet, const double n, const double a, const double b);
double funcao(double x) {
    return 1 / x;
}

int main() {
    system("chcp 1252 > nul");

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

    vector<double> vet {3.12014, 4.2569, 6.0424, 8.03014, 10.4667};

    linha(30);

    cout << "O cálculo da área da função definida é: " << fixed << setprecision(3) << trapezioSimples(vet, n, a, b) << endl;

	return 0;
}

void linha(int num, char ch) {
    for (size_t i = 0; i < num; i++)
    {
        cout << ch;
    }
    cout << "\n";
}

double trapezioSimples(vector<double> vet, const double n, const double a, const double b) {
    double integral = 0.0, h = (b - a) / n;

    for (size_t i = 0; i <= n; i += n)
    {
        if (i == 0) {
            for (size_t j = 1; j <= (n - 1); j++) {
                integral += vet[j];
            }
            integral *= 2;
        }
        integral += vet[i];
    }

    return integral * (h/2);
}