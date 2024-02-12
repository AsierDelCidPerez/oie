#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <cassert>
using namespace std;

int random(int a, int b) {
  return a + rand() % (b-a+1);
}

int ini, fin;
int N; // ¿x?

#define DOMJUDGE
#ifndef DOMJUDGE
string query(int m) {
  if (N <= m) return "<=";
  else return ">";
}
#else
string query(int m) {
  cout << "? " << m << endl;
  string resp;
  cin >> resp;
  return resp;
}
#endif

bool resuelve() {
#ifndef DOMJUDGE
  ini = 1; fin = 10;
#else
  cin >> ini >> fin;
#endif
  
  if (ini == 0 && fin == 0)
    return false;
  
#ifndef DOMJUDGE
  N = random(ini,fin);
#endif
  
  int l = ini-1, r = fin;
  // ¿x? > l   &&   ¿x? <= r
  while (l+1 < r) {
    int m = (l+r) / 2;
    if (query(m) == "<=") r = m-1;
    else l = m;
  }
  
#ifndef DOMJUDGE
  if (r != N) cout << "FALLO: " << ini << ' ' << fin << ' ' << N << ' ' << r << endl;
#else
  cout << "Respuesta: " << r << endl;
#endif
  
  return true;
}

int main() {
#ifndef DOMJUDGE
  for (int i = 1; i <= 100; ++i)
    resuelve();
#else
  while (resuelve());
#endif
  
  return 0;
}