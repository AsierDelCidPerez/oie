#include <iostream>
#include <deque>
#include <vector>

using namespace std;

void resolver(int k){
    vector<int> dist(k, -1); // Trabajamos sobre módulo k
    deque<int> q;

    dist[1] = 1; // No puede tomar valor k pues k === 0 (mod k).
    q.push_back(1);

    while(!q.empty()){
        int actual = q.front(); q.pop_front();
        
        // Caso 1 : No extra coste
        int a = (actual * 10) % k;
        if(dist[a] == -1 || dist[a] > dist[actual]){
            dist[a] = dist[actual];
            q.push_front(a);
        }


        // Caso 2 -> Extra coste de 1
        int b = (actual + 1) % k;
        if(dist[b] == -1 || dist[b] > dist[actual]+1){
            dist[b] = dist[actual]+1;
            q.push_back(b);
        }
    }

    cout << dist[0] << "\n";

}

int main(){
    int k;
    while(cin >> k) {
        resolver(k);
    }
}