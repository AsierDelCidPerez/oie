#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, K;

using info = pair<int, int>; // Anillo y grado
using estado = pair<int, info>;

vector<vector<info>> tuneles;
vector<int> costeCaminado;

vector<vector<int>> dist;

int d, g, e, h; // Comienza (anillo y grado); finaliza (anillo y grado)

void resuelve(){
    priority_queue<estado, vector<estado>, greater<estado>> pq;

    dist.assign(N, vector<int>(360, -1));
    dist[d][g] = 0;
    pq.push({0, {d, g}});

    while(!pq.empty()){
        auto [cst, v] = pq.top(); pq.pop();
        if(dist[v.first][v.second] != -1 && cst > dist[v.first][v.second]) continue;
        if(dist[e][h] != -1 && cst > dist[e][h]) break;
        // int min=-1, minLabel=-1;

        int coster = cst;
        if(v.first == e) {
            int transfer = (abs(v.second - h));
            coster += min(transfer, 360 - transfer) * costeCaminado[e];
            if(dist[v.first][h] == -1 || coster < dist[v.first][h]) {
                dist[v.first][h] = coster;
                // pq.push({nCoste, {tun.first, h}});
            }
        }
        for(info tun : tuneles[v.first]){
            int nCoste = cst;
            int transfer = abs(tun.second - v.second);
            nCoste += min(transfer, 360-transfer) * costeCaminado[v.first];

            if(dist[tun.first][tun.second] == -1 || nCoste < dist[tun.first][tun.second]){
                dist[tun.first][tun.second] = nCoste;
                pq.push({nCoste, {tun.first, tun.second}});
            }
            
        }


    }

    if(dist[e][h] == -1){
        cout << "IMPOSIBLE\n";
    }else{
        cout << dist[e][h] << "\n";
    }
}

int main(){
     int T;
     cin >> T;
     while(T--){
        cin >> N >> K;
        tuneles.assign(N, {});
        for(int i=0;i<K;i++){
            int a, aph; cin >> a >> aph; a--;
            tuneles[a].push_back({a+1, aph});
            tuneles[a+1].push_back({a, aph});
        }
        costeCaminado.assign(N, -1);
        for(int i=0;i<N;i++){
            int c; cin >> c;
            costeCaminado[i] = c;
        }

        cin >> d >> g >> e >> h;
        d--; e--;
        resuelve();

     }
}