#include <iostream>
#include <string>
#include <map>

using namespace std;

map<char, int> dnies = {{'E', 1},{'W', 2},{'A', 3},{'G', 4},{'M', 5},{'Y', 6},{'F', 7},{'P', 8},{'D', 9},{'X', 10},{'B', 11},{'N', 12},{'J', 13},{'Z', 14},{'S', 15},{'Q', 16},{'V', 17},{'H', 18},{'L', 19},{'C', 20},{'K', 21},{'E', 22}};

map<int, char> dnies2 = {{1, 'E'},{2, 'W'},{3, 'A'},{4, 'G'},{5, 'M'},{6, 'Y'},{7, 'F'},{8, 'P'},{9, 'D'},{10, 'X'},{11, 'B'},{12, 'N'},{13, 'J'},{14, 'Z'},{15, 'S'},{16, 'Q'},{17, 'V'},{18, 'H'},{19, 'L'},{20, 'C'},{21, 'K'},{22, 'E'}};

int conversion(char letra) {
    return dnies[letra];
}

char conversion2(int digit){
    return dnies2[digit];
}

int adivinarDNI(string dni){
    int posibilidades = 0;
    bool encontrado = false;

    // cout << "Recibo: " << dni << "\n";

    for(int j=0;j<dni.size()-1;j++){
        if(dni[j] == '?'){
            for(int i=0;i<10;i++){
                dni[j] = i+48;
                cout << i << " -> " << dni << "\n";
                posibilidades += adivinarDNI(dni);
                encontrado = true;
            }
        }
    }

    if(!encontrado){
        int entero = stoi(dni.substr(0, 8));
        if(entero % 23 == conversion(dni[dni.size()-1])){
            // cout << dni << " (Agraciado)\n";
            posibilidades++;
        }
    }

    return posibilidades;
}

int main(){
    int T;
    cin >> T;
    cin.ignore();
    while(T--){
        string dni;
        getline(cin, dni);
        int pos = -1;
        for(int i=0;i<dni.size()-1;i++){
            if(dni[i] == '?'){
                pos = i;
                break;
            }
        }
        cout << adivinarDNI(dni) << "\n";
    }
}