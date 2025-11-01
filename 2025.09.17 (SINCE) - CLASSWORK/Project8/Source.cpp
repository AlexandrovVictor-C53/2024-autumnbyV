#include <regex> // regular expression
#include<iostream>
using namespace std;

bool ex_match(string s)
{
	regex pattern(".*Peter.*");
	// pattern Ц объект класса Ђрегул€рное выражениеї
	return regex_match(s, pattern);
}
bool ex_search(string s)
{
	string str = "Peter";
	return regex_search(s, regex(str));
	// regex(str) Ц временный безым€нный объект, содержащий регул€рное
	// выражение, записанное в строке str
}

// сырой литерал: R'((\d{4} ){3}\D{4})'
int main()
{
	cout << ex_match("Peter") << endl; // 1
	cout << ex_match("Pyotr") << endl; // 0
	cout << ex_match("Peterhof") << endl; // 1
	cout << ex_match("St.Petersburg") << endl; // 1
	cout << ex_search("Peter") << endl; // 1
	cout << ex_search("Pyotr") << endl; // 0
	cout << ex_search("Peterhof") << endl; // 1
	cout << ex_search("St.Petersburg") << endl; // 1

	return EXIT_SUCCESS;
}