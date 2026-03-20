#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class TablaFrecuenciaExtendida {
private:
    vector<double> datos;
    int n;

public:
    TablaFrecuenciaExtendida(vector<double> d) {
        datos = d;
        n = d.size();
    }

    void calcular() {
        // 1. Encontrar min y max
        double min = datos[0], max = datos[0];

        for (int i = 1; i < n; i++) {
            if (datos[i] < min) min = datos[i];
            if (datos[i] > max) max = datos[i];
        }

        // 2. Número de clases (Sturges)
        int k = 1 + 3.322 * log10(n);

        // 3. Amplitud
        double rango = max - min;
        double amplitud = rango / k;

        double limiteInferior = min;

        int F_acum = 0;
        double fr_acum = 0;

        cout << "Clase\tMarca\tf\tF\tfr\tFr" << endl;

        for (int i = 0; i < k; i++) {
            double limiteSuperior = limiteInferior + amplitud;

            int f = 0;

            for (int j = 0; j < n; j++) {
                if (datos[j] >= limiteInferior && datos[j] < limiteSuperior) {
                    f++;
                }
            }

            double marca = (limiteInferior + limiteSuperior) / 2;

            F_acum += f;
            double fr = (double)f / n;
            fr_acum += fr;

            cout << "[" << limiteInferior << "-" << limiteSuperior << "]\t"
                 << marca << "\t"
                 << f << "\t"
                 << F_acum << "\t"
                 << fr << "\t"
                 << fr_acum << endl;

            limiteInferior = limiteSuperior;
        }
    }
};

int main() {
    vector<double> datos = {
        10, 12, 15, 18, 20, 22, 25, 27, 30, 35,
        40, 42, 45, 48, 50, 52, 55, 58, 60, 65,
        70, 72, 75, 78, 80, 82, 85, 88, 90, 95
    };

    TablaFrecuenciaExtendida tabla(datos);

    tabla.calcular();

    return 0;
}
