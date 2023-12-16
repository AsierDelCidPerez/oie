
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct accidente {
	string fecha;
	int cantidad;
};

void accidentesAereos() {
	string myNum;
	while (getline(cin, myNum)) {
		int N = stoi(myNum);
		stack<accidente> accidentes;
		for (int i = 0; i < N; i++)
		{
			string fecha, cantidad;
			cin >> fecha >> cantidad;
			accidente nAcc;
			nAcc.fecha = fecha;
			nAcc.cantidad = stoi(cantidad);

			if (accidentes.empty()) {
				cout << "NO HAY\n";
			}
			else {
				bool result = false;
				while (!accidentes.empty()) {
					if (accidentes.top().cantidad > nAcc.cantidad) {
						cout << accidentes.top().fecha << "\n";
						result = true;
						break;
					}
					else {
						accidentes.pop();
					}
				}
				if (!result) {
					cout << "NO HAY\n";
				}
			}
			accidentes.push(nAcc);
		}
		cin.ignore();
        cout << "---\n";
	}
}

int main(){
    accidentesAereos();
}