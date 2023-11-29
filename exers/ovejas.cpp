#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> img;
int n, m;
vector<vector<bool>> visited;

const int desp[2][4] = {
    {-1, 0, 1, 0},
    {0, -1, 0, 1}
};

const int desp2[2][8] = {
    {-1, 0, 1, 0, -1, 1, -1, 1},
    {0, -1, 0, 1, -1, -1, 1, 1}
};

void eliminarBlanco(int r, int j){ // Se supone que en [r, j] se ha encontrado '.'
    visited[r][j] = true;
    for(int i=0;i<4;i++){
        int nX = r + desp[0][i];
        int nY = j + desp[1][i];
        if(nX >= 0 && nX < m && nY >= 0 && nY < n && !visited[nX][nY] && img[nX][nY] == '.'){
            eliminarBlanco(nX, nY);
        }
    }
}

void eliminarFondo(){
    eliminarBlanco(0, 0);
}

int topologia (int r, int j){ // Se supone que en [r, j] se ha encontrado 'X'
    visited[r][j] = true;
    int topus = 0;
    for(int i=0;i<8;i++){
        int nX = r + desp2[0][i];
        int nY = j + desp2[1][i];
        if(nX >= 0 && nX < m && nY >= 0 && nY < n && !visited[nX][nY]){
            char actual = img[nX][nY];
            if(actual == 'X'){
                topus += topologia(nX, nY);
            }else{ // Si no es "X" entonces será punto
                topus++;
                eliminarBlanco(nX, nY);
            }
        }
    }
    return topus;
}

int main(){

    while(cin >> n >> m){
        visited.assign(m, vector<bool>(n, false));
        img.assign(m, "");
        cin.ignore();

        for(int i=0;i<m;i++){
            getline(cin, img[i]);
        }

        eliminarFondo(); // Eliminamos fondo innecesario

        int ovejasBlancas = 0;
       



        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!visited[i][j] && img[i][j] == 'X'){
                    if(topologia(i, j) > 0) ovejasBlancas++;
                }
            }
        }
        
        cout << ovejasBlancas << "\n";

    }
}