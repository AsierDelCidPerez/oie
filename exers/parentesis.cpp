#include <iostream>
#include <string>
#include <stack>

using namespace std;


pair<char, char> parentesis('(', ')');
pair<char, char> brackets('[', ']');
pair<char, char> corchetes('{', '}');


const pair<char, char> EQUIVALENCIAS[3] = {
	parentesis,
	brackets,
	corchetes
};

string getUtilString(string miString)
{

	string myString = "";


	for (char c : miString)
	{
		for (int i = 0; i < 3; i++)
		{
			if (c == EQUIVALENCIAS[i].first || c == EQUIVALENCIAS[i].second)
			{
				myString += c;
				break;
			}
		}
	}

	return myString;

}

bool eval(string util)
{
	stack<char> myPila;

	for (char c : util)
	{
		for (int i = 0; i < 3; i++)
		{
			if (c == EQUIVALENCIAS[i].first)
			{
				myPila.push(c);
				break;
			}
			else if (EQUIVALENCIAS[i].second == c && !myPila.empty())
			{
				if (myPila.top() == EQUIVALENCIAS[i].first)
				{
					myPila.pop();
					break;
				}
				else {
					return false;
					break;
				}
			}
			else if (EQUIVALENCIAS[i].second == c) {
				return false;
				break;
			}

		}
	}

	if (myPila.empty()) return true;
	else return false;

}

void ex1()
{
	string miString;

	while (getline(cin, miString)) {

		string util = getUtilString(miString);

		if (eval(util))
		{
			cout << "SI\n";
		}
		else {
			cout << "NO\n";
		}
	}
}


int main(){
    ex1();
}