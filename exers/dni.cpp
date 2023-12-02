#include <iostream>
#include <string>
#include <map>

using namespace std;

int conversion(char letra) {
	if (letra == 'T') return 0;
	else if (letra == 'R') return 1;
	else if (letra == 'W') return 2;
	else if (letra == 'A') return 3;
	else if (letra == 'G') return 4;
	else if (letra == 'M') return 5;
	else if (letra == 'Y') return 6;
	else if (letra == 'F') return 7;
	else if (letra == 'P') return 8;
	else if (letra == 'D') return 9;
	else if (letra == 'X') return 10;
	else if (letra == 'B') return 11;
	else if (letra == 'N') return 12;
	else if (letra == 'J') return 13;
	else if (letra == 'Z') return 14;
	else if (letra == 'S') return 15;
	else if (letra == 'Q') return 16;
	else if (letra == 'V') return 17;
	else if (letra == 'H') return 18;
	else if (letra == 'L') return 19;
	else if (letra == 'C') return 20;
	else if (letra == 'K') return 21;
	else if (letra == 'E') return 22;
	else return 23;
}

int adivinarDNI(string dni){
    int posibilidades = 0;
    bool encontrado = false;

    // cout << "Recibo: " << dni << "\n";

    for(int j=0;j<dni.size()-1;j++){
        if(dni[j] == '?'){
            for(int i=0;i<10;i++){
                dni[j] = i+48;
                // cout << i << " -> " << dni << "\n";
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