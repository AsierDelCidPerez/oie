#include <iostream>
#include <vector>

using namespace std;


void imprimirArr(vector<int> & a){
    cout << "\nImpresion:";
    for(int i : a){
        cout << i << " ";
    }
    cout <<endl;
}

struct ufds {
    int trees;
    vector<int> p;
    int n;
    
    ufds(int N) : trees(N), n(N), p(N, -1) {};

    int find(int i){
        return (p[i] < 0) ? i : p[i] = find(p[i]);
    }



    void join(int i, int j){
        
        // cout << i << " | " << j << " | "<< n << "\n";

        int x = find(i);
        int y = find(j);

        // cout << i << " | " << j << "\n";

        if (x ==y){
            return ;
        }
        if(p[x] > p[y]){
            swap(x, y);
        }


        p[x] += p[y];

        p[y] = x;

        --trees;
        // imprimirArr(p);

    }

    int size(int x){
        return -p[find(x)];
    }

};
 
vector<vector<char>> tablero;

int main(){
    int T; 
    cin >> T;
    int N;
    tablero.assign(N, vector<char>(N, 0));
    while(T--){
        cin >> N;
        ufds u(N*N+1);
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                char c; cin >> c;
                if(c == 'U'){
                    if(i - 1 < 0){
                        u.join(N*N, i*N+j);
                    }else{
                        u.join((i-1)*N+j, i*N+j);
                    }
                }else if(c == 'R'){
                    if(j +1 > N-1){
                        u.join(N*N, i*N+j);
                    }else{
                        u.join((i)*N+j+1, i*N+j);
                    }
                }else if(c == 'D'){
                    if(i + 1 > N){
                        u.join(N*N, i*N+j);
                    }else{
                        u.join((i+1)*N+j, i*N+j);
                    }
                }else if(c == 'L'){
                    if(j - 1 < 0){
                        u.join(N*N, i*N+j);
                    }else{
                        u.join((i)*N+j-1, i*N+j);
                    }
                }
            }
        }

        // cout << "\nTrees: "<<u.trees << " | " << u.n << "\n";

        if(u.trees == 1){
            cout << "POSIBLE\n";
        }else{
            cout << "IMPOSIBLE\n";
        }

    }
}