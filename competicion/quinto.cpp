#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N, M, T;

    priority_queue<int, vector<int>, greater<int>> celulas;

    while(cin >> N >> M >> T){
        celulas = priority_queue<int, vector<int>, greater<int>>();
        celulas.push(N);
        while(T!=0){
            int minimum = celulas.top();
            minimum = min(T, minimum);
            T-=minimum;
            queue<int> aux;
            while(!celulas.empty()){
                int value = celulas.top(); celulas.pop();
                if(value < minimum){
                    int dif = minimum - value; // segundos a restar después
                    aux.push(N+M-dif);
                    aux.push(N-dif);
                }else{
                    int myVal = value - minimum;
                    if(myVal == 0){
                        aux.push(N+M);
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