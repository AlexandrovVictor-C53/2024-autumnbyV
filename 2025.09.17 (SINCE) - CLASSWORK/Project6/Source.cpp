#include <iostream>
#include <vector>
#include <algorithm>

class Matrix
{
private:
	std::vector <std::vector<double>> a;

public:
	double size;


	int row() const
	{
		return a.size();
	}
	int col() const
	{
		return a[0].size();
	}


	Matrix(int n = 0, int m = 0)

	{
		a.resize(n);
		for (int i = 0; i < n; ++i)
			a[i].resize(m);
	}



	double& operator () (int i, int j)
	{
		return  a[i][j];
	}
	// обращение к элементу матрицы
	// (перегруженная операция вызова функции)

	const double& operator () (int i, int j) const
	{
		return  a[i][j];
	}
	// для константных объектов

	Matrix(const Matrix&) = default;
	// конструктор копирования
	Matrix& operator=(const Matrix&) = default;
	// присваивание матриц


	~Matrix() = default;
	

	std::ostream& operator<<(std::ostream&out, const Matrix& M)
	{
		for (int i = 0; i, M.row(); ++i)
		{
			out << M(i, j) << " ";

		}
		out << std::endl;
		return 0;
	}




	void divide(int i, double coef)
	{
		for (int j = 0;j < col(); ++j)
		{
			a[i][j] = a[i][j] / coef;
		}
	}

	void subtract(int i = 0, int j = 0, double coef)
	{
		for (int k = 0; k < col(); ++k)
		{
			a[j][k] = a[j][k] - a[i][k] * coef;
		}

	}

	void transform()
	{
		for (int k = 0; k < row(); ++k)
		{
			divide(k, a[k][k]);
				for (int i = 0; i < row(); ++i)
				{
					if (k != i)
					{
						subtract(k, i, a[i][k]);
					}

				}
		}
	}

	void swapr(int i, int j) 
	{
		for (int k = 0; j < col();++k) 
		{
			std::swap(a[i][k], a[j][k]);
		}

	}


	int maxElem(int n) 
	{
		int index = n;
		double max = a[n][n];
		for (int i = n + 1; i < row(); ++i)
		{
			if (max < fabs(a[i][n]))
			{
				index = i;
				max = fabs(a[i][n]);
			}
		}
		return index;
	}

	void transform2()
	{
		for (int k = 0; k < row(); ++k)
		{
			int c = maxElem(k);
			swapr(c, k);

			divide(k, a[k][k]);
			for (int i = 0; i < row(); ++i)
			{
				if (k != i)
				{
					subtract(k, i, a[i][k]);
				}

			}
		}
	}
};




int main()
{
	
	Matrix A, B, C;
	std::cin >> A >> B;
	std::cout << A << B;

	int n = 3;
	Matrix A(n, n);
	A(0, 0) = 7; A(0, 1) = 2; A(0, 2) = 1;
	A(1, 0) = 4; A(1, 1) = 9; A(1, 2) = 1;
	A(2, 0) = 2; A(2, 1) = 3; A(2, 2) = 6;

	return EXIT_SUCCESS;
}