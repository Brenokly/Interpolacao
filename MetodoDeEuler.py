import numpy as np # type: ignore
import matplotlib.pyplot as plt # type: ignore

def euler_method(func, x0, y0, h, x_end):
    """
    Implementação do Método de Euler para resolver uma equação diferencial.

    Args:
        func: A função que define a equação diferencial.
        x0: O valor inicial de x.
        y0: O valor inicial de y.
        h: O tamanho do passo.
        x_end: O valor final de x.

    Returns:
        Arrays contendo os valores de x e y.
    """
    n_steps = int((x_end - x0) / h) + 1
    x_values = np.linspace(x0, x_end, n_steps)
    y_values = np.zeros(n_steps)
    y_values[0] = y0

    for i in range(1, n_steps):
        y_prime = func(x_values[i-1], y_values[i-1])
        y_values[i] = y_values[i-1] + h * y_prime

    return x_values, y_values

# Define a equação diferencial para calcular a taxa de variação da temperatura de uma chapa metálica
def diff_eq(x, y):
    return (-1/(300*900)) * (5.67*10**-8 * 0.8 * ((y**4 - (300**4)) + 30*(y - 300)))

# Condições iniciais
x0 = 1
y0 = 1

# Parâmetros para o método de Euler
h = 0.04
x_end = 180

# Aplica o Método de Euler
x_values, y_values = euler_method(diff_eq, x0, y0, h, x_end)

# Plota o gráfico
plt.plot(x_values, y_values, label='Método de Euler')
plt.xlabel('x')
plt.ylabel('y')
plt.title('Solução da Equação Diferencial usando o Método de Euler')
plt.legend()
plt.grid(True)
plt.show()