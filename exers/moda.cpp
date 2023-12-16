#include <iostream>
#include <queue>
#include <map>
#include <set>

using namespace std;

deque<int> identificadores;
int N, itara, jotara; // n Camisas; itara = n camisas añadidas por izqd; jotara = n camisas añadidas por dcha
map<int, set<int>> unicos; // <Label, <Posiciones relativas>> 
set<int> unicoSet; // set de camisas unicas; almacena sus posiciones relativas

pair<int, int> ita={-1, -1}, jota={-1,-1}; // <dist, label>

void revisar(int label, int pos) {
	if (unicos[label].size() == 1) {
		unicos[label].push_back(pos);
		unicoSet.erase(pos);
	}
	else {
		unicos[label].push_back(pos);
		unicoSet.insert(pos);
	}
}

void imprimirUnicoSet(){
	for(auto it = unicoSet.begin(); it != unicoSet.end(); it++){
		cout << *it << " ";
	}
	cout << "\n";
}

void preguntarse() {

	int ita = *unicoSet.begin();
	int jota = *unicoSet.rbegin();

	int valido = abs(jota - N);

	cout << "---\n";
	cout << ita << " | " << jota << " \n";
	imprimirUnicoSet();
	cout << "---\n";

	if(!unicos.empty()){
		if(valido == abs(ita)){
			int dif = itara - abs(ita);
			cout << dif << " CUALQUIERA\n";
		}else{
			if(valido < abs(ita)){
				int dif = jotara - valido;
				cout << dif << " DERECHA\n";
			}else{
				int dif = abs(itara - ita);
				cout << dif << " DERECHA\n";
			}
		}
	}else{
		cout << "NADA INTERESANTE\n";
	}



}

void moda() {
	while (cin >> N) {
		identificadores.assign(0, {});
		unicos.clear();

		for (int i = 0; i < N; i++) {
			int id;
			cin >> id;
			identificadores.push_back(id);
			revisar(id, i);
		}
		int E;
		cin >> E;
		for (int i = 0; i < E; i++) {
			char accion;
			cin >> accion;

			switch (accion) {
				int param;
			case 'I': {
				cin >> param;
				identificadores.push_front(param);
				itara++;
				revisar(param, -i);
				break;
			}
			case 'D': {
				cin >> param;
				identificadores.push_back(param);
				jotara++;
				revisar(param, N+i);
				break;
			}
			case 'i': {
				int mId = identificadores.front();
				identificadores.pop_front();
				unicos[mId]--;
				if(unicos[mId] == 1) unicoSet.insert(N+i-1);
				N--; 
				break;
			}
			case 'd': {
				int mId = identificadores.back();
				identificadores.pop_back();
				unicos[mId]--;
				if(unicos[mId] == 1) unicoSet.insert(-i);
				break;
			}
			case 'P': {
				preguntarse();
				break;
			}
			}
		}
		std::cout << "---\n";
	}
}


int main(){
    int T;
    cin >> T;
    while(T--) moda();
}