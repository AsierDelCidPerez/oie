#include <iostream>
#include <cstring>

#define MAX 1000

using namespace std;

int teoria(){
    // 
}

int comb(int i, int j){
    if(i == 0 || j == 0) return 1;
    else return comb(i-1, j-1) + comb(i-1, j);
}

long C[MAX+1][MAX+1];

long combTopDown(int i, int j){ 
    if(i == 0 || i == j) return 1;
    if(C[i][j] != -1) return C[i][j];
    return C[i][j] = comb(i-1, j-1) + comb(i-1, j);
}

long comButtomUp (int n, int r){
    memset(C, 0, sizeof(C));
    C[0][0] = 1;
    for(int i=0;i<n;++i) {
        C[i][0] = 1;
        for(int j=0;j<r;i++){
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
}

long combButtomUpUpgraded(int n, int r){
    long C[MAX+1] = {};
    C[0] = 1;
    for(int i=1;i<=n;++i){
        for(int j=r;j>=1;--j){
            C[j] = C[j-1] + C[j];
        }
    }
    cout << C[r] << "\n";
}

int nFormas(int i, int j){ // i es el cordel a añadir y j el máximo cordel
    // Si i > j se descarta:
    if(i > j) return nFormas(i-1, j);

}

int tabla[1000][1000];

string s;


void reconstruir(int i, int j, string & sol){
    
}

int maxLongitudPalindromo(int l, int r){
    int & valor = tabla[l][r];
    if(valor == -1){
        if(l > r) return valor = 0;
        if(l == r) return valor = 1;
        if(s[l] == s[r]) return C[l][r] = 1 + maxLongitudPalindromo(l+1, r-1);
        else{
            return C[l][r] = max(maxLongitudPalindromo(l, r-1), maxLongitudPalindromo(l+1, r));
        }
    }else{
        return valor;
    }
}

void patindromo () {
    cin >> s;
    cout << maxLongitudPalindromo(0, s.length()-1);
}

int main(){
    // memset(C, -1, sizeof(C)); // Solo vale para el 0 o -1. Está en la librería <cstring>
    memset(tabla, -1, sizeof(tabla));
    // int n, r; cin >> n >> r;
    // cout << comb(n, r) << "\n";
    patindromo();
}