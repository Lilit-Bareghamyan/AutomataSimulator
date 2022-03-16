#include "Automaton.h"
int main()
{
	char s1[100];
	cout << "Input the configuration file location:" << endl;
	cin.getline(s1, 100);
	Automanton a(s1);
	char s[100];
	cout << "Input the string:" << endl;
	cin.getline(s, 100);
	a.output(s);
}
