#include <iostream>
#include <map>
#include<string>

using namespace std;


void miProfe(){
    int N;
    while(cin >> N){
        if(N == 0) break;
        cin.ignore();
        map<string, int> alumnos; // Cuando se inicializa el valor de int, toma por defecto 0.
        for(int i=0;i<N;i++){
            string n;
            string punt;
            getline(cin, n); getline(cin, punt);
            int nota = (punt == "CORRECTO") ? 1 : -1;
            alumnos[n]+=nota;
        }

        for(auto par : alumnos){
            if(par.second != 0){
                cout << par.first << ", " << par.second << "\n";
            }
        }
        cout << "---\n";

    }
}

int main(){
    miProfe();
}