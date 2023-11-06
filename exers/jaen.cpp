#include <iostream>
#include <vector>
#include <string>

using namespace std;

using image = vector<string>;
image img;
int F, C;
vector<vector<bool>> visit;

int const direcciones[2][4] = {
    {
        -1, 0, 1, 0 // filas
    },
    {
        0, 1, 0, -1 // Columnas
    }
};

int dfs(int f, int c){
    int tam = 1;
    visit[f][c] = true;

    for(int i=0;i<4;i++){
        int nF = f + direcciones[0][i];
        int nC = c + direcciones[1][i];

        if(nF >= 0 && nF < F && nC >= 0 && nC < C){ // Restricciones para evitar error de index. 
            if(img[nF][nC] == '#' && !visit[nF][nC]){
                tam += dfs(nF, nC);
            }
        }

    }

    return tam;
}

void jaen(){
    while(cin >> F >> C){
        cin.ignore();
        img.assign(F, "");
        visit.assign(F, vector<bool>(C, false));
        for(int i=0;i<F;i++){
            getline(cin, img[i]);
        }

        int tam_max = 0;

        for(int i=0;i<F;i++){
            for(int j=0;j<C;j++){
                if(img[i][j] == '#' && !visit[i][j]){
                    int tam = dfs(i, j);
                    if(tam > tam_max) tam_max = tam;
                }
            }
        }

        cout << tam_max << "\n";
    }
}

int main(){
    jaen();
}