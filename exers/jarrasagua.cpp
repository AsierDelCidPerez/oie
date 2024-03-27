#include <iostream>
#include <vector>
#include <queue>

using namespace std;
using estado = pair<int, int>; // Capacidad de a y b

vector<vector<estado>> g; // Su
vector<int> capacidades;
vector<vector<int>> dist;

int L;

void resolver(){
    priority_queue<pair<int, estado>, vector<pair<int, estado>>, greater<pair<int, estado>>> pq;
    pq.push({0, {capacidades[0], 0}});
    while(!pq.empty()){
        auto [trasvases, estado] = pq.top(); pq.pop();
        int actual[3] = {estado.first, estado.second, capacidades[0] - (estado.first + estado.second)};
        for(auto i : actual){
            if(i == L){
                cout << trasvases << "\n";
            }
        }

        for(int i=0;i<3;i++){ // El dador
            for(int j=0;j<3;j++){ // El recibidor

            }
        }
    }

}

int main(){
    int a, b, c;
    while(cin >> a >> b >> c >> L){
        capacidades.assign(3, -1);

        for(int i=0;i<3;i++){
            cin >> capacidades[i];
        }

        cin >> L;

        resolver();    

    }
}