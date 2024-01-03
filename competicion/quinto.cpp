#include <iostream>
#include <queue>

using ll = long long int;

using namespace std;

int main(){
    int N, M, T;

    priority_queue<int, vector<int>, greater<int>> celulas;
    vector<int> yemas;
    priority_queue<int, vector<int>, greater<int>> aux;

    while(cin >> N >> M >> T){
        celulas.push(N); //tiempo que tardan en reproducirse en una
        while(T>0){
            int min = -1;
            aux = priority_queue<int, vector<int>, greater<int>>();
            for(int i=0;i<celulas.size();i++){
                int val = celulas.top(); celulas.pop();
                min = (min == -1) ? (val) : (min);
                min = (min > T) ? T : min;
                T-=min;
                if(i < yemas.size()){
                    int &aVal = yemas[i];
                    if(aVal < min){
                        aux.push(N-(aVal-min));
                        aVal = M;
                    }else{
                        aVal -= min;
                        if(aVal == 0) {
                            celulas.push(N);
                            aVal = M;
                        }
                    }
                }
                if(val == min){
                    celulas.push(N);
                    yemas.push_back(M);
                    // aux.push(M);
                }else{
                    celulas.push(val-min);
                }
            }
        }
        std::cout << celulas.size() << "\n";
    }
}