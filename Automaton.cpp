#include "Automaton.h"
#include <fstream>
/* depending on dest value 0,1 or 2 initilizes a,b or q correspondingly */
void Automanton::writeInto(string s, int dest)
{
	int k = 0;// for keeping track of the array we initilize
	if (dest == 0)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ',' && s[i] != ' ')//write into a[k] until seeing ','
			{
				a[k] += s[i];
			}
			else if(s[i] == ',') k++;//move on to the next element of a
		}
		a_size = k + 1;//save the size of a
	}
	else if (dest == 1)
	{
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] != ',' && s[i] != ' ')
			{
				b[k] += s[i];
			}
			else if(s[i] == ',') k++;
		}
		b_size = k + 1;
	}
	else if (dest == 2)
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == 'q')
				q++;
		}
}
/* finds b and q from the string and makes a pair*/
pair<string,int> Automanton::pairUp(string s)
{
	string b = "";
	int q = 0;
	int k = s.find_first_of(',', 0); // divide string into 2 parts
	for (int i = 0; i < s.length(); i++)
	{
		if (i < k && s[i] != ' ') // write substring before , into b
		{
			b += s[i];
		}
		else if( i >= k) //get q value from substing after ,
		{
			k = s.find_first_of("0123456789", k+1);// get the first number after q
			i = k;
			q = q * 10 + (s[i] - '0');
		}
	}
	return pair<string, int>(b,q);
}

Automanton::Automanton(string s):a_size(0),b_size(0),q(0)
{
	fstream newfile;
	int indx = 0;
	newfile.open(s, ios::in);
	
	if (newfile.is_open())
	{
		string c;
		int k = 0, 
			i = 0, 
			q_ = 0;//index of each row 
		while(newfile>>c)//read a string from file into c
		{
			if (k < 3)
				writeInto(c, k++);//write into a,b or q
			else if (k == 3 && c != "|") //read each cell of the table from the file
			{
				pair<int, string> p(q_, a[i++]);//make pair of each state and input alphabet value
				table.insert({ p , pairUp(c) });//pair up p with corresponding pair of the table written in c
				if (i == a_size - 1)
				{
					//go to the first cell of the next row
					q_++;
					i = 0;	
				}
			}

		}

		
		newfile.close();
	}
}
/*gets an input string(e.g. "a1 a2 a1 a3 a2 a1")
  outputs corresponding string */
void Automanton::output(string input)
{
	int state = 0;//start from the initial state
	string sub = "";
	int s = -1,e = -1;//start and ending indexes of substring
	for (int i = 0; i < input.length(); i=e)
	{
		s = input.find_first_not_of(' ', e + 1);
		e = input.find_first_of(' ', e + 1);
		sub = input.substr(s, e - s);
		cout <<table[{state, sub}].first << " ";
		state = table[{state, sub}].second;
	}
}
