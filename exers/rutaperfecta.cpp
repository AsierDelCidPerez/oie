#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
struct estado {
    int nGrava, nEmp, nVege;
};

vector<vector<pair<int, pair<int, string>>>> rutas;

void resolver(int const & origin, int const & dest){
    priority_queue<pair<int, estado>, vector<pair<int, estado>>, greater<pair<int, estado>>> pq;
    pq.push({0, {}});

}

int main(){
    while(cin >> N >> M){
        rutas.assign(N, {});
        for(int i=0;i<M;i++){
            int a, b, c, r;
            string tRuta;
            cin >> a >> b >> c >> tRuta; a--;b--;
            rutas[a].push_back({c, {b, tRuta}});
            rutas[b].push_back({c, {a, tRuta}});
        }

        int k, a, b; cin >> k;

        for(int i=0;i<k;i++){
            cin >> a >> b;
            resolver(a, b);
        }

    }
}