#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main() 
{
	
	class Polinomial;
		std::vector<double> coef;
public:
	Polinomial(std::vector<double> c);
		coef{c} {}
	double value(double x);
	{
		double res = coef[coef.size - 1];
		for (int i = coef.size() - 2; i > 0; --i)
			res = res * x + coef[i];
		
		
		
		return res;

	}

	double& getcoef(int ind)
	{
	}

	polynomial p(coef)
	{
		std::cout << p.getcoef[2];
		p.getcoef[1] = 10;


	}

	return 0;
}