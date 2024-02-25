#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct ufds {
    int numSets;
    int max;
    vector<int> p;

    ufds(int N) : numSets(N), p(N, -1), max(0) {}

    int find(int i){
        // cout << i << " -> " << p[i] << "\n";
        return (p[i] < 0) ? i : p[i] = find(p[i]);
    }

    void join(int i, int j){

        if(related(i, j)){
            return;
        }

        int x = find(i), y = find(j); 
        if(p[x] > p[y]) {
            swap(x, y);
        } // x siempre contiene al arbol mayor
        p[x] += p[y];
        p[y] = x;
        
        if(p[max] > p[x]) max = x;

        --numSets;
    }

    bool related(int i, int j){
        return find(i) == find(j);
    }

    int size(int i){
        return -p[find(i)];
    }

};

int F, C;
vector<string> img;
vector<vector<bool>> visited;
ufds u(0);

const int despAdy [2][8] = {
    {-1, 0, 1, 0, -1, 1, 1, -1}, // 1st
    {0, 1, 0, -1, -1, -1, 1, 1} // 2nd
};

int getId(int x, int y){
    return x*C + y;
}

void dfsWithUfds(int x, int y){
    visited[x][y] = true;
    for(int i=0;i<8;i++){
        int nX = x + despAdy[0][i];
        int nY = y + despAdy[1][i];

        if(nX >= 0 && nX < F && nY >= 0 && nY < C && img[nX][nY] == '#'){
            if(!visited[nX][nY]){
                u.join(getId(nX, nY), getId(x, y)); 
                dfsWithUfds(nX, nY);
            }
        }
    }
}

void preprocesado(){
    visited.assign(F, vector<bool>(C, false));
    for(int i=0;i<F;i++){
        for(int j=0;j<C;j++){
            if(img[i][j] == ' ' || visited[i][j]) continue;
            if(img[i][j] == '#') {
                dfsWithUfds(i, j);
            }
        }
    }
}

void resuelve(){
    int N; cin >> N;

    preprocesado();
    cout << u.size(u.max) << " ";
    while(N--){
        int x, y; cin >> x >> y; --x; --y;

        for(int i=0;i<8;i++){ // O(cte)
            int nX = x + despAdy[0][i];
            int nY = y + despAdy[1][i];
            
            if(nX >= 0 && nX < F && nY >= 0 && nY < C && img[nX][nY] == '#'){
                // cout << " -> " <<  getId(nX, nY) << " -> " << getId(x, y) << "\n";
                u.join(getId(nX, nY), getId(x, y));
            }
        }


        cout << u.size(u.max) << ((!N) ? "" : " ");

    }
    cout << "\n";
}

int main(){
    while(cin >> F >> C){
        u = ufds(F*C+1);
        img.assign(F, "");
        cin.ignore();
        for(int i=0;i<F;i++){
            getline(cin, img[i]);
        }
        resuelve();
    }
}