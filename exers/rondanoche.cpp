#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

using coord = pair<int, int>;
vector<string> img;
int w, h;
coord entrada, salida;
const int desp[2][4] = {
    {-1, 0, 1, 0},
    {0, 1, 0, -1}
};
bool posible = true;

void antiCAT() {
    // Llegar lo más rápido posible a salida.
    vector<vector<int>> dist;
    dist.assign(h, vector<int>(w, -1));
    queue<coord> q;
    dist[entrada.first][entrada.second] = 0;
    q.push(entrada);
    while(!q.empty()){
        coord c = q.front(); q.pop();
        for(int i=0;i<4;i++){
            int nX = c.first + desp[0][i];
            int nY = c.second + desp[1][i];
            if (nX >= 0 && nY >= 0 && nX < h && nY < w && img[nX][nY] != '#' && dist[nX][nY] == -1 && img[nX][nY] != 'R') {
                dist[nX][nY] = dist[c.first][c.second] + 1;
                if(nX == salida.first && nY == salida.second){
                    cout << dist[nX][nY] << "\n";
                    // cout << dist[nX][nY] << " <- RESULTADO\n";
                    return;
                }
                q.push({nX, nY});
            }
        }
    }
    if(dist[salida.first][salida.second] == -1){
        cout << "NO\n";
    }
}

void catyzer(int cat, coord c) {
    cat -= '0';
    img[c.first][c.second] = 'R';

    for(int i=0;i<4;i++){
        for(int j=1;j<=cat;j++){
            int nX = c.first + (desp[0][i] * j); // Alargamos el vector desplazamiento correspondiente.
            int nY = c.second + (desp[1][i] * j);
            if(nX >= 0 && nY >= 0 && nX < h && nY < w){
                if(img[nX][nY] == '#') break;
                else if(img[nX][nY] == 'E' || img[nX][nY] == 'P') posible = false;
                else if(!isdigit(img[nX][nY])){
                    img[nX][nY] = 'R';
                }
            }
        }
    }
}

void formulacionUtil() {
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (img[i][j] != '.' && img[i][j] != '#' && img[i][j] != 'R') {
                if (img[i][j] == 'E') {
                    entrada = { i, j };
                }
                else if (img[i][j] == 'P') {
                    salida = { i, j };
                }
                else {
                    int cat = img[i][j];
                    catyzer(cat, { i, j });
                    // img[i][j] = '#';
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> w >> h;
        cin.ignore();
        img.assign(h, "");
        posible = true;


        for (int i = 0; i < h; i++) {
            getline(cin, img[i]);
        }

        formulacionUtil(); // ¿Los sensores qué son? Si son CAT-K podemos tratar su alcance como muros.
        
        // cout << "\n";
        // for(auto s : img) cout << s << "\n";

        if(posible){
            antiCAT();
        }else{
            cout << "NO\n";
        }
    }
}