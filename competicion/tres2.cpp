#include <iostream>
#include <vector>
#include <string> 

using namespace std;

vector<vector<int>> g;
vector<bool> visited;

int dfsMinCoste(int nodo, vector<int>& coste) {
	int minCoste = coste[nodo];
	visited[nodo] = true;
	for (int v : g[nodo]) {
		if (!visited[v]) {
			int nCoste = dfsMinCoste(v, coste);
			if (nCoste != -1 && nCoste < minCoste) minCoste = nCoste;
		}
	}
	return minCoste;
}

void difundiendoRumor() {
	int N, M; // N => V; M => A
	while (cin >> N >> M) {
		g.assign(N, {});
		vector<int> costes(N, 0);
		visited.assign(N, false);
		for (int i = 0; i < N; i++) {
			int c;
			cin >> c;
			costes[i] = c;
		}
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			g[a - 1].push_back(b - 1);
			g[b - 1].push_back(a - 1);
		}

		int sumTotal = 0;

		for (int i = 0; i < visited.size(); i++) {
			if (!visited[i]) sumTotal += dfsMinCoste(i, costes);
		}

		cout << sumTotal << "\n";
	}
}

int main(){
    difundiendoRumor();
}