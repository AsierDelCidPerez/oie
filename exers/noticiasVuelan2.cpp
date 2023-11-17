#include <iostream>
#include <set>
#include <vector>
#include <string>

using namespace std;

using Grafo = vector<vector<int>>;
vector<set<int>> g;
vector<bool> visited; // Tenemos que inicializarlo despues de cada caso.

int dfs(int n) {
  visited[n] = true;
  int tam = 1;
  for (int i : g[n]) {
    if (!visited[i])
      tam += dfs(i);
  }
  return tam;
}

using img = vector<string>;

int jaen(){
  int F, C;
  while(cin >> F >> C){
    img img(F, "");
    cin.ignore();
    for(int i=0;i<F;i++){
      getline(cin, img[i]);
    }
       
  }
}

int main() {
  int N, M;
  while (cin >> N >> M) { // Ejecutando cada caso
    auto grupos = Grafo(N);
    auto usuarios = Grafo(M);

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

    for(int i : tams){
      cout << i << " ";
    }
    cout << "\n";
  }
}