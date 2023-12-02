#include <iostream>
#include <vector>

using namespace std;

int N, A; // nodos (N) = cruces; aristas (A) = calles

vector<vector<int>> calles;
vector<int> color;
// vector<bool> visited;

int colorizados[2] = {
    0, 0
};

int myMin;

bool posible;

void colorizar(int parent, int starter){
    if(parent == -1) {
        color[starter] = true;
        colorizados[true]++;
    }

    for(auto g : calles[starter]){
        if(!posible) return;
        if(color[g] == -1){
            color[g] = !color[starter];
            colorizados[!color[starter]]++;
            colorizar(starter, g);
        }else if(color[g] == color[starter]){
            posible = false;
            return;
        }
    }
}

int main(){
    while(cin >> N >> A){

        calles.assign(N, {});
        color.assign(N, -1);
        colorizados[0] = 0;
        colorizados[1] = 0;
        posible = true;
        myMin = 0;

        for(int i=0;i<A;i++){
            int a, b;
            cin >> a >> b; 
            a--; b--;
            calles[a].push_back(b);
            calles[b].push_back(a);
        }

        bool resultado = true;

        for(int i=0;i<N;i++){
            if(color[i] == -1){
                colorizar(-1, i);
                resultado = resultado && posible;
                myMin += min(colorizados[0], colorizados[1]);
                colorizados[0] = 0;
                colorizados[1] = 0;
            }
        }

        if(resultado){
            cout << myMin << "\n";
        }else{
            cout << "IMPOSIBLE\n";
        }
    }
}