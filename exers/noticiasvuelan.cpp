
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> components;
vector<int> tamano;

int getRoot(int i){
    int parent = components[i];
    while(parent != components[parent]){
        parent = components[parent];
    }
    return parent;
}

void join(int i, int j){
    int rootI = getRoot(i);
    int rootJ = getRoot(j);
    if(rootI != rootJ){
        if(tamano[rootI] < tamano[rootJ]){
            components[rootI] = rootJ;
            tamano[rootJ] += tamano[rootI];
        }else{
            components[rootJ] = rootI;
            tamano[rootI] += tamano[rootJ];
        }
    }
}

void printTree(){
    for(int i=1;i<components.size();i++){
        cout << tamano[getRoot(i)] << ((i+1 == components.size()) ? "" : " ");
    }
    cout << "\n";
}

int main(){
    int n, m;
    while(cin >> n >> m){
        tamano.assign(n+1, 1);
        components.assign(n+1, -1);

        iota(components.begin(), components.end(), 0);

        for(int i=0;i<m;i++){
            int nPersonas;
            int anterior = -1;
            int actual;
            cin >> nPersonas;
            for (int j = 0; j < nPersonas; j++) {
                cin >> actual;
                if (anterior != -1) {
                    join(anterior, actual);
                }
                anterior = actual;
            }
        }

        printTree();

    }
}
