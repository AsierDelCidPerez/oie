#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, A;
using info = pair<int, int>;
vector<int> precios;

struct Estado {
    int ciudad;
    int combustible;
    int coste;

    bool operator>(const Estado& otro) const{
        return coste > otro.coste;
    }

};

vector<vector<info>> g;

void resuelve(int capacidad, int origin, int des){
    // int N = g.size();
    vector<vector<int>> distancias(N, vector<int>(capacidad, -1));
    origin-=1;
    des-=1;
    distancias[origin][0] = 0;
    priority_queue<Estado, vector<Estado>, greater<Estado>> pq;
    
    pq.push({origin, 0, 0});

    while(!pq.empty()){
        auto [city, comb, cost] = pq.top(); pq.pop();
        if(city == des) {
            cout << cost << "\n";
            return; 
        }
        
        for(auto ady : g[city]){
            for (int i = comb; i <= capacidad; i++){
                if (i >= ady.first){
                    int newCost = cost + (i-comb)*precios[city];
                    if (distancias[ady.second][i-ady.first] == -1 || newCost < distancias[ady.second][i-ady.first]) {
                        distancias[ady.second][i-ady.first] = newCost;
                        pq.push({ady.second, i - ady.first, newCost});
                    }
                }
            }
        }
    }

    cout << "IMPOSIBLE\n";

}

int main(){
    while(cin >> N >> A){

        for(int i=0;i<N;i++){
            int c; cin >> c;
            precios.push_back(c);
        }

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
            int capacidad, ori, des;
            cin >> capacidad >> ori >> des;
            resuelve(capacidad, ori, des);
        }

        cout << "---\n";

    }
}