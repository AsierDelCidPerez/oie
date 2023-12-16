#include <iostream>
#include <vector>
#include <string>

using namespace std;

int H, W;



vector<vector<bool>> img;
vector<vector<bool>> visited;

const bool negro = true;
const bool blanco = false;
const char correspondencias[6] = {'W', 'A', 'K', 'J', 'S', 'D'};


const int desp[2][4] = {
    {-1, 0, 1, 0},
    {0, 1, 0, -1}
};

void convertirHexToBinary(string const & hex, vector<bool> & v){
    for(int i=0;i<hex.size();i++){
        int intval = (hex[i] > 'a' ? hex[i] - 'a' + 10 : hex[i] - '0');
        for(int j=0;j<=3;j++){
            v[4*i+j] = (intval % 2) ? negro : blanco;
            intval/=2;
        }
    }
}


void eliminarBlanco(int x, int y){
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nX = x + desp[0][i];
        int nY = y + desp[1][i];
        if(nX >= 0 && nX < H && nY >= 0 && nY < W){ // Validación básica
            if(!visited[nX][nY] && !img[nX][nY]) eliminarBlanco(nX, nY); // Si no está visitado y es blanco eliminar blancos
        }
    }
}

int topologia(int x, int y){
    int tam = 0;
    visited[x][y] = true;
    for(int i=0;i<4;i++){
        int nX = x + desp[0][i];
        int nY = y + desp[1][i];
        if(nX >= 0 && nX < H && nY >= 0 && nY < W && !visited[nX][nY]){ // Validación básica
            if(img[nX][nY]){
                tam += topologia(nX, nY);
            }else{
                eliminarBlanco(nX, nY);
                tam++;
            }
        }
    }
    return tam;
}

void resuelve(){
    // Eliminación del fondo
    for(int i=0;i<W;i++){
        if(!img[0][i]) eliminarBlanco(0, i);
    }
    for(int i=0;i<H;i++){
        if(!img[i][0]) eliminarBlanco(i, 0);
    }

    for(int i=1;i<W-1;i++){
        for(int j=1;j<H-1;j++){
            bool actual = img[j][i];
            if(actual && !visited[j][i]) {
                cout << correspondencias[topologia(j, i)];
            }
        }
    }
    cout << "\n"; 
}

int main(){
    while(cin >> H >> W){
        if(H == 0 && W == 0) break;
        W*=4;
        cin.ignore();
        img.assign(H, vector<bool>(W, false));
        visited.assign(H, vector<bool>(W, false));

        for(int i=0;i<H;i++){
            string s;
            getline(cin, s);
            convertirHexToBinary(s, img[i]);
        }

        /*
        for(auto b : img){
            for(auto i : b) cout << i << " ";
            cout << "\n";
        }
        */
       
        // eliminarBordes();
        resuelve();
    }
}