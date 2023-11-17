#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int o, d;
vector<int> dist;
const int MAX = 10000;

int getMyNumber(int n, int i){
    switch(i){
        case 0:
            return (n + 1) % MAX;
        case 1:
            return (n << 1) % MAX;
        case 2:
            return (n/3);  // No hace falta módulo pues la función x/2 es reductora.
    }
    return -1;
}

int minMovimientos (int origen, int destino){
    if(origen == destino) return 0;
    dist.assign(MAX, -1);
    queue<int> h; h.push(origen);
    dist[origen] = 0;
    while(!h.empty()){

        int mO = h.front(); h.pop();

        for(int i=0;i<3;i++) {
            int w = getMyNumber(mO, i); 
            if(dist[w] == -1){
                dist[w] = dist[mO]+1;
                if(w == destino) return dist[w];
                h.push(w);
            }
        }
    } 
    return -1;
}

int main(){
    while(cin >> o >> d){
        cout << minMovimientos(o, d) << "\n";
    }
}