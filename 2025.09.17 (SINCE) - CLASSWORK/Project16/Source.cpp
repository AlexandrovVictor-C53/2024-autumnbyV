#include<iostream>
#include<cstdlib>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<algorithm>

using namespace std;

class Vector
{

	vector<double> v; 

	public: 

	Vector(vector <double>& v1) : v(v1) {}
	
	void input(std::istream& is) {
		v.clear();

		std::string line;
		std::getline(is, line);

		std::istringstream iss(line);
		double value;
		while (iss >> value) {
			v.push_back(value);
		}
	}
};

	
int main()
{
	
	return EXIT_SUCCESS;

}