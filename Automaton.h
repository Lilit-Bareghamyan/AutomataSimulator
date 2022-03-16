#pragma once
#include <iostream>
#include <string>
#include <map>
using namespace std;
#define MAX_ALPHABET_SIZE 20
#define MAX_STATE_SIZE 20
class Automanton
{
	string a[MAX_ALPHABET_SIZE]; //input alphabet of the automaton
	string b[MAX_ALPHABET_SIZE]; //output alphabet of the automaton
	int q; //set of states
	map<pair<int, string>, pair<string, int>> table;

	int a_size;
	int b_size;


	void writeInto(string s, int dest);
	pair<string,int> pairUp(string);


public:
	Automanton(string s);
	void output(string input);

};

