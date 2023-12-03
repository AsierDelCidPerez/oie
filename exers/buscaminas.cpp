#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int F, C;

using coord = pair<int, int>;
vector<string> tablero;
vector<string> postTablero;
queue<coord> descubiertas;

bool perdido = false;

const int despAdy [2][8] = {
    {-1, 0, 1, 0, -1, 1, 1, -1}, // 1st
    {0, 1, 0, -1, -1, -1, 1, 1} // 2nd
};

void minar(coord c){
    if(postTablero[c.first][c.second] != 'X') return;
    int bombardeo = 0;
    if(perdido) return;
    if(tablero[c.first][c.second] == '*') {
        perdido = true;
        return;
    }
    queue<coord> colindantes;
    for(int i=0;i<8;i++){
        int nX = c.first + despAdy[0][i];
        int nY = c.second + despAdy[1][i];
        if(nX >= 0 && nY >= 0 && nX < F && nY < C){ // Existe dicho colindante en el tablero
            colindantes.push({nX, nY});
            if(tablero[nX][nY] == '*'){
                bombardeo++;
            }
        }
    }

    if(bombardeo == 0){
        postTablero[c.first][c.second] = '-';
        while(!colindantes.empty()){
            coord ci = colindantes.front();
            if(!perdido){
                minar(ci);
            }else{
                return;
            }
            colindantes.pop();
        }
    }else{
        postTablero[c.first][c.second] = bombardeo + 48;
    }



}

void resolver(){
    string ms;
    for(int i=0;i<C;i++) ms+='X';
    postTablero.assign(F, ms);
    perdido = false;
    while(!descubiertas.empty()){
        auto c = descubiertas.front(); descubiertas.pop();
        minar(c);
    }
}

int main(){
    while(cin >> F >> C){
        cin.ignore();
        tablero.assign(F, "");
        for(int i=0;i<F;i++){ // '*' -> BOMBA, '-' -> NO BOMBA
            getline(cin, tablero[i]);
        }
        int k;
        cin >> k; // Celdas a descubrir

        for(int i=0;i<k;i++){
            int f, c;
            cin >> f >> c; f--; c--;
            descubiertas.push({f, c});
        }
        resolver();
        if(perdido){
            cout << "GAME OVER\n";
        }else{
            for(string f : postTablero){
                cout << f << "\n";
            }  
        }
        
    }
}