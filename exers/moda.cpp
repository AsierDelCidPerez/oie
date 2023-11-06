#include <iostream>
#include <queue>
#include <map>

using namespace std;

deque<int> identificadores;
int N; // n Camisas
map<int, int> unicos;


void revisar(int const& id) {
	if (unicos.count(id)) {
		unicos[id]++;
	}
	else {
		unicos[id] = 1;
	}
}

void preguntarse() {

	auto itS = identificadores.begin();
	auto itE = identificadores.end();
	itE--;

	bool seguir = false;
	for(auto i : unicos){
		if(i.second == 1){
			seguir = true;
			break;
		}
	}

	if(!seguir){
		std::cout << "NADA INTERESANTE\n";
		return;
	}

	for (int i = 0; i <= identificadores.size()/2; i++) {

		int a = *itS;
		int b = *itE;


		if (unicos[*itS] == 1 && unicos[*itE] == 1) {
			std::cout << (i + 1) << " CUALQUIERA\n";
			return;
		}

		if (unicos[*itS] == 1) {
			std::cout << (i + 1) << " IZQUIERDA\n";
			return;
		}

		if (unicos[*itE] == 1) {
			std::cout << (i+1) << " DERECHA\n";
			return;
		}

		itS++;
		itE--;
	}

	std::cout << "NADA INTERESANTE\n";

}

void moda() {
	while (cin >> N) {

		identificadores.assign(0, {});
		unicos.clear();

		for (int i = 0; i < N; i++) {
			int id;
			cin >> id;
			identificadores.push_back(id);
			revisar(id);
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
				revisar(param);
				break;
			}
			case 'D': {
				cin >> param;
				identificadores.push_back(param);
				revisar(param);
				break;
			}
			case 'i': {
				int mId = identificadores.front();
				identificadores.pop_front();
				unicos[mId]--;
				break;
			}
			case 'd': {
				int mId = identificadores.back();
				identificadores.pop_back();
				unicos[mId]--;
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