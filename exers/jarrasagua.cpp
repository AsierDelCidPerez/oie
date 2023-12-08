#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> capacidades;
int D;

using estado = pair<int, int>;
vector<vector<estado>> anteriores;
vector<vector<int>> dist; // {trasvases, {a, b}}

void imprimirAnteriores(int a, int b){
    if(anteriores[a][b].first == -1 && anteriores[a][b].second == -1){
        cout << "(" << a << ", " << b << ")";
    }else{
        auto [x, y] = anteriores[a][b];
        imprimirAnteriores(x, y);
        cout << " -> (" << a << ", " << b << ")";
    }
}

void resuelve(){
    priority_queue<pair<int, estado>, vector<pair<int, estado>>, greater<pair<int, estado>>> pq;
    // Se comienza con la primera jarra llena y demás vacías
    
    pq.push({0, {capacidades[0], 0}});
    dist[8][0] = 0;
    while(!pq.empty()){
        auto [trasvases, estado] = pq.top();
        if(trasvases > dist[estado.first][estado.second]) continue;
        int actual[3] = {estado.first, estado.second, capacidades[0] - (estado.first + estado.second)};
        for(auto i : actual){
            if(i == D) {
                cout << trasvases << "\n"; 
                imprimirAnteriores(actual[0], actual[1]);
                return;
            }
        }

        for(int i=0;i<3;i++) { // El dador
            for(int j=0;j<3;j++) { // El recibidor
                if(i == j) continue;
                vector<int> cap;
                cap.assign(3, -1);
                int t;
                if(actual[i] > capacidades[j] - actual[j]){ // Máximo transferible capacidades[j] - actual[j]
                    t = capacidades[j] - actual[j];
                    cap[j] = capacidades[j];
                    cap[i] = actual[i] - capacidades[j] + actual[j];
                }else{
                    t = actual[i];
                    cap[i] = 0;
                    cap[j] = actual[j] + actual[i];

                }
                // int t = min(actual[i], capacidades[j]-actual[i]);
                t += trasvases;
                cap[3-i-j] = capacidades[0] - (cap[i] + cap[j]);
                if(dist[cap[0]][cap[1]] == -1 || t < dist[cap[0]][cap[1]]){
                    dist[cap[0]][cap[1]] = t;
                    anteriores[cap[0]][cap[1]] = {actual[0], actual[1]}; 
                    pq.push({t, {cap[0], cap[1]}});
                }
            }
        }

    }
    cout << "BOOM\n";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        capacidades.assign(3, -1);
        for(int i=0;i<3;i++){
            cin >> capacidades[i];
        }
        anteriores.assign(capacidades[0]+1, vector<estado>(capacidades[1]+1, {-1, -1}));
        dist.assign(capacidades[0]+1, vector<int>(capacidades[1]+1, -1));
        cin >> D;
        resuelve();
    }
}