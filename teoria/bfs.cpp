#include <iostream>
#include <queue>

using namespace std;

using Grafo = vector<vector<int>>;
Grafo g;
int V, A;

/*
    7 9
    0 1
    0 2
    0 5
    1 2
    2 3
    2 4
    3 4
    3 5
    4 6
*/

vector<int> bfs(int origen){ // Coste de recorrido proporcional al número de vértice y aristas desde el origen que no es mayor que el del grafo. O(V+A)
    vector<int> dist(V, -1);
    queue<int> q;

    q.push(origen);

    dist[origen] = 0;

    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int w : g[v]){
            if(dist[w] == -1){
                // No visitado
                dist[w] = dist[v] + 1;
                q.push(w);
            }
        }

    }

    return dist;

}

// A veces queremos saber un recorrido mínimo dentro de un grafo -> BFS
// Recorrido en anchura
/*
    El recorrido en anchura (BFS) visita primero todos los vértices
    alcanzables siguiendo nua arista (a distancia 1); luego visita
    todos los vértices alcanzables utilizando dos aristas (a distancia 2);
    y asi sucesivamente.

    Para lograrlo hace uso de una COLA (FIFO).
*/

int main(){
    cin >> V >> A;
    g.assign(V, {});
    for(int i=0;i<A;i++){
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist = bfs(0);

    for(int v=1;v<V;v++){
        if(dist[v] < 0){
            cout << v << " inalcanzable\n";
        }else{
            cout << v << " dist " << dist[v] << "\n";
        }
    }

}