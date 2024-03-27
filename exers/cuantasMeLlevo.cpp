#include <iostream>

using namespace std;

int main(){
    string a, b;
    while(cin >> a >> b){
        int llevadas = 0, acarreo = 0;
        int k = a.length() - b.length();

        if(a == "0" && b == "0") break;

        if(k > 0){
            for(int i=0;i<k;++i){
                b = "0" + b;
            }
        }else if(k < 0){
            for(int i=0;i< -k; ++i){
                a = "0" + a;
            }
        }

        for(int i=a.length()-1;i>=0;--i){
            int valorA = a[i] - '0';
            int valorB = b[i] - '0';
            if(valorA + valorB + llevadas >= 10){
                ++acarreo; llevadas = 1;
            }else{
                llevadas = 0;
            }
        }

        cout << acarreo << "\n";

    }
}