#include <iostream>

using namespace std;

string query(int m){
    cout << "? " << m << endl;
    string p; cin >> p; return p;
}

int main(){
    int in, fin;
    while(cin >> in >> fin){

        if(in == 0 && fin == 0) break;

        int l = in-1, r = fin;
        // Se aplica Binary Search
        /*
            Invariantes:
                .- [in...l] no contiene el número
                .- (l...r] contiene el número
        */
       while(l+1 < r){
        int m = (l+r)/2;
        string q = query(m);
        if(q == "<="){
            r = m;
        }else{
            l = m;
        }
       }
       cout << "Respuesta: " << r << endl; 
    }
}