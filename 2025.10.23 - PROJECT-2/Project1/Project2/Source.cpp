#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0);
const double g = 9.81;

void derivatives(double tau, double Ksi, double Eta, double F, double f,
    double& dKsi_dTau, double& dEta_dTau, double& dF_dTau, double& df_dTau,
    double alpha, double beta, double rho) {
    dKsi_dTau = Eta;
    dEta_dTau = -alpha * F;
    dF_dTau = Eta * exp(beta * Ksi) - F + rho * f;
    df_dTau = Eta * exp(beta * Ksi);
}

void rungeKuttaStep(double tau, double& Ksi, double& Eta, double& F, double& f,
    double h, double alpha, double beta, double rho) {
    double k1_Ksi, k1_Eta, k1_F, k1_f;
    double k2_Ksi, k2_Eta, k2_F, k2_f;
    double k3_Ksi, k3_Eta, k3_F, k3_f;
    double k4_Ksi, k4_Eta, k4_F, k4_f;

    derivatives(tau, Ksi, Eta, F, f, k1_Ksi, k1_Eta, k1_F, k1_f, alpha, beta, rho);

    double temp_Ksi = Ksi + 0.5 * h * k1_Ksi;
    double temp_Eta = Eta + 0.5 * h * k1_Eta;
    double temp_F = F + 0.5 * h * k1_F;
    double temp_f = f + 0.5 * h * k1_f;
    derivatives(tau + 0.5 * h, temp_Ksi, temp_Eta, temp_F, temp_f,
        k2_Ksi, k2_Eta, k2_F, k2_f, alpha, beta, rho);

    temp_Ksi = Ksi + 0.5 * h * k2_Ksi;
    temp_Eta = Eta + 0.5 * h * k2_Eta;
    temp_F = F + 0.5 * h * k2_F;
    temp_f = f + 0.5 * h * k2_f;
    derivatives(tau + 0.5 * h, temp_Ksi, temp_Eta, temp_F, temp_f,
        k3_Ksi, k3_Eta, k3_F, k3_f, alpha, beta, rho);

    temp_Ksi = Ksi + h * k3_Ksi;
    temp_Eta = Eta + h * k3_Eta;
    temp_F = F + h * k3_F;
    temp_f = f + h * k3_f;
    derivatives(tau + h, temp_Ksi, temp_Eta, temp_F, temp_f,
        k4_Ksi, k4_Eta, k4_F, k4_f, alpha, beta, rho);

    Ksi += (h / 6.0) * (k1_Ksi + 2.0 * k2_Ksi + 2.0 * k3_Ksi + k4_Ksi);
    Eta += (h / 6.0) * (k1_Eta + 2.0 * k2_Eta + 2.0 * k3_Eta + k4_Eta);
    F += (h / 6.0) * (k1_F + 2.0 * k2_F + 2.0 * k3_F + k4_F);
    f += (h / 6.0) * (k1_f + 2.0 * k2_f + 2.0 * k3_f + k4_f);
}

int main() {
    double m = 0.1;
    double d = 0.005;
    double h0 = 0.0023;
    double A = PI * (d / 2.0) * (d / 2.0);
    double E0 = 5.6e6;
    double rho = 0.3;
    double E_inf = rho * E0;
    double tau_R = 3.0e-4;
    double B = 6.2;
    double alpha = (A * E0 * tau_R * tau_R) / (m * h0);

    const int numH = 10;
    double H_values[numH];
    double v0_values[numH];
    double beta_values[numH];
    double e_values[numH];
    double tau_c_values[numH];

    for (int i = 0; i < numH; ++i) {
        H_values[i] = 0.01 * (i + 1);
        v0_values[i] = sqrt(2.0 * g * H_values[i]);
        beta_values[i] = (B * v0_values[i] * tau_R) / h0;
    }

    double h_step = 0.001;
    double tau_end = 50.0;
    int plot_index = 4; // 5 см

    cout << fixed << setprecision(4);
    cout << "\nТаблица результатов:\n";
    cout << "H(см)\tv0(м/с)\tbeta\ttau_c\te*\n";
    cout << "------------------------------------------\n";

    for (int idx = 0; idx < numH; ++idx) {
        double v0 = v0_values[idx];
        double beta = beta_values[idx];
        double Ksi = 0.0, Eta = 1.0, F = 0.0, f = 0.0, tau = 0.0;
        bool contact_ended = false;
        double tau_c = 0.0, e_star = 0.0;

        vector<double> t_plot, x_plot, v_plot;
        if (idx == plot_index) {
            t_plot.reserve(50000);
            x_plot.reserve(50000);
            v_plot.reserve(50000);
        }

        while (tau <= tau_end && !contact_ended) {
            if (idx == plot_index) {
                t_plot.push_back(tau * tau_R);
                x_plot.push_back(Ksi * v0 * tau_R);
                v_plot.push_back(Eta * v0);
            }
            if (F <= 0.0 && tau > 0.001) {
                contact_ended = true;
                tau_c = tau;
                e_star = -Eta;
                break;
            }
            rungeKuttaStep(tau, Ksi, Eta, F, f, h_step, alpha, beta, rho);
            tau += h_step;
        }

        if (!contact_ended) {
            tau_c = tau;
            e_star = -Eta;
        }
        e_values[idx] = e_star;
        tau_c_values[idx] = tau_c;

        cout << H_values[idx] * 100 << "\t" << v0 << "\t" << beta
            << "\t" << tau_c << "\t" << e_star << "\n";

        if (idx == plot_index) {
            string fname = "trajectory_H" + to_string((int)(H_values[idx] * 100)) + "cm.txt";
            ofstream traj(fname);
            traj << "t(s)\tx(m)\tv(m/s)\n";
            for (size_t i = 0; i < t_plot.size(); ++i)
                traj << t_plot[i] << "\t" << x_plot[i] << "\t" << v_plot[i] << "\n";
            traj.close();
        }
    }

    ofstream tab("table_results.txt");
    tab << "H(cm)\tv0(m/s)\tbeta\ttau_c\te*\n";
    for (int i = 0; i < numH; ++i)
        tab << H_values[i] * 100 << "\t" << v0_values[i] << "\t"
        << beta_values[i] << "\t" << tau_c_values[i] << "\t" << e_values[i] << "\n";
    tab.close();

    cout << "\nТаблица сохранена в table_results.txt\n";
    cout << "Траектория для H=5 см сохранена в trajectory_H5cm.txt\n";
    cout << "Команды для графиков:\n";
    cout << "gnuplot -p -e \"plot 'trajectory_H5cm.txt' using 1:2 with lines title 'x(t)'\"\n";
    cout << "gnuplot -p -e \"plot 'trajectory_H5cm.txt' using 1:3 with lines title 'v(t)'\"\n";

    return 0;
}