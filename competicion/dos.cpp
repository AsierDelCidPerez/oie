#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>

using namespace std;

int N;

vector<string> nombres;
vector<set<int>> bingos;


vector<string>  delimitar(string str, char delim)
{
	vector<string> delims;
	string actual = "";
	int finali = 0;
	for (char c : str) {
		if (c == delim)
		{
			//cout << actual;
			delims.push_back(actual);
			actual = "";
		}
		else {
			actual += c;
		}
		finali++;
	}

	if (actual.size() > 0) delims.push_back(actual);

	return delims;
}

void resuelve(){
        cin.ignore();
        nombres.assign(N, "");
        bingos.assign(N, set<int>());

        for(int i=0;i<N;i++){
            string boleto;
            cin >> nombres[i];
            cin >> boleto;


            while(boleto != "0"){
                bingos[i].insert(stoi(boleto));
                cin >> boleto;
            }

        }

        int K;
        cin >> K;
        priority_queue<string, vector<string>, greater<string>> ganadores;
        bool entrado = false;
        for(int i=0;i<K;i++){
            int t; cin >> t;
            for(int j=0;!entrado && j<N;j++){
                bingos[j].erase(t);
                if(bingos[j].size() == 0) ganadores.push(nombres[j]);
            }
            // sort(ganadores.begin(), ganadores.end());
            if(ganadores.size() > 0 && !entrado) {
                while(!ganadores.empty()){
                    cout << ganadores.top() << " ";
                    ganadores.pop();
                }
                cout << "\n";
                entrado = true;
            }
        }
}

int main(){
    while(cin >> N){
        if(N == 0) break;
        resuelve();
    }
}