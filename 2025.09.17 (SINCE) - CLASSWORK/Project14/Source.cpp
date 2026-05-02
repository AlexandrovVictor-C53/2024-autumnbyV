#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;


void distribute(string s1, string s2)
{
	ifstream s(s1);
	if (s.is_open())
	{
		cout << 'ok';
	}
	string st;
	string name;
	int a = 1;
	stringstream str; // str – строковый поток ввода и вывода

	while (getline(s, st))
	{
		str << s2;
		str << a; // записали в строковый поток целое число
		str << ".txt";
		str >> name;
		cout << name;
		ofstream n(name);
		++a;
		n << st;
		str.clear();
	}
}


int main()
{
	ofstream g("g.txt");
	g << "first ";
	g << "second ";
	g << "forth ";
	string s;
	

	distribute("g.txt" , "Monday");

	return EXIT_SUCCESS;
}