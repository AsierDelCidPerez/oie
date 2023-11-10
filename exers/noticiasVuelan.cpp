#include <iostream>
#include <set>
#include <vector>
using namespace std;

using Grafo = vector<vector<int>>;
vector<set<int>> g;
vector<bool> visited; // Tenemos que inicializarlo despues de cada caso.

int dfs(int const & n) {
  visited[n] = true;
  int tam = 1;
  for (int i : g[n]) {
    if (!visited[i])
      tam += dfs(i);
  }
  return tam;
}

int main() {
  int N, M;
  while (cin >> N >> M) { // Ejecutando cada caso
    g.assign(N, {});
    visited.assign(N, false);
    for (int i = 0; i < M; i++) { // Grupos
      int c; // Cantidad integrantes / grupo
      cin >> c;
      int x;
      
      if(c > 0){
        cin >> x;
        
        x--;

        for (int j = 0; j < c - 1; j++) { // Recorremos /integrante
            int y;
            cin >> y;
            y--;
            g[x].insert(y);
            g[y].insert(x);

            x = y;
        }
      }
    }


    vector<int> tams(N, 0);
    
    for (int i = 0; i < N; i++) {
      if (tams[i] == 0)
      {
        visited.assign(N, false);
        int tam = dfs(i);
        // vector<int> tams;
        for (int j=0;j<N;j++) {
          if (visited[j]) {
            tams[j] = tam;
          }
        }
      }
    }

    for(int const &i : tams){
      cout << i << " ";
    }
    cout << "\n";
  }
}