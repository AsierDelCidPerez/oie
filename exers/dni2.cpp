#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <unordered_set>

using namespace std;

map<char, int> dnies = {{'T', 0}, {'R', 1},{'W', 2},{'A', 3},{'G', 4},{'M', 5},{'Y', 6},{'F', 7},{'P', 8},{'D', 9},{'X', 10},{'B', 11},{'N', 12},{'J', 13},{'Z', 14},{'S', 15},{'Q', 16},{'V', 17},{'H', 18},{'L', 19},{'C', 20},{'K', 21},{'E', 22}};

map<int, char> dnies2 = {{0, 'T'}, {1, 'R'},{2, 'W'},{3, 'A'},{4, 'G'},{5, 'M'},{6, 'Y'},{7, 'F'},{8, 'P'},{9, 'D'},{1, 'X'},{11, 'B'},{12, 'N'},{13, 'J'},{14, 'Z'},{15, 'S'},{16, 'Q'},{18, 'V'},{18, 'H'},{19, 'L'},{20, 'C'},{21, 'K'},{22,'E'}};


vector<unordered_set<int>> mB10; // Para una posición del dni i, almaceno los 8 posibles módulos que puede tomar la potencia en base 10.

char letra;

int positiveMod(int a, int p){
    int val = a%p;
    if(val < 0) return val+p;
    else return val;
}

bool DNIposible(int pos, int suma){
    return mB10[pos].count(positiveMod(dnies[dnies2[dnies[letra]]] - suma, 23));
}

int numFormas(string &s, vector<int> & interrogaciones, int interrogacion, int suma){
    int maneras = 0;
    if(interrogacion == interrogaciones.size()-1){
        // Última interrogaciones, especial -> Caso base
        return DNIposible(interrogaciones[interrogacion], suma);
    }else{
        int pos = interrogaciones[interrogacion]; // interrogacion a procesar
        for(int i=0;i<=9;i++){
            int val = (i*pow(10, 7-pos));
            val %= 23;
            val += suma;
            val %=23;
            maneras += numFormas(s, interrogaciones, interrogacion+1, val);
        }
    }
    return maneras;
}

void resolver(string & s){
    vector<int> posInterrogaciones;
    int suma = 0; // contener el módulo de la suma de los módulos conocidos.
    for(int i=0;i<s.length()-1;i++){
        if(s[i] == '?') posInterrogaciones.push_back(i);
        else{
            int val = (s[i] - '0') * pow(10, 7-i);
            val%=23;
            suma += val;
        }
    }
    suma%=23;
    letra = s[s.length()-1];
    int maneras = numFormas(s, posInterrogaciones, 0, suma);
    cout << maneras << "\n";
}

int main(){
    // Aritmética modular.
    mB10.assign(8, {});
    for(int i=0;i<8;i++){
        for(int j=0;j<=9;j++){
            int val = pow(10, 7-i) * j; val %= 23;
            mB10[i].insert(val);
        }
    }
    
    int T; cin >> T;
    while(T--){
        string s; cin >> s;
        resolver(s);
    }

}