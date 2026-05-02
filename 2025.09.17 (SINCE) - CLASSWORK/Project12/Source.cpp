#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string> // для работы со строками
using namespace std;
int main()
{
	ifstream g("g.txt");
	// открываем файл "f.txt" на чтение
	// сам файл будет связан с файловым потоком g
	string s; 
	int sum = 0, i, j;
	while (g >> s >> i >> j)
		// считываем парами, пока не кончится файл
		//sum = sum + i + j;
	cout << s << " " << i + j;
	//cout << sum << endl; // вывод суммы на экран
	return EXIT_SUCCESS;
}