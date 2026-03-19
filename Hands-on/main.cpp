#include <iostream>
#include <vector>
using namespace std;

// Clase que implementa la regresión lineal simple
class SimpleLinearRegression {
private:
    vector<double> x; // Advertising
    vector<double> y; // Sales
    double B0; // Intercepto
    double B1; // Pendiente

public:
    // Constructor
    SimpleLinearRegression(vector<double> xData, vector<double> yData) {
        x = xData;
        y = yData;
        B0 = 0;
        B1 = 0;
    }

    // Método para calcular la regresión
    void calcular() {
        int n = x.size();
        double sumX = 0, sumY = 0;

        // Calcular sumas
        for (int i = 0; i < n; i++) {
            sumX += x[i];
            sumY += y[i];
        }

        double meanX = sumX / n;
        double meanY = sumY / n;

        double numerador = 0;
        double denominador = 0;

        // Fórmula de B1
        for (int i = 0; i < n; i++) {
            numerador += (x[i] - meanX) * (y[i] - meanY);
            denominador += (x[i] - meanX) * (x[i] - meanX);
        }

        B1 = numerador / denominador;

        // Fórmula de B0
        B0 = meanY - (B1 * meanX);
    }

    // Método para imprimir ecuación
    void imprimirEcuacion() {
        cout << "Ecuacion de regresion:\n";
        cout << "y = " << B0 << " + " << B1 << "x\n";
    }

    // Método para predecir
    double predecir(double xNuevo) {
        return B0 + (B1 * xNuevo);
    }

    // Mostrar predicciones
    void mostrarPredicciones() {
        double nuevosX[5] = {60, 65, 70, 75, 80};

        cout << "\nPredicciones:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Advertising: " << nuevosX[i]
                 << " -> Sales: " << predecir(nuevosX[i]) << endl;
        }
    }
};

// MAIN
int main() {
    // Dataset HARDCODED
    vector<double> advertising = {23, 26, 30, 34, 43, 48, 52, 57, 58};
    vector<double> sales =       {651, 762, 856, 1063, 1190, 1298, 1421, 1440, 1518};

    // Crear objeto
    SimpleLinearRegression modelo(advertising, sales);

    // Ejecutar pasos
    modelo.calcular();
    modelo.imprimirEcuacion();
    modelo.mostrarPredicciones();

    return 0;
}
