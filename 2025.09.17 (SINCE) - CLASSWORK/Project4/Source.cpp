#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial {
public:
    std::vector<double> coef;

    Polynomial(const std::vector<double>& coefficients = {}) : coef(coefficients) {}

    double& operator[](size_t index) {
      
        if (index >= coef.size()) {
            coef.resize(index + 1, 0.0);
        }
        return coef[index];
    }
Polynomial operator+(const Polynomial& p1, const Polynomial& p2)
{
    size_t size1 = p1.coef.size();
    size_t size2 = p2.coef.size();
    size_t max_size = std::max(size1, size2);

    std::vector<double> res(max_size, 0.0);

    for (size_t i = 0; i < size1; i++)
        res[i] += p1.coef[i];

    for (size_t i = 0; i < size2; i++)
        res[i] += p2.coef[i];

    return Polynomial(res);
}

ostream& operator << (ostream& st, Complex z)
{
    return st << z.re << "+" << z.im << "i" << endl;

}

istream& operator >> (istream& st, Comlex& z)
{
    st >> z.re >> z.im
        return st;
}

int main()
{

    operator[] 
   
    std::vector<double> v1{ 4, 1, 3, 2 };
    std::vector<double> v2{ 1, 2, 1 };

    Polynomial p1(v1);
    Polynomial p2(v2);

    Polynomial result = sum(p1, p2);

    

    return 0;
}
