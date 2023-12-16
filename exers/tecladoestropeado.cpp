#include <iostream>
#include <string>
#include <list>

using namespace std;

void tecladoEstropeado() {
    string entrada;
    while (getline(cin, entrada)) {
        list<char> resultado;
        auto it = resultado.begin();

        for (char c : entrada) {
            switch (c) {
            case '-':
                it = resultado.begin();
                break;
            case '+':
                it = resultado.end();
                break;
            case '*':
                if (it != resultado.end()) {
                    it++;
                }
                break;
            case '3':
                if (it != resultado.end()) {
                    it = resultado.erase(it);
                }
                break;
            default:
                resultado.insert(it, c);
            }

        }
        string result;
        result = string(resultado.begin(), resultado.end());

        cout << result << "\n";

    }
}

int main(){
    tecladoEstropeado();
}