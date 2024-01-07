#include <iostream>
#include <queue>

using namespace std;

int expHongos(int N, int M, int T){
    // Principio de recursividad: 
    int cantidad = 1;

    if(M < T){
        T-=M;
        expHongos(N, M, T-M);
    }

    return cantidad;
}


int main(){
    int N, M, T;
    /*
        N -> tiempo que tarda una célula adulta en reproducirse
        M -> tiempo que tarda una celula hija en convertirse en adulta
        T -> tiempo del experimento
        Cuestión: En tiempo T cuantas células tendremos si comenzamos con una célula adulta.
    */

    priority_queue<int, vector<int>, greater<int>> celulas;

    while(cin >> N >> M >> T){
        celulas = priority_queue<int, vector<int>, greater<int>>();
        celulas.push(N);
        while(T!=0){
            int minimum = celulas.top(); // propiedad de priority_queue
            minimum = min(T, minimum);
            T-=minimum;
            queue<int> aux;

            while(!celulas.empty()){
                int value = celulas.top(); celulas.pop();
                if(value < minimum){
                    int dif = minimum - value; // segundos a restar después
                    aux.push(M-dif);
                    aux.push(N-dif);
                }else{
                    int myVal = value - minimum;
                    if(myVal == 0){
                        aux.push(M);
                        aux.push(N);
                    }else{
                        aux.push(myVal);
                    }
                }
            }
            while(!aux.empty()){
                celulas.push(aux.front()); aux.pop();
            }
        }
        cout << celulas.size() << "\n";
    }
}