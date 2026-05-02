#include <iostream>
#include <string>
#include <regex>
#include <fstream>
#include <cmath>


class Fraction {
private:
    int numerator;
    int denominator;

    int gcd(int a, int b) const 
    {
        a = std::abs(a);
        b = std::abs(b);
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() 
    {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }

        int common_divisor = gcd(numerator, denominator);
        numerator /= common_divisor;
        denominator /= common_divisor;
    }

public:
    Fraction(int num = 0, int den = 1) : numerator(num), denominator(den) 
    {
        reduce();
    }

   

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    Fraction operator+(const Fraction& other) const 
    {
        int new_numerator = numerator * other.denominator + other.numerator * denominator;
        int new_denominator = denominator * other.denominator;
        return Fraction(new_numerator, new_denominator);
    }

    bool operator==(const Fraction& other) const 
    {
        return numerator == other.numerator && denominator == other.denominator;
    }


    double toDouble() const 
    {
        return static_cast<double>(numerator) / denominator;
    }

    void transform(const std::string& input_filename, const std::string& output_filename) {
        std::ifstream input_file(input_filename);
        std::ofstream output_file(output_filename);

        int num1, num2;
        while (input_file >> num1 >> num2) {
            Fraction frac(num1, num2);
            output_file << frac.toDouble() << std::endl;
        }

        input_file.close();
        output_file.close();
    }
};

int main() 
{
    {
        Fraction f1(3, 8);
        Fraction f2("5/4");

        std::cout << "f1 = " << f1 << std::endl;
        std::cout << "f2 = " << f2 << std::endl;

        Fraction sum = f1 + f2;
        std::cout << f1 << " + " << f2 << " = " << sum << std::endl;

        Fraction f4(6, 16);
        std::cout << f1 << " == " << f4 << " ? " << (f1 == f4 ? "true" : "false") << std::endl;

        std::ofstream test_input("test_input.txt");
        test_input << "1 2\n3 4\n5 6\n7 8\n";
        test_input.close();

        Fraction::transform("test_input.txt", "test_output.txt");

    }
   

    return 0;
}