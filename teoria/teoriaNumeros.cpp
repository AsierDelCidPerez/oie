#include <iostream>
#include <cassert>
#include <cmath>
#include <vector>

#define MAX_N 1e7;

using namespace std;

void factorizarRec(unsigned int n){
    unsigned int p = 2;

    while((p*p<=n) && (n%p) != 0) ++p;

    if((n % p) == 0){
        cout << ' ' << p;
    }

    if((n%p) == 0){
        factorizarRec(n/p);
        cout << ' ' << p;
    }
    else{
        if(n!= 1) cout << " \n";
    }

}

void factorizarDos(unsigned int n){
    cout << n << " =";
    factorizarRec(n);
    cout << '\n';
}

vector<bool> primos;

void cribaEratostenes(){
    primos.assign(MAX_N, 0);
    
}

void factorizar(unsigned int n){
    assert(n >= 2);
    cout << n << " =";

    unsigned int p = 2;

    bool contador = false;

    while(p*p <= n){
        if((n % p) == 0){
            cout << ' ' << p;
            n /= p;
            contador = true;
        }else {
            if(p == 2) ++p;
            else p+=2;
        }
    }

    if(!contador){
        cout << ' ' <<  n;
    }

    cout << "\n";

}

int main(){
    int n; while(cin >> n) factorizarDos(n);

    // Ejercicio: ¿Cuántos divisores tiene un entero n?

}