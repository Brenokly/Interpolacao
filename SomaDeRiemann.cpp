#include <iostream>
#include <iomanip>
using namespace std;
#define e = 2.71828;
#define pi = 3,14159;

void linha(int num = 20, char ch = '=');
double somadeRiemann(const double n, const double a, const double b);
double funcao(double x) {
    return x * x;
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

    linha(30);

    cout << "O cálculo da área da função definida é: " << fixed << setprecision(3) << somadeRiemann(n, a, b) << endl;
    
	return 0;
}

void linha(int num, char ch) {
    for (size_t i = 0; i < num; i++)
    {
        cout << ch;
    }
    cout << "\n";
}

double somadeRiemann(const double n, const double a, const double b) {
    double soma = 0;
    double ci = 0;

    double h = (b - a) / n;
    for (size_t i = 0; i < n; i++)
    {
        double xi = a + h * i;
        double xj = a + h * (i + 1);
        ci = ((xj + xi) / 2); // pegando o ponto do meio
        soma += funcao(ci) * (xj - xi); // Delta X
    }

    return soma;
}