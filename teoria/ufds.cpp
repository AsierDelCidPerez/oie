#include <iostream>
#include <vector>

using namespace std;

struct ufds {
    int numSets;
    vector<int> p;

    ufds(int N) : numSets(N), p(N, -1) {}

    int find(int i){
        return (p[i] < 0) ? i : p[i] = find(p[i]);
    }

    void join(int i, int j){
        int x = find(i), y = find(j); 
        if(p[x] > p[y]) {
            swap(x, y);
        } // x siempre contiene al arbol mayor
        p[x] += p[y];
        p[y] = x;
        --numSets;
    }

    bool related(int i, int j){
        return find(i) == find(j);
    }

    int size(int i){
        return -p[find(i)];
    }

};


void teoria(){
    /*
        Las estructuras UFDS permiten la inserción dinámica y su búsqueda.
        Para ello hacemos uso de árboles. Este árbol lo representamos con un vector donde p[i] es el padre de i.
        
        El método find dado un elemento devuelve la raíz del arbol.
    
    */
}

bool resuelve(){
    int N, M;
}

int main(){
    int N, M;
    while(cin >> N >> M){
        ufds UF(N);
        
        for(int i=0;i<M;++i){
            int T; cin >> T;
            if(T > 0){
                int prim; cin >> prim; --i;
                for(int j=1;j<T;j++){
                    int otro; cin >> otro; --otro;
                    UF.join(prim, otro);
                }
            }
        }

        cout << UF.size(0);
        for(int i=1;i<N;++i){
            cout << ' ' << UF.size(i);
        }

    }
}