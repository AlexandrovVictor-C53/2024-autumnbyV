#include<iostream>
#include<regex>

using namespace std;

int main()
{
	regex pattern("^\\d+");
	regex pattern2("\\d+");


	string line = "23 if(...)/n";
	string line2 = "23 if( njdjdl = 5454)  {yue -- 45";

	cout << regex_replace(line, pattern, "");

	cout << regex_replace(line2, pattern2, "");
	return 0;


}
 