

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int V, E; // n de intersecciones (nodos) y calles (aristas)
vector<vector<pair<int, int>>> g;
vector<int> visited;

bool resolver(int ori, int de, int an){
    visited.assign(V, false);
    
    queue<int> q;
    q.push(ori);
    visited[ori] = true;
    while(!q.empty()){
        auto v = q.front(); q.pop();
        for(auto g : g[v]){
            if(an <= g.second && !visited[g.first]){
                visited[g.first] = true;
                if(g.first == de) return true;
                q.push(g.first);
            }
        }
    }

    return false;
    
}


int main(){

    while(cin >> V >> E){
        g.assign(V, {});
        visited.assign(V, false);
        for(int i=0;i<E;i++){
            int a, b, c;
            cin >> a >> b >> c; a--; b--;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }

        int k;
        cin >> k;
        // ¿BFS?
        for(int i=0;i<k;i++){
            int a, b, c;
            cin >> a >> b >> c; // a y b son inters. y c anchura camion. ¿Puede el camión pasar de a hasta b con su anchura?
            if( resolver(a-1, b-1, c)){
                cout << "SI\n";
            }else{
                cout << "NO\n";
            }
        }

    }

}
