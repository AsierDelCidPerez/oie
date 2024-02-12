#include <iostream>
#include <vector>
#include <set>

using namespace std;

bool premiado[1000001];
vector<set<int>> jugadores;
vector<string> nombres;

int main(){
    int N;
    while(cin >> N){
        if(N == 0) break;
        for(int i=0;i<N;i++){
            cin >> nombres[i];
            int c; cin >> c;
            while(c != 0){
                jugadores[i].insert(c);
                cin >> c;
            }
        }
        int K; cin >> K;
        while(K--){
            int c; cin >> c;
            premiado[c] = true;
        }
        vector<string> ganadores;

        for(int i=0;i<1000001;i++){
            
        }

    }
}