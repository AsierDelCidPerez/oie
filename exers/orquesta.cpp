#include <iostream>
#include <queue>

using namespace std;

struct instrumento {
    int id;
    int max;
    int nMusicos;
    int partituras;
};

bool operator < (instrumento a, instrumento b){
    if(a.max < b.max) return true;
    if(a.max == b.max && a.id < b.id) return true;
    return false;
}

int main(){
    int P, N;

    while(cin >> P >> N){ // P (n Partituras) >= N (n Instrumentos distintos)
        priority_queue<instrumento> instrumentos;
        for(int i=0;i<N;i++) { // ¿Cuántos músicos hay por instrumento
            int musicos;
            cin >> musicos;
            instrumento m;
            m.id = i;
            m.nMusicos = musicos;
            m.partituras = 1;
            m.max = musicos / 1;

            instrumentos.push(m);
        }

        P-=N;

        while(P > 0){
            instrumento max = instrumentos.top();
            max.partituras++;
            P--;
            if(max.nMusicos % max.partituras == 0){
                max.max = max.nMusicos / max.partituras;
            }else{
                max.max = max.nMusicos / max.partituras + 1;
            }
            instrumentos.pop();
            instrumentos.push(max);
        }

        cout << instrumentos.top().max << "\n";

    }

}