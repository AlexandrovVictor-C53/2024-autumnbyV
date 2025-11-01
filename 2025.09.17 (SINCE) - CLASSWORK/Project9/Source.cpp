#include <regex> // regular expression
#include<iostream>
using namespace std;



bool card_match(string s)
{
	regex pattern("(\\d{4} ){3}\\d{4}");
	return regex_match(s, pattern);
}

bool numTel_match(string s)
{
	regex pattern("\\d+ [(]\\d+[) \\d{3}[-]\\d\\d[-]\\d\\d");
	return regex_match(s, pattern);
}

bool numAuto_match(string s)
{
	regex pattern("[AVEKMNORCTUH]\\d\\d\\d[][] \\d\\d\\d?");
	return regex_match(s, pattern);
}

bool email_match(string s)
{
	regex pattern("(\\w+[.]\\w+)*|\\w+@(\\w+\\.)+\\w+");
	return regex_match(s, pattern);
}

/*bool IP_match(string s)
{
	regex pattern("");
	return regex_match(s, pattern);
}*/

// сырой литерал: R'((\d{4} ){3}\D{4})'
//      \\w  - буква или цифра или пробел

int main()
{
	

	cout << card_match("2202 1020 9339 2101") << endl;
	cout << numTel_match("8 (905) 132-02-31") << endl;
	cout << numAuto_match("8 (905) 132-02-31") << endl;
	cout << email_match("8 (905) 132-02-31") << endl;
	//cout << IP_match("8 (905) 132-02-31") << endl;

	return EXIT_SUCCESS;
}