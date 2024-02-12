#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>

using namespace std;

struct ufds {
    vector<int> p;

    int trees;
    
    ufds(int N) : trees(N), p(N, -1) {}

    void join(int i, int j){
        int a = find(i); // a es más grande siempre
        int b = find(j);

        if(a > b) { // Los tamaños se ponen en negativo, entonces si a > b, entonces b tiene más elementos
            swap(a, b);
        }

        p[a] += p[b];
        p[b] = a;
        --trees;

    }

    int find(int n){
        return (p[n] < 0) ? n : p[n] = find(p[n]);
    }

    int size(int i){
        return -p[find(i)];
    }

    bool related(int i, int j){
        return find(i) == find(j);
    }

};

int W, H, N; // Ancho, alto del patio (en metros); y número de guardias; todos con una visión rango=10m

/*
    El truco del problema se encuentra en que para que no escaparse un prisionero, entonces debe existir una barrera horizontal
    (de este a oeste) de guardias cuyos alcances podrán ser como máximo tangentes.
    
    Es decir, no podrá escaparse los prisioneros si y solo si existe una cadena definida como una serie de guardias tales que
    sus rangos de alcance sean conexos, pudiendo ser como máximo tangentes.
*/

vector<vector<int>> alcances;

using coordenadas = pair<int, int>;

const int ratio = 10;

int dist (coordenadas a, coordenadas b){
    return sqrt(pow(b.first - a.first, 2) + pow(b.second - a.second, 2));
}

const int varEste = 1; // Deben ser diferentes y positivas (>0).
const int varOeste = 2;

int main(){
    while(cin >> W){
        if(W == 0) break;
        cin >> H >> N;
        ufds u(N+max(varEste, varOeste));

        vector<pair<int, coordenadas>> cords;

        for(int i=0;i<N;i++){
            int nX, nY; cin >> nX >> nY;
            if(nX-ratio <= 0){ // Cubre el oeste
                u.join(i, N-1+varOeste);
            }
            if(nX + ratio >= W-1){ // Cubre el este
                u.join(i, N-1+varEste);
            }
            for(auto [index, c] : cords){
                int d = dist({nX, nY}, c);
                if(d <= ratio*2){
                    u.join(index, i);
                }
            }

            cords.push_back({i, {nX, nY}});
        }

        if(u.related(N-1+varEste, N-1+varOeste)) cout << "NO\n";
        else cout << "SI\n";

    }
}