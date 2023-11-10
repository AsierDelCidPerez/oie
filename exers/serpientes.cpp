#include <iostream>
#include <numeric>
#include <vector>
#include <queue>


using namespace std;

void serpientes(){
    
    int N, K, S, E;

    while(cin >> N >> K >> S >> E){

        if(N == 0 && K == 0 && S == 0 && E == 0) break;

        vector<int> saltos(N*N); // Contamos el 0.

        iota(saltos.begin(), saltos.end(), 0); // Relleno inicial

        for(int i = 0; i < E + S; i++){ // Ejecutamos E+S veces (tanatas serpientes y escaleras haya)
            int o, d; cin >> o >> d; // Tratamos igual a las escaleras y serpientes, como redirecciones.
            saltos[o-1] = d-1;
        }

        vector<int> dist(N*N, -1);

        queue<int> q;

        q.push(0);

        dist[0] = 0;

        while(!q.empty()){
            int v = q.front(); q.pop();
            int ent = false;
            for(int i=1;i <= K && K + v < N*N;i++){
                int w = saltos[i+v];
                if(dist[w] == -1){
                    q.push(w);
                    dist[w] = dist[v] + 1;
                    if(w == N*N-1){
                        cout << dist[v]+1 << "\n";
                        ent = true;
                        break;
                    }
                }
            }
            if (ent){
                break;
            }
        }

    }

}

int main(){

    serpientes();

}