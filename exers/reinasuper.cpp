#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Caja {
    int id;
    int espera;
};


bool operator > (Caja a, Caja b) {
    if (a.espera >  b.espera) return true;
    else if (a.espera == b.espera && a.id > b.id) return true;
    else return false;
}

void reinaSuper() {
    int N, C;
    cin >> N >> C;
    while (N != 0 && C != 0) {

        priority_queue<Caja, vector<Caja>, greater<Caja>> cajas;

        for (int i = 0; i < N; i++) { // Relleno de las cajas
            Caja miCaja;
            miCaja.id = i;
            miCaja.espera = 0;
            cajas.push(miCaja);
        }

        string clientes;

        for (int i = 0; i < C; i++) {

            int espera;
            cin >> espera;

            Caja miCaja = cajas.top();
            cajas.pop();
            miCaja.espera += espera;
            cajas.push(miCaja);
        }

        cout << (cajas.top().id + 1) << "\n";
        cin.ignore();
        cin >> N >> C;

    }


}

int main(){
    reinaSuper();
}