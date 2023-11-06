#include <iostream>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, m;
        cin >> n >> m;
        int ** matriz = new int * [m];
        
        for(int i=0;i<m;i++){
            matriz[i] = new int[n];
            for(int j=0;j<n;j++){
                int c;
                cin >> c;
                matriz[j][i] = c;
            }
        }
        cout << "\n---\n";
        for(int i=0;i<m;i++){
            for(int j=0;j<n;i++){
                cout << matriz[i][j];
            }
            cout << "\n";
        }
    }
}