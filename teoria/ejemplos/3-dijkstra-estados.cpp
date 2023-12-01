#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

// using info = vector<int>;

using estado = pair<int, int>; // Estado primera y segunda garrada, la 3ª se calcula.
using info = pair<int, estado>;

vector<vector<pair<int, info>>>;

int A, B, C, D;

map<info, int> dist;

void dijkstra(){
    vector<int> cap = {A, B, C};
    vector<vector<int>> dist(cap[0]+1, vector<int>(cap[1]+1, -1));
    priority_queue<info, vector<info>, greater<info>> q;
    
    estado origen = {cap[0], 0};
    q.push({0, origen});
    dist[origen.first][origen.second] = 0;

    while(!q.empty()){
        auto [t, u] = q.top(); q.pop();
        auto [a, b] = u;
        if(t > dist[a][b]) continue;
        int c = cap[0] - a - b;
        vector<int> act = {a, b, c};

        //Vemos si tenemos solución
        for(int x : act){
            if(x == D){
                cout << t << "\n";
                return;
            }
        }

        // transvases
        for(int i=0;i<3;i++){ // Posibilidades de a (i)
            for(int j=0;j<3;j++){ // Posibilidades de b (j)
                if(i == j) continue; // No puedo transferir de una jarra a ella misma
                // Movemos de i a j todo lo que podamos.
                vector<int> nuevo = act; // lo que tienen las tres vasijas tras este movimiento.
                int muevo = min(act[i], cap[j] - act[j]);
                nuevo[i] = act[i] - muevo;
                nuevo[j] = act[j] + muevo;
                if(t + muevo < dist[nuevo[0]][nuevo[1]]) { // Puedo mejorar
                    dist[nuevo[0]][nuevo[1]] = t + muevo;
                    q.push({t + muevo, {nuevo[0], nuevo[1]}});
                }

            }
        }

    }

    cout << "BOOM\n";

}

/*
void dijkstra(){

    priority_queue<pair<int, info>, vector<pair<int, info>>, greater<pair<int, info>>> q;
    dist[{a, 0, 0}] = 1;

    vector<int> capacidades = {a, b, c};

    q.push({0, {a, 0, 0}});

    while(!q.empty()){
        auto [c, v] = q.top();
        for(int i=0;i<v.size();i++){
            if(v[i] > 0){
                for(int j=0;j<3;j++){
                    info aux;
                    aux = v;

                    aux[i]-=capacidades[j];
                    aux[j]+=capacidades[j];

                    if(v[i] > capacidades[j] && (dist[aux] == 0 || capacidades[j] + dist[v] < dist[aux])){
                        v[i]-=capacidades[j];
                        v[j]+=capacidades[j];
                    }
                }
            }
        }
    }



}

*/

void dijkstraEstados(){
    /*
        ----------------------------------
        -------- Dijkstra estados --------
        ----------------------------------
        Imagínate que tenemos tres jarras con agua:
            - Jarra de 8L (primera)
            - Jarra de 5L
            - Jarra de 3L
        
        La primera jarra está llena, el resto vacías. Una jarra llena no puede recibir agua.

        Queremos hacer que al menos una de las jarras llege a tener D litros (en este caso D=4).
        Reglas: solo se puede pasar agua HASTA QUE SE LLENA la jarra (no son jarras medidoras)

        Utilizaremos como estado la cantidad de agua que hay en cada jarra.
        Se debe hacer moviendo la menor cantidad de agua.
        1L/s. Minimizar tiempo.

        Al principio: <8, 0, 0> (terna) -> de aquí podemos mover agua a la segunda o a la tercera.
            1º Adyacentes de <8, 0, 0>
        Desde <8, 0, 0> podemos llegar a:
                -> <3, 5, 0>
                    -> <8, 0, 0> NO (nos hace retroceder)
                    -> <0, 5, 3>
                    -> <3, 2, 3>
                        -> <6, 2, 0>
                -> <5, 0, 3>
                    -> <8, 0, 0> NO (nos hace retroceder)
                    -> <0, 5, 3> NO (nos hace retroceder)

        
        Punto 2.- Camino mínimo con un número par de aristas.

        Un hombre quiere recorrer el camino minimo desde un nodo origen A hasta un nodo
        destino B transitando por un número par de calles o aristas.
        Ver ejemplos/grafosdijkstra/a.dot
        Partimos de 0 hasta 
        <0, 0> // Izquierda info, derecha paridad
        |-- <1, 1>
        |    |-- <5, 0>
        |    |   |-- <2, 1>
        |    |-- <2, 0>
        |-- <2, 1>
        |    |-- <3, 0>
        |    |-- <4, 0>
    */



    cin >> A >> B >> C >> D;

    dijkstra();

}

int main(){
    int T;
    cin >> T;
    while(T--){
        dijkstraEstados();
    }
}