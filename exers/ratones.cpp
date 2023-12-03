#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, S, T, P; // S -> Destino
using info = pair<int, int>;
vector<vector<info>> digraph;
vector<vector<int>> dist;

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
    dist.assign(N, vector<int>(N, -1));
    // dijkstra(0);
    priority_queue<info, vector<info>, greater<info>> q;
    for(int i=0;i<N;i++){
        int origin = i;
        q.push({0, origin});
        while(!q.empty()){
            info v = q.top();
            if(v.first > dist[i][v.second]) break;
            if(dist[i][v.second] >= dist[i][S]) break;
            for(auto g : digraph[v.second]){
                if(dist[i][g.second] == -1 || dist[i][v.second] + g.first < dist[i][g.second]){
                    dist[i][g.second] = dist[i][v.second] + g.first;
                    q.push({dist[i][g.second], g.second});
                }
            }
        }
    }

    int conteo = 0;
    for(auto i : dist){
        if(i[S] < T){
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
        resolver();
    }
}