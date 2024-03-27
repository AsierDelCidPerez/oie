#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long int;

int N, L;

const int INF = 1e9;

vector<pair<int, int>> cuerdas;

vector<vector<ll>> combinaciones;
vector<vector<int>> costes;
vector<vector<int>> minimasCuerdas;

ll nFormas(ll i, ll j){
    if(j == 0) return 1;
    if(i < 0) return 0;
    if(combinaciones[i][j] != -1) return combinaciones[i][j];
    else{
        if(cuerdas[i].first > j){
            return combinaciones[i][j] = nFormas(i-1, j); // Si es mayor la cuerda tan solo tomamos las opciones de cuerda menores a esta
        }else{
            return combinaciones[i][j] = nFormas(i-1, j - cuerdas[i].first) + nFormas(i-1, j); // Si no es mayor practicamos el principio de combinación
        }
    }
}

int minCuerdas(int i, int j){
    if(j == 0) return 0; // para formar una cuerda de longitud l=0 se necesita un conjunto vacío es decir 0 cuerdas.
    if(i<0) return INF;
    if(minimasCuerdas[i][j] != -1) return minimasCuerdas[i][j];
    else{
        if(cuerdas[i].first > j){
            return minimasCuerdas[i][j] = minCuerdas(i-1, j);
        }else{
            return minimasCuerdas[i][j] = min(minCuerdas(i-1, j-cuerdas[i].first)+1, minCuerdas(i-1, j));
        }
    }
}

int minCoste(int i, int j){
    if(j == 0) return 0;
    if(i < 0) return INF;
    if(costes[i][j] != -1) return costes[i][j];
    else{
        if(cuerdas[i].first > j){
            return costes[i][j] = minCoste(i-1, j);
        }else{
            return costes[i][j] = min(minCoste(i-1, j - cuerdas[i].first) + cuerdas[i].second, minCoste(i-1, j));
        }
    }
}

int main(){
    while(cin >> N >> L){
        minimasCuerdas.assign(N+1, vector<int>(L+1, -1));
        combinaciones.assign(N+1, vector<ll>(L+1, -1));
        costes.assign(N+1, vector<int>(L+1, -1));

        cuerdas.clear();
        // costes.clear();
        for(int i=0;i<N;++i){
            int c, cs; cin >> c >> cs;
            cuerdas.push_back({c, cs});
        }
        sort(cuerdas.begin(), cuerdas.end()); // orden ascendente
        // for(int i : cuerdas) cout << i << " ";
        // cout << "\n";
        ll formasTotal = nFormas(N-1, L);
        int minimo = minCuerdas(N-1, L);
        int minimoCost = minCoste(N-1, L);
        if(formasTotal != 0){
            cout << "SI " << formasTotal << " " << minimo << " " << minimoCost << "\n";
        }else{
            cout << "NO\n";
        }
    }
}