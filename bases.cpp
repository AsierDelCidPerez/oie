#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void convertirHexToBinary(string const & hex, vector<bool> & v){
    for(int i=0;i<hex.size();i++){
        int intval = (hex[i] > 'a' ? hex[i] - 'a' + 10 : hex[i] - '0');
        for(int j=0;j<=3;j++){
            v[4*i+j] = (intval % 2) ? 1 : 0;
            intval/=2;
        }
    }
}

string decimalToBase(int n, int base){

    int cociente = n;
    int contador = 0;
    string resultado = "";

    while(cociente != 0){
        int aux = cociente;
        cociente = (aux / base);
        int resto = (aux % base);
        if(resto > 9){
            resultado = char(resto + 55) + resultado;
        }else{
            resultado = char(resto + 48) + resultado;
        }
        contador++;
    }
    return resultado;
}

int baseToDecimal(string n, int base){
    string number = n;

    // cout << number << "\n";
    int resultado = 0;

    for(int i=number.size()-1;i<number.size();i--){
        if(number[number.size()-i-1] < 58){
            resultado += ((number[number.size()-i-1] - 48) * pow(base, i));
        }else{
            resultado += ((number[number.size()-i-1] - 55) * pow(base, i));
        }
    }

    return resultado;
}

int main(){

    string ejemplo;
    int base;
    cin >> ejemplo >> base;
    vector<bool> binary;
    binary.assign(20, false);
    convertirHexToBinary(ejemplo, binary);

    for(int i : binary) cout << i << " ";

    

    // cout << decimalToBase(rest, base) << "\n";
}