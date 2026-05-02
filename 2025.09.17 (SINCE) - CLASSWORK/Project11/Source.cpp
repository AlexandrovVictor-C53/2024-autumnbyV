#include<fstream>
#include<iostream>
 
using namespace std;

int main()
{
	ofstream f("f.txt");
	f << 2345;
	return 0;
}