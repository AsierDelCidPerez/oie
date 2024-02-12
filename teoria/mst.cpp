#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

struct ufds {
    int numSets;
    vector<int> p;

    ufds(int N) : numSets(N), p(N, -1) {}

    int find(int i){
        return (p[i] < 0) ? i : p[i] = find(p[i]);
    }

    void join(int i, int j){
        int x = find(i), y = find(j); 
        if(p[x] > p[y]) {
            swap(x, y);
        } // x siempre contiene al arbol mayor
        p[x] += p[y];
        p[y] = x;
        --numSets;
    }

    bool related(int i, int j){
        return find(i) == find(j);
    }

    int size(int i){
        return -p[find(i)];
    }

};

using arista = tuple<int, int, int>; // <coste, extremos>
int V, A;

int kruskal(vector<arista> & aristas){
    sort(aristas.begin(), aristas.end()); // Ordenamos de menor a mayor
    sort(aristas.rbegin(), aristas.rend()); // Ordenamos de mayor a menor
    ufds UF(V);
    int coste = 0;

    for(auto[c, u, v] : aristas){
        if(UF.related(u, v)){ // ¿Crea ciclos?
            UF.join(u, v);
            coste += c;
        }
        if(UF.numSets == 1) break;
    }

    return coste;

}

void recogerDatos (){
    cin >> V >> A;
    vector<arista> aristas;
    for(int i=0;i<A;i++){
        int u, v, c; cin >> u >> v >> c;
        aristas.push_back({c, u, v});
    }

    int mPrice = kruskal(aristas);
    cout << mPrice << "\n";
}


int main(){
    /*
    Los árboles de recubrimiento de un grafo G es un subgrafo T tal que:
        - T es un árbol: es conexo y acíclico.
        - T es de recubrimiento: alcanza todos los vértices de G.
    
    Si T es un ábrol de recubrimiento de un grafo G con V vértices se cumple que:
        - T contiene exactamente V-1 aristas
        - Al eliminar cualquier arista de T deja de ser conexo.
        - Añadir cualquier arista a T crea un ciclo.
    
    Dado un grafo valorado no dirigido, encontrar un árbol de recubrimiento de coste mínimo (ARM)
    Si todos los costes del grafo son distintos tan solo existe un solo ARM.

    Aplicaciones de los ARMs:
        - Verificación facil en tiempo real.
        - Búsqueda de redes de carreteras en imágenes de satélites o aéreas.
        - Reducción del almacenamiento de datos en la secuenciación de aminoácidos de una protéina.
        - Algoritmos de aproximación para problemas NP-dificiles (por ejemplo TSP)
        
    Algoritmos:
        -> Algoritmo de Kruskal. O(Alog(A))
            1.- Considera las aristas en orden creciente de coste y cada arista se selecciona si no crea ciclos.
            2.- Mientras que no se haya seleccionado V-1 aristas entonces:
                2.1.- Se selecciona la arista de coste mínimo no seleccionada.
                2.2.- ¿Crea ciclos?
                    2.2.1.- Sí -> Se ignora (continúa el bucle).
                    2.2.2.- No -> Se selecciona.
            ¿Pero como se comprueba que forma ciclos o no?
            Si formase ciclos entonces ambos nodos que se unen comparten raíz -> se puede usar UFDS.
            * Téngase en cuenta que:
                -> Si el grafo no es conexo entonces devuelve la sumatoria de los ARMs de cada grafo conexo.
        
        -> Algoritmo de Prim. 
            2.- Se selecciona un nodo
            1.- Mientras no se haya seleccionado todos los nodos:
                1.1.- Se 
    Variantes del problema de ARM:
        1.- Arbol de recubrimiento máximo
        2.- ARMs "minimos" cuando algunas aristas ya están seleccionadas.
        3.- Bosque de recubrimiento mínimo (No hace falta conectarlos todos)
            3.1.- Conexiones entre ciudades y tirar cables para que haya conexiones. Hay también conexión por cable (es más caro)
        4.- El camino minimax o maximin
        5.- Segundo ARM_2 (ARM_1 < ARM_2), de entre aquel que solo es mayor a ARM_1
    */


   recogerDatos();

}