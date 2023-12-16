#include <set>
#include <iostream>

using namespace std;


int N;


int main(){

    while(cin >> N){
        if(N == 0) break;
        set<int> unicos;
        for(int i=0;i<N;i++){
            int c;
            cin >> c;
            unicos.insert(c);
        }
        cout << unicos.size() << "\n";
    }
}