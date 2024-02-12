#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

void imprimirQueue(queue<int> cola){
    while(!cola.empty()){
        int v = cola.front(); cola.pop();
        cout << v << " ";
    }
    cout << "\n";
}

int main(){
    int N, M, T; // Tiempo que tarda en reprducirse 
    // Como máximo habrá N agrupaciones de células y M agrupaciones de yemas, donde las agrupaciones son conjuntos de ese tipo de ser que coinciden en su tiempo restante de reproducción

    while(cin >> N >> M >> T){
        queue<int> celulas;
        queue<int> yemas;

        for(int i=1;i<max(N, M);i++){
            if(i < N){
                celulas.push(0);
            }
            if(i < M){
                yemas.push(0);
            }
        }


        celulas.push(1);
        yemas.push(0);

        // imprimirQueue(celulas);
        // imprimirQueue(yemas);

        // T+=5;

        while(T--){ // Principio de progresión de la queue -> no varía su size.
            int k = celulas.front(); celulas.pop();
            int j = yemas.front(); yemas.pop();

            celulas.push(k+j); // Convertimos las (j) yemas que se convierten en adultas a celulas y las celulas que se reproducen reinician (k)
            yemas.push(k+j); // Se reproducen las (k) células y las (j) yemas.
            // imprimirQueue(celulas);
            // imprimirQueue(yemas);
        }

        int suma = 0;




        for(int i=0;i<max(N, M);i++){
            if(!celulas.empty()){
                suma += celulas.front(); celulas.pop();
            }
            if(!yemas.empty()){
                suma += yemas.front(); yemas.pop();
            }
        }

        cout << suma << "\n";
    }

}