#include <iostream>
#include <vector>

using namespace std;
using Grafus = vector<vector<int>>;

Grafus g;
vector<bool> visited;


int dfs(int v) { // El coste de dfs es V + A, es realmente lineal ya que cada vértice es marcado y se pasará por el una o dos veces.
	visited[v] = true;
	int tam = 1;
	for (int w : g[v]) {
		if (!visited[w]) {
			tam+=dfs(w);
		}
	}
	return tam;
}


void exGrafos() {

	// Cálculo de la componente conexa más grande de un grafo

	int T;
	cin >> T;
	while (T--) {
		int V, A;
		cin >>V >> A;
		int max = 0;
		visited.assign(V, false);
		g.assign(V, {});

		for (int i = 0; i < A; i++) {
			int u, w;
			cin >> u >> w;
			u--; w--;
			g[u].push_back(w);
			g[w].push_back(u);
		}

		for (int v = 0; v < V; v++) {
			if (!visited[v]) {
				int tam = dfs(v);
				max = tam > max ? tam : max;
			}
		}
		cout << max << "\n";
	}
}

int main(){
    exGrafos();
}