#include <iostream>
#include <vector>
#include <algorithm>

class Polynomial {
public:
    std::vector<double> coef;

    Polynomial(const std::vector<double>& coefficients = {}) : coef(coefficients) {}

    // Перегрузка оператора индексации для доступа к коэффициентам
    double& operator[](size_t index) {
        // Если индекс выходит за границы, расширяем вектор нулями
        if (index >= coef.size()) {
            coef.resize(index + 1, 0.0);
        }
        return coef[index];
    }

    // Константная версия для чтения
    const double& operator[](size_t index) const {
        // Если индекс выходит за границы, возвращаем 0
        static double zero = 0.0;
        if (index >= coef.size()) {
            return zero;
        }
        return coef[index];
    }
};

Polynomial operator+(const Polynomial& p1, const Polynomial& p2) {
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

std::ostream& operator<<(std::ostream& st, const Polynomial& p) {
    for (size_t i = 0; i < p.coef.size(); i++) {
        if (i > 0) st << " + ";
        st << p.coef[i];
        if (i > 0) st << "x^" << i;
    }
    return st;
}

int main() {
    std::vector<double> v1{ 4, 1, 3, 2 };
    std::vector<double> v2{ 1, 2, 1 };

    Polynomial p1(v1);
    Polynomial p2(v2);

    Polynomial result = p1 + p2;

    // Демонстрация использования оператора индексации
    std::cout << "Коэффициенты полинома result:" << std::endl;
    for (size_t i = 0; i < result.coef.size(); i++) {
        std::cout << "result[" << i << "] = " << result[i] << std::endl;
    }

    // Изменение коэффициента через оператор индексации
    result[1] = 5.0;
    result[4] = 7.0; // Добавление нового коэффициента

    std::cout  << std::endl;
    for (size_t i = 0; i < result.coef.size(); i++) {
        std::cout << "result[" << i << "] = " << result[i] << std::endl;
    }

    std::cout << "\nresult: " << result << std::endl;

    return 0;
}