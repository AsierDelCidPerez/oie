#include <iostream>
#include <deque>
using namespace std;


struct tElem{
	int elem, pos;
};


// Explain the code below:
// Optimised solution: O(n)

// Create an optimised solution for the problem of finding the maximum of each subarray of size k in an array of size n.

bool resuelveCaso() {
	int n, k; // n = num of elements, k = num of elements to be considered
	cin >> n >> k; // Read n and k
	if (n == 0 && k == 0) // If n and k are 0, return false
		return false;
	deque <tElem> colaK, candidatosMax; // colaK = deque of elements to be considered, candidatosMax = deque of candidates to be the max
	tElem max = { 0, -1 }; // max = max element
	int valor; // value of the element
	for (int i = 0; i < k; ++i){ //Cojo el maximo
		cin >> valor; // Read value
		if (valor > max.elem){ // If value is greater than max
			max = { valor, i }; // max = value
		}
		colaK.push_back({ valor, i }); // Add value to the deque
	}
	deque <tElem> aux = colaK; // aux = colaK
	int maxCand = 0; // maxCand = max candidate
	while (!aux.empty()){ // Mientras que aux no este vacio
		if (aux.back().elem > maxCand && aux.back().pos != max.pos){ // Si el elemento de la cola es mayor que maxCand y su posicion es distinta a la de max
			maxCand = aux.back().elem; // maxCand = elemento de la cola
			candidatosMax.push_back(aux.back()); // Add element to candidatosMax
		}
		aux.pop_back(); // Pop element
	}
	cout << max.elem; // Print max
	 if (k < n) cout << " "; // If k < n, print space
	for (int i = k; i < n; ++i){ // Recorro el resto de elementos
		cin >> valor; // Read value
		if (!candidatosMax.empty() && candidatosMax.back().pos == colaK.front().pos) candidatosMax.pop_back(); // Si el elemento de la cola es el maximo, lo borro
		if (colaK.front().elem == max.elem){ // Si el elemento de la cola es el maximo
			if (!candidatosMax.empty()) { // Si candidatosMax no esta vacio
				max = candidatosMax.back(); // max = ultimo elemento de candidatosMax
				candidatosMax.pop_back(); // Borro el ultimo elemento de candidatosMax
			}
			else {
				max = { valor, i }; // max = valor
			}
		}
		colaK.pop_front(); // Borro el primer elemento de colaK
		if (valor > max.elem){
			max = { valor, i };
			if (!candidatosMax.empty()) candidatosMax.clear(); // Si candidatosMax no esta vacio, lo borro
		}
		else {
			if (candidatosMax.empty()) candidatosMax.push_back({ valor, i }); // Si candidatosMax esta vacio, meto el valor
			else{
				if (valor >= candidatosMax.front().elem){ // Si el valor es mayor o igual que el primer elemento de candidatosMax
					while (!candidatosMax.empty() && valor >= candidatosMax.front().elem) candidatosMax.pop_front(); // Borro los elementos de candidatosMax que sean menores que el valor
				}
				candidatosMax.push_front({ valor, i }); // Meto el valor en candidatosMax
			}
		}
		colaK.push_back({ valor, i });      // Meto el valor en colaK
		cout << max.elem; // Imprimo el maximo
		if(i < n - 1) cout << " "; // Si no es el ultimo elemento, imprimo un espacio
	}
	cout << '\n';
		return true;
}
int main() {
	while (resuelveCaso());
	return 0;
}