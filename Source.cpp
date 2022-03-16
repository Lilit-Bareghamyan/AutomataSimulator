#include "Automaton.h"
int main()
{
	Automanton a("C:\\automaton.txt");
	char s[100];
	cout << "Input the string: \n" << endl;
	cin.getline(s, 100);
	a.output(s);
}