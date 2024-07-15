#include <iostream>
#include <iomanip>
#include <vector>
#include <functional>
using namespace std;
#define e = 2.71828;
#define pi = 3,14159;

void linha(int num = 20, char ch = '=');
function<double(double)> lagrange(const vector<double>& Xs, const vector<double>& Ys);

int main() {
    system("chcp 1252 > nul");

    vector<double> Xs = { -1.0, 0.0, 2.0 };
    vector<double> Ys = { 4.0, 1.0, -1.0 };

    cout << "Pontos [x, y]: " << endl;
    for (size_t i = 0; i < Xs.size(); i++)
    {
        cout << "Ponto " << i << ": ";
        cout << fixed << setprecision(1) << "[" << setw(4) << Xs[i] << ", " << setw(4) << Ys[i] << "]" << endl;
    }

    linha(50); // Adicionando a chamada correta para a função linha()

    cout << "O polinômio que passa pelos pontos acima é:\n" << endl;

    // Chamando a função lagrange para obter o polinômio
    auto polinomio = lagrange(Xs, Ys);

    // Exibindo o polinômio na forma polinomial
    cout << "P(x) = ";
    for (size_t i = 0; i < Xs.size(); ++i) {
        if (i != 0) {
            cout << " + ";
        }
        cout << Ys[i];
        for (size_t j = 0; j < Xs.size(); ++j) {
            if (j != i) {
                cout << " * (x - " << Xs[j] << ") / (" << Xs[i] << " - " << Xs[j] << ")";
            }
        }
    }
    cout << "\n\n";

    linha(50);

    // Configurando a precisão de saída para evitar arredondamentos
    cout << fixed << setprecision(3);

    // Perguntando ao usuário se deseja interpolar valores
    char resposta;
    cout << "Deseja interpolar valores (s/n)? ";
    cin >> resposta;
    if (resposta == 's' || resposta == 'S') {
        do {
            double valor;

            cout << "Digite o valor a ser interpolado (ou digite uma letra para sair): ";
            cin >> valor;

            if (!cin.good()) {
                break;
            }

            // Interpolando o valor usando o polinômio
            double resultado = polinomio(valor);

            cout << "O valor interpolado em x = " << valor << " é: " << resultado << endl;
        } while (true); // Loop infinito, será interrompido quando o usuário pressionar Enter
    }

    return 0;
}

void linha(int num, char ch) {
    for (size_t i = 0; i < num; i++)
    {
        cout << ch;
    }
    cout << "\n";
}

function<double(double)> lagrange(const vector<double>& Xs, const vector<double>& Ys) {
    return [=](double x) {
        double result = 0.0;
        for (size_t i = 0; i < Xs.size(); ++i) {
            double term = Ys[i];
            for (size_t j = 0; j < Xs.size(); ++j) {
                if (j != i) {
                    term *= (x - Xs[j]) / (Xs[i] - Xs[j]);
                }
            }
            result += term;
        }

        return result;
    };
}