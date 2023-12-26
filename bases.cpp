#include <iostream>
#include <string>
#include <cmath>
#include <vector>

using namespace std;

void convertirHexToBinary(string const & hex, vector<bool> & v){
    for(int i=0;i<hex.length();++i){
        int intval = (hex[i] >= 'a') ? (hex[i] - 'a' + 10) : (hex[i] - '0');
        for(int j=3;j>=0;j--){
            v[4*i+j] = (intval % 2) ? 1 : 0;
            intval/=2;
        }
    }
}

void binaryToHex(string linea, string & resultado){
    resultado = "";
    int n = ceil(((double)linea.length())/ 4);
    int anadido = n*4 - linea.length();
    for(int i=0;i<anadido;i++) {
        linea = '0' + linea;
    }
    // cout << n<< "\n";
    for(int i=0;i<n;i++){
        int res = 0;
        for(int j=3;j>=0;j--){
            int myValue = linea[linea.length() - 1 - (4 * i + j)] - '0';
            res += (myValue % 2) ? pow(2, j) : 0;
        }
        char valor = (res >= 10) ? (res + 'a' - 10) : (res + '0');
        resultado = valor + resultado;
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
    string n; 

    while(cin >> n){
        if(n == "EXIT") break;
        string resultado;
        binaryToHex(n, resultado);
        cout << resultado << "\n";
    }
}