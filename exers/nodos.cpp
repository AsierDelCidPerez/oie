#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, c; // n de nodos y conexiones
vector<vector<int>> conexiones;

int nInalcanzables (int ori, int ttl){
    queue<int> q;

    int alcanzables = 1;
    vector<bool> visited;
    visited.assign(n, false);

    q.push(ori);
    visited[ori] = true;

    int myTtl = 0;

    while(myTtl < ttl){

        queue<int> temp;

        while(!q.empty()){
            int v = q.front(); q.pop();
            for(auto g : conexiones[v]){
                if(!visited[g]) {
                    temp.push(g);
                    visited[g] = true;
                    alcanzables++;
                }
            }
        }

        myTtl++;
        q = temp;

    }

    // cout << n << " -> NODUMs\n";
    return n - alcanzables;

}

int main(){
    while(cin >> n >> c){
        
        conexiones.assign(n, vector<int>(0, {}));

        for(int i=0;i<c;i++){
            int a, b;
            cin >> a >> b; a--; b--;
            // La conexión es bidireccional entre nodos.
            conexiones[a].push_back(b);
            conexiones[b].push_back(a);
        }


        int k;
        cin >> k;
        for(int i=0;i<k;i++){
            int ori, ttl;
            cin >> ori >> ttl;
            int inalc = nInalcanzables(ori-1, ttl);
            cout << inalc << "\n";
        }
        cout << "---\n";
    }

}

