#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TablaFrecuencias {
private:
    vector<double> datos;
    map<double, int> frecuencia;

public:
    TablaFrecuencias(vector<double> d) {
        datos = d;
    }

    void calcular() {
        for (int i = 0; i < datos.size(); i++) {
            frecuencia[datos[i]]++;
        }
    }

    void mostrar() {
        int n = datos.size();

        cout << "Valor\tf\tfr\t%" << endl;

        for (auto it = frecuencia.begin(); it != frecuencia.end(); it++) {
            double valor = it->first;
            int f = it->second;
            double fr = (double)f / n;
            double porcentaje = fr * 100;

            cout << valor << "\t" << f << "\t" << fr << "\t" << porcentaje << "%" << endl;
        }
    }
};

int main() {
    vector<double> datos = {2, 3, 2, 5, 3, 2, 4, 5, 3, 4};

    TablaFrecuencias tabla(datos);

    tabla.calcular();
    tabla.mostrar();

    return 0;
}