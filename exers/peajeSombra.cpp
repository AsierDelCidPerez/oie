#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 1e9;
using namespace std;

vector<vector<int>> g;

int N, C;
int A, L, T;

vector<int> bfsWOD(int origin){
    vector<int> dist;
    dist.assign(N, -1);
    queue<int> q;
    q.push(origin);
    dist[origin] = 0;
    
    while(!q.empty()){
        int v = q.front(); q.pop();
        for(int ady : g[v]){
            if(dist[ady] == -1) {
                dist[ady] = dist[v]+1;
                q.push(ady);
            }
        }
    }
    return dist;
}

void resolver(){
    A--; L--; T--;
    int origin = T;

    queue<int> q;

    q.push(origin);

    const vector<int> dist1 = bfsWOD(A);
    const vector<int> dist2 = bfsWOD(L);
    const vector<int> dist3 = bfsWOD(T);

    vector<int> finalista;
    finalista.assign(N, -1);
 
    for(int i=0;i<N;i++){
        if(dist1[i] == -1 || dist2[i] == -1 || dist3[i] == -1){
            finalista[i] = MAX; continue;
        }
        finalista[i] = dist1[i] + dist2[i] + dist3[i];
    }
    int minimum = *min_element(finalista.begin(), finalista.end());
    cout << minimum << "\n";
}

int main() {
    while(cin >> N >> C >> A >> L >> T){
        g.assign(N, {});
        for(int i=0;i<C;i++){
            int a, b; cin >> a >> b; a--;b--;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        resolver();

    }
}