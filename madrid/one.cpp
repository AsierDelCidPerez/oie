#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        long long int A, B, D, R;
        cin >> A >> B >> D >> R;
        cout << (ceil((B-R)/D) - floor((A-R)/D)) +1 << "\n";
    }
}