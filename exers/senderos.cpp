#include <iostream>
#include <vector>

using namespace std;

struct estado {
    int grava;
    int empedrado;
    int vegetacion;
};

struct peso {
    int peso;
    int tipo; // 0 -> grava, 1 -> empedrado, 2 -> vegetación
};

vector<vector<pair<int, peso>>> g;
vector<vector<pair<int, estado>>> dist;

int N, M;

int main() {
    while(cin >> N >> M){
        g.assign(N, {});
        for(int i=0;i<M;i++){
            int o, d, c, estado; cin >> o >> d >> c;
            o--; d--;

        }
    }
}