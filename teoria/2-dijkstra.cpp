#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using Digrafo = vector<vector<pair<int, int>>>; // vecino, coste
const int INF = 1000000000;

vector<int> ant;

using info = pair<int, int>; // ditsancia, vértice;

int origen = 0;

/*
    Téngase en cuenta que el tipo pair tiene definido un orden 
    {a, b} < {c, d} -> orden lexicográfico
        - a < c
        - b < d
*/

void camino (int v){
    if(v == origen) cout << origen;
    camino(ant[v]);
    cout << " -> " << v;
}

void dikstra(){
    // los grafos valorados son grafos que tienen asociado un valor (peso, coste) en las aristas.
    // Digrafo => grafo dirigido

    /*
        Se puede graficar en un árbol de camino mínimo partiendo de S.
        Representación de un grafo valorado:
            - Matriz de adyaciencia
            - Lista adyacentes: guardamos en cada posición sus adyacentes.
    */

   /*
        En un supuesto de aristas positivas:
   */

   int V, A;
   cin >> V >> A;

    vector<int> dist(V, INF);

    ant.assign(V, -1);
    Digrafo g(V);
    for(int i=0; i < A; i++){
            int u, v, c;
            cin >> u >> v >> c;
            // u--;c--;
            g[u].push_back({c, v});
            // g[v].push_back({u, c}); -> Grafo dirigido
    }

    priority_queue<info, vector<info>, greater<info>> pq; // Nos devolverá aquel cuya distancia sea menor.

    dist[0] = 0;
    pq.push({0, origen});

    while(!pq.empty()){
        auto [d, u] = pq.top(); // desetructuración
        pq.pop();
        if(d > dist[u]) continue; // info. antigua
        for(auto [c, v] : g[u]){
            if(dist[u]+c < dist[v]){ // Si la distancia al adyacente dist[u]+c es menor a la que tenía asignada dist[v]
                dist[v] = dist[u]+c;
                pq.push({dist[v], v});
                ant[v] = u;
            }
        }
    }



    for(int i = 1; i < V; i++){
        cout << "dist 0 a " << i << " => " << dist[i] << "\n";
    }

   // El camino mínimo es el conjunto de aristas que han de poasarse desde S hasta T para que el peso totoal sea mínimo.

}


/*
    4 8
    0 1 10
    2 0 12
    6 0 20
    5 0 15
    4 5 60
    3 5 5
    3 4 30
    6 4 25
*/

int main(){

    dikstra();
    camino(3);
}