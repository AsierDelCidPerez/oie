#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, S, T, P; // N, S => destino, T => tiempo; P => pasadizos

using info = pair<int, int>; // Coste, label

vector<vector<info>> pasadizos;
vector<int> dist;

void resuelve(){
    priority_queue<info, vector<info>, greater<info>> pq;
    S--;
    pq.push({0, S});
    dist[S] = 0;
    int conteo = 0;

    while(!pq.empty()){
        auto [c, v] = pq.top(); pq.pop();
        if(c > dist[v]) continue; // info. antigua
        if(c > T) break;

        for(auto g : pasadizos[v]){
            if(dist[g.second] == -1 || dist[v] + g.first < dist[g.second]){
                dist[g.second] = dist[v] + g.first;
                pq.push({dist[g.second], g.second});
            }
        }
    }

    for(auto i : dist){
        // cout << i << "\n";
        if(i != -1 && i <= T) {
            // cout << i << "\n";
            conteo++;
        }
    }

    cout << max(conteo-1,0) << "\n";

}

int main(){
    while(cin >> N >> S >> T >> P){
        if(N == 0) {
            cout << "0\n"; continue; // Solamente si N =0
        }

        pasadizos.assign(N, {});
        for(int i=0;i<P;i++){
            int a, b, c; cin >> a >> b >> c;
            a--; b--;
            pasadizos[b].push_back({c, a});
        }   
        dist.assign(N, -1);
        resuelve();
    }
}