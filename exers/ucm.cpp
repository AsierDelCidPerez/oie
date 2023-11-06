#include <iostream>
#include <queue>
#include<vector>

using namespace std;

struct usuario {
    int id;
    int t;
    int periodo;
};

bool operator > (usuario a, usuario b){
    if(a.t > b.t) return true;
    if(a.t == b.t && a.id > b.id) return true;
    return false;
}



void ucm (){
    int N;
    while(cin >> N){
        if(N == 0) break;
        priority_queue<usuario, vector<usuario>, greater<usuario>> usuarios; // Por defecto la PQ es < (less), entonces nos devuelve el elemento mayor

        for(int i=0;i<N;i++){
            int id, periodo;
            cin >> id >> periodo;
            usuario m;
            m.id = id;
            m.periodo = periodo;
            m.t = periodo;
            usuarios.push(m);
        }

        int k;
        cin >> k;

        for(int i=0;i<k;i++){
            usuario miUser = usuarios.top();
            usuarios.pop();
            cout << miUser.id << "\n";
            miUser.t += miUser.periodo;
            usuarios.push(miUser);
            // imprimirCola(usuarios);
        }

        cout << "---\n";
    }
}

int main(){
    ucm();
}