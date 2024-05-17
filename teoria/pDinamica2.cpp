#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tabla;

int C, n;

const int INF = 1e9;

vector<vector<int>> dp;

vector<int> tipos;

int monedas (int i, int j){
    if(j == 0) return dp[i][j] = 0;
    else if(i == 0) return dp[i][j] = INF;
    cout << i << " " << j << "\n";
    if(dp[i][j] != -1) return dp[i][j];
    if(tipos[i] > j){
        return dp[i][j] = monedas(i-1, j);
    }else{
        return dp[i][j] = min(monedas(i-1, j), monedas(i, j-tipos[i])+1);
    }
}

void rellenarTabla(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=C;j++){
            if(i == 0) tabla[i][j] = 0;
            else if(j == 0) tabla[i][j] = INF;
            else {
                if(tipos[i] > j){
                    tabla[i][j] = tabla[i-1][j];
                }else{
                    tabla[i][j] = min(tabla[i-1][j], tabla[i][j-tipos[i]]+1);
                }
            }
        }
    }
}

int main(){
    cin >> C >> n;
    tipos.assign(n, -1);
    tabla.assign(n+1, vector<int>(C+1, -1));
    dp.assign(n+1, vector<int>(C+1, -1));
    for(int i=1;i<=n;i++){
        cin >> tipos[i];
    }
    // rellenarTabla();
    cout << monedas(n, C) << "\n";
    // cout << tabla[n][C] << "\n";
}