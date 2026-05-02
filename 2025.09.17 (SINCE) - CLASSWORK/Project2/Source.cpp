#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;
class Vector {
private:
    vector<double> v;

public:
    // 1) Конструктор с параметром типа vector
    Vector(const vector<double>& vec = {}) : v(vec) {}

    // 2) Умножение вектора на скаляр
    Vector operator*(double scalar) const {
        Vector result(*this);
        for (auto& element : result.v) {
            element *= scalar;
        }
        return result;
    }

    // Дружественная функция для умножения скаляра на вектор
    friend Vector operator*(double scalar, const Vector& vec) {
        return vec * scalar;
    }

    // 3) Вычисление нормы (Тельдера) вектора
    double norm() const {
        if (v.empty()) return 0.0;

        double max_val = 0.0;
        for (const auto& element : v) {
            double abs_val = abs(element);
            if (abs_val > max_val) {
                max_val = abs_val;
            }
        }
        return max_val;
    }

    // 4) Операция нормирования вектора
    Vector normalize() const {
        double n = norm();
        if (n == 0.0) {
            return Vector(v); // возвращаем копию, если норма 0
        }

        Vector result(*this);
        for (auto& element : result.v) {
            element /= n;
        }
        return result;
    }

    // 5) Метод linear_comb для вычисления линейной комбинации
    void linear_comb(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Ошибка открытия файла: " << filename << endl;
            return;
        }

        // Очищаем текущий вектор
        v.clear();

        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            double coefficient;
            vector<double> vector_v;

            // Читаем коэффициент
            if (!(iss >> coefficient)) {
                continue; // пропускаем некорректные строки
            }

            // Читаем элементы вектора
            double value;
            while (iss >> value) {
                vector_v.push_back(value);
            }

            // Если это первое слагаемое, инициализируем результат
            if (v.empty()) {
                v.resize(vector_v.size(), 0.0);
            }

            // Добавляем линейную комбинацию
            if (vector_v.size() == v.size()) {
                for (size_t i = 0; i < v.size(); ++i) {
                    v[i] += coefficient * vector_v[i];
                }
            }
        }

        file.close();
    }

    // 6) Ввод вектора из потока
    friend istream& operator>>(istream& is, Vector& vec) {
        vec.v.clear();

        string line;
        getline(is, line);

        istringstream iss(line);
        double value;
        while (iss >> value) {
            vec.v.push_back(value);
        }

        return is;
    }

    // Вывод вектора в поток (для тестирования)
    friend ostream& operator<<(ostream& os, const Vector& vec) {
        os << "[";
        for (size_t i = 0; i < vec.v.size(); ++i) {
            os << vec.v[i];
            if (i < vec.v.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
        return os;
    }

    // Получение размера вектора
    size_t size() const {
        return v.size();
    }

    // Доступ к элементам
    double& operator[](size_t index) {
        return v[index];
    }

    const double& operator[](size_t index) const {
        return v[index];
    }
};
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

class Vector {
private:
    std::vector<double> data;

public:
    // 1) Конструктор с параметром типа vector
    Vector(const std::vector<double>& vec = std::vector<double>()) : data(vec) {}

    // 2) Умножение вектора на скаляр
    Vector operator*(double scalar) const {
        Vector result(data);
        for (size_t i = 0; i < result.data.size(); ++i) {
            result.data[i] *= scalar;
        }
        return result;
    }

    // 3) Вычисление нормы (Тельдера) вектора
    double norm() const {
        if (data.empty()) return 0.0;

        double max_val = 0.0;
        for (size_t i = 0; i < data.size(); ++i) {
            double abs_val = std::abs(data[i]);
            if (abs_val > max_val) {
                max_val = abs_val;
            }
        }
        return max_val;
    }

    // 4) Операция нормирования вектора
    Vector normalize() const {
        double n = norm();
        if (n == 0.0) {
            return Vector(data);
        }

        Vector result(data);
        for (size_t i = 0; i < result.data.size(); ++i) {
            result.data[i] /= n;
        }
        return result;
    }

    // 5) Метод linear_comb для вычисления линейной комбинации
    void linear_comb(const std::string& filename) {
        std::ifstream file(filename.c_str());
        if (!file.is_open()) {
            std::cerr << "Ошибка открытия файла: " << filename << std::endl;
            return;
        }

        data.clear();

        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            double coefficient;
            std::vector<double> vector_data;

            if (!(iss >> coefficient)) {
                continue;
            }

            double value;
            while (iss >> value) {
                vector_data.push_back(value);
            }

            if (data.empty()) {
                data.resize(vector_data.size(), 0.0);
            }

            if (vector_data.size() == data.size()) {
                for (size_t i = 0; i < data.size(); ++i) {
                    data[i] += coefficient * vector_data[i];
                }
            }
        }

        file.close();
    }

    // 6) Ввод вектора из потока
    void input(std::istream& is) {
        data.clear();

        std::string line;
        std::getline(is, line);

        std::istringstream iss(line);
        double value;
        while (iss >> value) {
            data.push_back(value);
        }
    }

    // Вывод вектора в поток
    void output(std::ostream& os) const {
        os << "[";
        for (size_t i = 0; i < data.size(); ++i) {
            os << data[i];
            if (i < data.size() - 1) {
                os << ", ";
            }
        }
        os << "]";
    }

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

    class Vector {
    private:
        std::vector<double> data;

    public:
        // 1) Конструктор с параметром типа vector
        Vector(const std::vector<double>& vec = std::vector<double>()) : data(vec) {}

        // 2) Умножение вектора на скаляр
        Vector operator*(double scalar) const {
            Vector result(data);
            for (size_t i = 0; i < result.data.size(); ++i) {
                result.data[i] *= scalar;
            }
            return result;
        }

        // 3) Вычисление нормы (Тельдера) вектора
        double norm() const {
            if (data.empty()) return 0.0;

            double max_val = 0.0;
            for (size_t i = 0; i < data.size(); ++i) {
                double abs_val = std::abs(data[i]);
                if (abs_val > max_val) {
                    max_val = abs_val;
                }
            }
            return max_val;
        }

        // 4) Операция нормирования вектора
        Vector normalize() const {
            double n = norm();
            if (n == 0.0) {
                return Vector(data);
            }

            Vector result(data);
            for (size_t i = 0; i < result.data.size(); ++i) {
                result.data[i] /= n;
            }
            return result;
        }

        // 5) Метод linear_comb для вычисления линейной комбинации
        void linear_comb(const std::string& filename) {
            std::ifstream file(filename.c_str());
            if (!file.is_open()) {
                std::cerr << "Ошибка открытия файла: " << filename << std::endl;
                return;
            }

            data.clear();

            std::string line;
            while (std::getline(file, line)) {
                std::istringstream iss(line);
                double coefficient;
                std::vector<double> vector_data;

                if (!(iss >> coefficient)) {
                    continue;
                }

                double value;
                while (iss >> value) {
                    vector_data.push_back(value);
                }

                if (data.empty()) {
                    data.resize(vector_data.size(), 0.0);
                }

                if (vector_data.size() == data.size()) {
                    for (size_t i = 0; i < data.size(); ++i) {
                        data[i] += coefficient * vector_data[i];
                    }
                }
            }

            file.close();
        }

        // 6) Ввод вектора из потока
        void input(std::istream& is) {
            data.clear();

            std::string line;
            std::getline(is, line);

            std::istringstream iss(line);
            double value;
            while (iss >> value) {
                data.push_back(value);
            }
        }

        // Вывод вектора в поток
        void output(std::ostream& os) const {
            os << "[";
            for (size_t i = 0; i < data.size(); ++i) {
                os << data[i];
                if (i < data.size() - 1) {
                    os << ", ";
                }
            }
            os << "]";
        }

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

        class Vector {
        private:
            std::vector<double> data;

        public:
            // 1) Конструктор с параметром типа vector
            Vector(const std::vector<double>& vec = std::vector<double>()) : data(vec) {}

            // 2) Умножение вектора на скаляр
            Vector operator*(double scalar) const {
                Vector result(data);
                for (size_t i = 0; i < result.data.size(); ++i) {
                    result.data[i] *= scalar;
                }
                return result;
            }

            // 3) Вычисление нормы (Тельдера) вектора
            double norm() const {
                if (data.empty()) return 0.0;

                double max_val = 0.0;
                for (size_t i = 0; i < data.size(); ++i) {
                    double abs_val = std::abs(data[i]);
                    if (abs_val > max_val) {
                        max_val = abs_val;
                    }
                }
                return max_val;
            }

            // 4) Операция нормирования вектора
            Vector normalize() const {
                double n = norm();
                if (n == 0.0) {
                    return Vector(data);
                }

                Vector result(data);
                for (size_t i = 0; i < result.data.size(); ++i) {
                    result.data[i] /= n;
                }
                return result;
            }

            // 5) Метод linear_comb для вычисления линейной комбинации
            void linear_comb(const std::string& filename) {
                std::ifstream file(filename.c_str());
                if (!file.is_open()) {
                    std::cerr << "Ошибка открытия файла: " << filename << std::endl;
                    return;
                }

                data.clear();

                std::string line;
                while (std::getline(file, line)) {
                    std::istringstream iss(line);
                    double coefficient;
                    std::vector<double> vector_data;

                    if (!(iss >> coefficient)) {
                        continue;
                    }

                    double value;
                    while (iss >> value) {
                        vector_data.push_back(value);
                    }

                    if (data.empty()) {
                        data.resize(vector_data.size(), 0.0);
                    }

                    if (vector_data.size() == data.size()) {
                        for (size_t i = 0; i < data.size(); ++i) {
                            data[i] += coefficient * vector_data[i];
                        }
                    }
                }

                file.close();
            }

            // 6) Ввод вектора из потока
            void input(std::istream& is) {
                data.clear();

                std::string line;
                std::getline(is, line);

                std::istringstream iss(line);
                double value;
                while (iss >> value) {
                    data.push_back(value);
                }
            }

            // Вывод вектора в поток
            void output(std::ostream& os) const {
                os << "[";
                for (size_t i = 0; i < data.size(); ++i) {
                    os << data[i];
                    if (i < data.size() - 1) {
                        os << ", ";
                    }
                }
                os << "]";
            }

            // Получение размера вектора
            size_t size() const {
                return data.size();
            }

            // Доступ к элементам
            double& operator[](size_t index) {
                return data[index];
            }

            const double& operator[](size_t index) const {
                return data[index];
            }
        };

        // Внешние функции для операций с векторами
        Vector multiplyScalarVector(double scalar, const Vector& vec) {
            return vec * scalar;
        }

        // Пример использования
        int main() {
            std::vector<double> init_data;
            init_data.push_back(1.0);
            init_data.push_back(2.0);
            init_data.push_back(3.0);

            Vector v1(init_data);
            std::cout << "v1 = ";
            v1.output(std::cout);
            std::cout << std::endl;

            Vector v2 = v1 * 2.0;
            std::cout << "v1 * 2 = ";
        // Получение размера вектора
        size_t size() const {
            return data.size();
        }

        // Доступ к элементам
        double& operator[](size_t index) {
            return data[index];
        }

        const double& operator[](size_t index) const {
            return data[index];
        }
    };

    // Внешние функции для операций с векторами
    Vector multiplyScalarVector(double scalar, const Vector& vec) {
        return vec * scalar;
    }

    // Пример использования
    int main() {
        std::vector<double> init_data;
        init_data.push_back(1.0);
        init_data.push_back(2.0);
        init_data.push_back(3.0);

        Vector v1(init_data);
        std::cout << "v1 = ";
        v1.output(std::cout);
        std::cout << std::endl;

        Vector v2 = v1 * 2.0;
        std::cout << "v1 * 2 = ";