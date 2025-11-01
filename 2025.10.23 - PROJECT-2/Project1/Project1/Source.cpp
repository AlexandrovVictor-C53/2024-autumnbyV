#include<iostream>
#include<cmath>

using namespace std;

int main()
{
	// обЪявление переменных и констант 
	double x = 0;
	double t = 0;

	double A = 0;
	double E_0 = 0;
	double tau_R = 0; // время релаксации
	double B = 0; //Модуль объёмного сжатия ????
	double tau = 0; //
	double v_0 = 0;
	double h_0 = 0;
	double E_inf = 0;
	double m = 0;

	// начальные данные ДУ
	double Ksi = 0;
	double Eta = 1;
	double F = 0;
	double f = 0;
	

	// ввод данных
	cout << "Введите значения A, E0, E_inf, B, h0, v0, tau_R, m: \n"; // сколько и чего вводить ???
	cin >> A >> E_0 >> E_inf >> B >> h_0 >> v_0 >> tau_R >> m;

	// функции безразмерных переменных 
	double beta = -(B * v_0 * tau_R) / h_0;
	double Ksi = x / ( v_0 * tau_R);
	double alpha = (A * E_0 * tau_R * tau_R) / (m * h_0);
	double tau = t / tau_R;
	double P = E_inf / E_0;

	// 	функции производных
	double dKsi_dTau = Eta;
	double dEta_dTau = alpha * F;
	double dF = exp(beta * Ksi) * dKsi_dTau + P*f - F;
	double Df = exp(beta * Ksi) * dKsi_dTau;

	if (alpha > 1 || alpha < 0) 
	{
		return -1;
	}

	else 
	{
		return 0;
	}
		

	if (beta > 1 || beta < 0) 
	{
		return -1;
	}
	else {
		return 0;
	}

	cout << "dKsi_dTau=" << dKsi_dTau << "  dEta_dTau=" << dEta_dTau << "  dF=" << dF << "  df=" << Df << endl;
	return 0;
}
