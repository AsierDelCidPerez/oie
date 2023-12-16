#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, A;

vector<vector<int>> g;
vector<int> visited;
vector<int> precios;
vector<int> minimus;

int MAX = 2147483647;

vector<int> costeMin;

int dfsMinCoste(int nodo) {
	int minCoste = precios[nodo];
    visited[nodo] = true;
    if(costeMin[nodo] != MAX) return costeMin[nodo];
    for (int v : g[nodo]) {
		if (!visited[v]) {
			int nCoste = dfsMinCoste(v);
            costeMin[v] = nCoste;
			if (nCoste < minCoste) minCoste = nCoste;
		}else{
            if (costeMin[v] < minCoste) minCoste = costeMin[v];
        }
	}
    costeMin[nodo] = minCoste;
	return minCoste;
}

void recorrido(){
    costeMin.assign(N, MAX);
    for(int i=0;i<N;i++){
        if(costeMin[i] == MAX){
            dfsMinCoste(i);
        }
    }
}



void resuelve(){
    g.assign(N, vector<int>(0, {}));
    visited.assign(N, false);
    precios.assign(N, MAX);
    // minimus.assign(N, MAX);

    for(int i=0;i<A;i++){
        int a, b; cin >> a >> b; a--; b--;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int S; cin >> S;
    for(int i=0;i<S;i++){
        int a, c; cin >> a >> c; a--;
        precios[a] = c;
    }

    int K; cin >> K;
    // cout << "LEGA\n";

    recorrido();

    for(int i=0;i<K;i++){
        int p; cin >> p; p--;
        int min = costeMin[p];
        if(min == MAX) {
            cout << "MENUDO MARRON\n";
        }else{
            cout << min << "\n";
        }
    }

    cout << "---\n";

}

int main(){
    while(cin >> N >> A){
        resuelve();
    }
}