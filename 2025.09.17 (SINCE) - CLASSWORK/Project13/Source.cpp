
// программа, у который написаны номера строк в начеле 

#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string> 
#include<regex> 

using namespace std;
int main()
{
	ifstream g("g.txt.txt");
	string s;
	while (getline(g, s)) 
	{
		//cout << s << ;
		regex pattern("^\\d+ ");
		cout << regex_replace(s, pattern, "") << endl;
	}
	return EXIT_SUCCESS;
}