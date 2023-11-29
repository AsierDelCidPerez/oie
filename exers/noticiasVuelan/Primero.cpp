#include <iostream>
#include <vector>
using namespace std;

int hallar_raiz(int i, vector<int> &componentes) {
  int padre = componentes[i];
  while (padre != componentes[padre]) {
    padre = componentes[padre];
  }
  return padre;
}

void unir_nodos(int i, int j, vector<int> &componentes, vector<int> &tamano) {
  int raiz_i = hallar_raiz(i, componentes);
  int raiz_j = hallar_raiz(j, componentes);
  if (raiz_i != raiz_j) {
    if (tamano[raiz_i] < tamano[raiz_j]) {
      componentes[raiz_i] = raiz_j;
      tamano[raiz_j] += tamano[raiz_i];
    } else {
      componentes[raiz_j] = raiz_i;
      tamano[raiz_i] += tamano[raiz_j];
    }
  }
}

void imprimir_conexiones(vector<int> &componentes, vector<int> &tamano) {
  for (int i = 1; i < componentes.size(); i++) {
    cout << tamano[hallar_raiz(i, componentes)] << (i+1 ==componentes.size()) ? "" : " ";
  }
  cout << "\n";
}

int main() {
  vector<int> tamano, componentes;
  int n, m;
  while (cin >> n >> m) {
    tamano.resize(n + 1);
    componentes.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      tamano[i] = 1;
      componentes[i] = i;
    }

    for (int i = 0; i < m; i++) {
      int num_personas;
      int persona_anterior = -1;
      cin >> num_personas;
      int persona_actual;
      for (int j = 0; j < num_personas; j++) {
        cin >> persona_actual;
        if (persona_anterior != -1) {
          unir_nodos(persona_anterior, persona_actual, componentes, tamano);
        }
        persona_anterior = persona_actual;
      }
    }
    imprimir_conexiones(componentes, tamano);
  }
}