#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, S, T, P; // S -> Destino
using info = pair<int, int>;
vector<vector<info>> digraph;
vector<int> distF;

/*
void dijkstra (int origin) {
    priority_queue<info, vector<info>, greater<info>> q;
    q.push({0, origin});
    while(!q.empty()){
        info v = q.top();
        if(v.first > dist[v.second]) return;
        for(auto g : digraph[v.second]){
            if(dist[g.second] == -1 || dist[i][v.second] + g.first < dist[g.second]){
                dist[g.second] = dist[v.second] + g.first;
                q.push({dist[i][g.second], g.second});
            }
        }
    }
}
*/

void resolver(){
    int conteo = 0;
    for(int i=0;i<N;i++){
        if(i == S) continue;
        vector<int> dist;
        dist.assign(N, -1);
        priority_queue<info, vector<info>, greater<info>> pq;
        
        int origin = i;

        pq.push({0, origin});
        dist[origin] = 0;

        while(!pq.empty()){
            auto [c, v] = pq.top(); pq.pop();
            if(c > dist[v]) continue;

            for(auto g : digraph[v]){
                if(distF[g.second] != -1) {
                    if(dist[S] == -1 || distF[g.second] < dist[S]){
                        dist[S] = distF[g.second];
                        continue;
                    }
                }

                if(dist[g.second] == -1 || dist[v] + g.first < dist[g.second]){
                    dist[g.second] = dist[v] + g.first;
                    pq.push({dist[g.second], g.second});
                }

            }
        }

        distF[origin] = dist[S];

    }

    for(auto i : distF){
        if(i != -1 && i <= T) {
            cout << i << "\n";
            conteo++;
        }
    }

    cout << conteo << "\n";

}

int main(){
    while(cin >> N >> S >> T >> P){ 
        digraph.assign(N, {});
        for(int i=0;i<P;i++){
            int a, b, c; 
            cin >> a >> b >> c;
            a--; b--;
            digraph[a].push_back({c, b}); // coste, celda -> (UNIDIRECCIONAL)
        }
        distF.assign(N, -1);
        resolver();
    }
}