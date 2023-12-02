#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> cargas;
using info = pair<int, int>; // coste (ms), v;
vector<vector<info>> links;
vector<int> dist;
vector<int> anteriores;

void dijkstra(){
    int origin = 0;
    int des = N-1;
    dist.assign(N, -1);
    anteriores.assign(N, -1);
    priority_queue<info, vector<info>, greater<info>> q;

    dist[origin] = cargas[origin];
    q.push({dist[origin], origin});

    while(!q.empty()){
        auto [c, v] = q.top(); q.pop();
        if(dist[v] < c) continue; // Optimización -> info antigua
        if(dist[des] < dist[v] && dist[des] != -1) continue; // Optimización. Ningún camino ya mayor que el encontrado al destino puede ser mejor.

        for(auto g : links[v]){
            if(dist[g.second] == -1 || dist[g.second] > dist[v] + g.first){
                anteriores[g.second] = v;
                dist[g.second] = dist[v] + g.first;
                q.push({dist[g.second], g.second});
            }
        }
    }

    if(dist[des] == -1){
        cout << "IMPOSIBLE\n";
    }else{
        cout << dist[des] << "\n";
    }

}

int main(){
    cin >> N;
    while(N != 0){
        // cargas.assign(N, -1);
        links.assign(N, {});
        cargas.assign(0, -1);
        for(int i=0;i<N;i++){
            int t;
            cin >> t;
            cargas.push_back(t);
        }

        cin >> M;

        for(int i=0;i<M;i++){
            int a, b, c;
            cin >> a >> b >> c; a--; b--;
            links[a].push_back({c + cargas[b], b});
            // cout << a << " -> " << b << " (" << c + cargas[b] << ")\n";
            // links[b].push_back({c, a});
        }

        dijkstra();
        // cout << minCoste() << "\n";
        cin >> N;
    }
}