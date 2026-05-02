#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<sstream>
using namespace std;


void summ (string s1, string s2)
{
	ifstream s(s1);
	string st;

	while (getline(s, st)) 
	{

		stringstream str;
		ofstream g(s2);
		int x = 0;
		int summ = 0;

		while (str >> x)
		{
			summ += x;
		}
	}
}



int main()
{
	ofstream g("g.txt");
	g << "12 5";
	g << "4 ";
	g << "6 ";
	string s;


	summ("g.txt", "Monday");
	return 0;
}