#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using info = pair<int, int>;
int N, A;
vector<vector<info>> g;
vector<int> anteriores;
vector<int> dist;

void imprimirAnteriores(int des){
    if(anteriores[des] == -1){
        cout << (des+1);
    }else{
        imprimirAnteriores(anteriores[des]);
        cout << " -> " << (des+1);
    }
}

void resuelve(int origin, int des){
    dist.assign(N, -1);
    anteriores.assign(N, -1);

    priority_queue<info, vector<info>, greater<info>> q;
    q.push({0, origin});
    dist[origin] = 0;

    while(!q.empty()){
        auto [cost, v] = q.top(); q.pop();
        if(cost > dist[v]) continue; // info. antigua: si la distancia a un nodo es mayor que la que tenía asignada, significa que es info. antigua.
        if(dist[des] != -1 && dist[v] > dist[des]) continue; // Optimización: cuando nos interesa ir de origen a destino con un camino mínimo, podemos desechar todas aquellas opciones no mínimas.
        for(auto ady : g[v]){
            if(dist[ady.second] == -1 || dist[v] + ady.first < dist[ady.second]){
                anteriores[ady.second] = v;
                dist[ady.second] = dist[v] + ady.first;
                q.push({dist[ady.second], ady.second});
            }
        }
    }

    if(dist[des] == -1){
        cout << "NO LLEGA\n";
    }else{
        cout << dist[des] << ": ";
        imprimirAnteriores(des);
        cout << "\n";
    }
}

int main(){

    while(cin >> N >> A){
        
        g.assign(N, {});

        for(int i=0;i<A;i++){
            int a, b, c; 
            cin >> a >> b >> c; a--; b--;
            g[a].push_back({c, b});
            g[b].push_back({c, a});
        }

        int k;
        cin >> k;

        for(int i=0;i<k;i++){
            int a, b;
            cin >> a >> b;
            resuelve(a-1, b-1);
        }

        cout << "---\n";
    }

}