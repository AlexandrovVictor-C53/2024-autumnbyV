#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath>
#include <algorithm>

using namespace std;

class Vector 
{

    vector<double> v;

public:
    Vector(const vector<double>& vec = vector<double>()) : v(vec) {}

 
    Vector operator*(double scalar) const 
    {
        Vector result(v);
        for (size_t i = 0; i < result.v.size(); ++i) 
        {

            result.v[i] *= scalar;
        }
        return result;
    }

    double norm() const 
    {
        if (v.empty()) return 0.0;

        double max_val = 0.0;
        for (size_t i = 0; i < v.size(); ++i) 
        {
            double abs_val = abs(v[i]);
            if (abs_val > max_val) {
                max_val = abs_val;
            }
        }
        return max_val;
    }
    
    Vector normalize() const
    {
        double n = norm();

        if (n == 0.0)
        {
            return Vector(v);
        }

  

        Vector result(v);

        for (size_t i = 0; i < result.v.size(); ++i)
        {
            result.v[i] /= n;
        }
    }

    
        std::ostream& operator<<(std::ostream & out, Vector v)
        {
            for (size_t i = 0; i < result.v.size(); ++i)
            {
                out << v[i];
            }
        }



        size_t size() const 
        {
            return v.size();
        }

        double& operator[](size_t index) 
        {
            return v[index];
        }

        const double& operator[](size_t index) const 
        {
            return v[index];
        }
        
    };

    int main()
    {
        vector<double> init_v;
        init_v.push_back(1.0);
        init_v.push_back(2.0);
        init_v.push_back(3.0);

        Vector v1(init_v);
        cout << "v1 = ";
        cout << endl;

        Vector v2 = v1 * 2.0;
        cout << "v1 * 2 = ";
        return EXIT_SUCCESS;
    }