#include <iostream>
#include <vector>

using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        
        int n, m;

        cin >> n >> m;

        int ** matriz = new int* [m];
        // vector<vector<int>> matriz(m, vector<int>(n, 0));
        
        for(int i=0;i<n;i++){
            matriz[i] = new int[n];
            for(int j=0;j<m;j++){
                int c;
                cin >> c;
                matriz[j][i] = c;
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                 cout << matriz[i][j] << " ";
            }
            cout << "\n";
        }
    }
}