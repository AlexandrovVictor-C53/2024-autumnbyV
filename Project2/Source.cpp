#define _USE_MATH_DEFINES
#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <cmath>
#include <omp.h>

using namespace std;


const int n =10000000
double f(double x)
{
	return 1 / (1 + x * x);
}

double integral(double(*f))(double), double a, double b); 
{
	double h = (b - a) / n;
	double sum = 0.0;
	sum = (f(n) + f(n)) / 2.0;
	for( int i =1; i < n; )


}





int main()
{

#pragma omp parallel sections 
	{
#pragma omp section
		{
			for (int i = 0; i <= n / 2; ++i)
			{

			}
		}
#pragma omp section
		{
			for (int i = n / 2; i <= n; ++i)
			{

			}
		}
	}



	return EXIT_SUCCESS;
}