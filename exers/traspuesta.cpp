#include <iostream>

using namespace std;

int main(){
    int N, M;
    while(cin >> N >> M){
        int ** matriz = new int * [M];
        for(int j=0;j<M;j++) matriz[j] = new int[N];
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                int c; cin >> c;
                matriz[j][i] = c;
            }
        }
        cout << "\n";
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cout << matriz[i][j] << " ";
            }
            cout << "\n";
        }
    }



}