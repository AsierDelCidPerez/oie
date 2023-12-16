#include <iostream>
#include <vector>
#include <stack> 
#include <string> 

using namespace std;

void firstDsc(string& s) {
	vector<char> ns(s.length(), ' ');
	for (int i = 0; i < s.length();i++) {
		if (i % 2 == 0) {
			ns[i/2] = s[i];
		}else{
			ns[s.length() - i/2 - 1] = s[i];
		}
	}

	for (int i = 0; i < s.size();i++) {
		s[i] = ns[i];
	}
}

bool isVocal(char& ascii) {
	vector<int> vocales = { 65, 69, 73, 79, 85, 97, 101, 105, 111, 117 };
	for (int c : vocales) {
		if (c == ascii) {
			return true;
		}
	}
	return false;
}

void scdDsc(string& s) {
	for (int i = 0; i < s.length(); i++) {
		stack<char> pila;

		int j = i;
		while (j < s.length() && !isVocal(s[j])) {
			pila.push(s[j]);
			j++;
		}

		for (int k = i; k < j; k++) {
			s[k] = pila.top();
			pila.pop();
		}
		i = j;
	}
}

void anacleto() {
	string miS;
	while (getline(cin, miS)) {
		//cout << miS << "\n";
		firstDsc(miS);
		scdDsc(miS);

		cout << miS << "\n";
	}
}

int main(){
    anacleto();
}