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
    double temp_F   = F   + 0.5 * h * k1_F;
    double temp_f   = f   + 0.5 * h * k1_f;
    derivatives(tau + 0.5 * h, temp_Ksi, temp_Eta, temp_F, temp_f,
                k2_Ksi, k2_Eta, k2_F, k2_f, alpha, beta, rho);

    temp_Ksi = Ksi + 0.5 * h * k2_Ksi;
    temp_Eta = Eta + 0.5 * h * k2_Eta;
    temp_F   = F   + 0.5 * h * k2_F;
    temp_f   = f   + 0.5 * h * k2_f;
    derivatives(tau + 0.5 * h, temp_Ksi, temp_Eta, temp_F, temp_f,
                k3_Ksi, k3_Eta, k3_F, k3_f, alpha, beta, rho);

    temp_Ksi = Ksi + h * k3_Ksi;
    temp_Eta = Eta + h * k3_Eta;
    temp_F   = F   + h * k3_F;
    temp_f   = f   + h * k3_f;
    derivatives(tau + h, temp_Ksi, temp_Eta, temp_F, temp_f,
                k4_Ksi, k4_Eta, k4_F, k4_f, alpha, beta, rho);

    Ksi += (h / 6.0) * (k1_Ksi + 2.0 * k2_Ksi + 2.0 * k3_Ksi + k4_Ksi);
    Eta += (h / 6.0) * (k1_Eta + 2.0 * k2_Eta + 2.0 * k3_Eta + k4_Eta);
    F   += (h / 6.0) * (k1_F   + 2.0 * k2_F   + 2.0 * k3_F   + k4_F);
    f   += (h / 6.0) * (k1_f   + 2.0 * k2_f   + 2.0 * k3_f   + k4_f);
}

int main() {
    // Физические параметры
    double m = 0.1;
    double d = 0.005;
    double h0 = 0.0023;
    double A = PI * (d/2.0)*(d/2.0);
    double E0 = 5.6e6;
    double rho = 0.3;
    double tau_R = 3.0e-4;
    double B = 6.2;
    double alpha = (A * E0 * tau_R * tau_R) / (m * h0);

    // Новый список высот (см)
    double H_cm_list[] = {0.25, 0.5, 0.75, 10.0, 11.0, 12.0, 13.0, 14.0,
                          15.0, 16.0, 17.0, 18.0, 19.0, 20.0};
    const int numH = sizeof(H_cm_list) / sizeof(H_cm_list[0]);

    double H_values[numH], v0_values[numH], beta_values[numH];
    double e_values[numH], tau_c_values[numH];
    double Ek0_values[numH], dE_rel_values[numH];

    for (int i = 0; i < numH; ++i) {
        H_values[i] = H_cm_list[i] / 100.0;   // метры
        v0_values[i] = sqrt(2.0 * g * H_values[i]);
        beta_values[i] = (B * v0_values[i] * tau_R) / h0;
        Ek0_values[i] = 0.5 * m * v0_values[i] * v0_values[i];
    }

    double h_step = 0.001;
    double tau_end = 50.0;

    cout << fixed << setprecision(4);
    cout << "\n--- Таблица результатов (расширенный диапазон) ---\n";
    cout << "H(см)\tv0(м/с)\tbeta\tE_k0(Дж)\ttau_c\te*\tdE_k/E_k0\n";
    cout << "-----------------------------------------------------------\n";

    for (int idx = 0; idx < numH; ++idx) {
        double v0 = v0_values[idx];
        double beta = beta_values[idx];
        double Ksi = 0.0, Eta = 1.0, F = 0.0, f = 0.0, tau = 0.0;
        bool contact_ended = false;
        double tau_c = 0.0, e_star = 0.0;

        vector<double> t_plot, x_plot, v_plot, F_plot;
        t_plot.reserve(50000); x_plot.reserve(50000);
        v_plot.reserve(50000); F_plot.reserve(50000);

        while (tau <= tau_end && !contact_ended) {
            double t_dim = tau * tau_R;
            double x_dim = Ksi * v0 * tau_R;
            double v_dim = Eta * v0;
            double F_dim = (A * E0 / h0) * F;

            t_plot.push_back(t_dim);
            x_plot.push_back(x_dim);
            v_plot.push_back(v_dim);
            F_plot.push_back(F_dim);

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
        double dE_rel = 1.0 - e_star * e_star;
        dE_rel_values[idx] = dE_rel;

        cout << H_cm_list[idx] << "\t" << v0 << "\t" << beta << "\t"
             << Ek0_values[idx] << "\t" << tau_c << "\t" << e_star << "\t"
             << dE_rel << "\n";

        // формируем имя файла траектории
        ostringstream namestr;
        namestr << "trajectory_v2_H" << fixed << setprecision(2) << H_cm_list[idx] << "cm.txt";
        string fname = namestr.str();
        for (char& c : fname) if (c == '.') c = '_';   // заменяем точку на подчеркивание
        ofstream traj(fname);
        traj << "t(s)\tx(m)\tv(m/s)\tF(N)\n";
        for (size_t i = 0; i < t_plot.size(); ++i)
            traj << t_plot[i] << "\t" << x_plot[i] << "\t" << v_plot[i] << "\t" << F_plot[i] << "\n";
        traj.close();
    }

    // Сохраняем таблицу
    ofstream tab("table_results_v2.txt");
    tab << "H(cm)\tv0(m/s)\tbeta\tE_k0(J)\ttau_c\te*\tdE_k/E_k0\n";
    for (int i = 0; i < numH; ++i)
        tab << H_cm_list[i] << "\t" << v0_values[i] << "\t"
            << beta_values[i] << "\t" << Ek0_values[i] << "\t"
            << tau_c_values[i] << "\t" << e_values[i] << "\t"
            << dE_rel_values[i] << "\n";
    tab.close();

    // Генерация скрипта для gnuplot
    ofstream script("plot_all_v2.gnu");
    script << "set terminal pngcairo size 800,600 enhanced font 'Arial,10'\n";
    for (int i = 0; i < numH; ++i) {
        ostringstream datname;
        datname << "trajectory_v2_H" << fixed << setprecision(2) << H_cm_list[i] << "cm.txt";
        string datfile = datname.str();
        for (char& c : datfile) if (c == '.') c = '_';

        ostringstream outname;
        outname << "plot_v2_H" << fixed << setprecision(2) << H_cm_list[i] << "cm.png";
        string outfile = outname.str();
        for (char& c : outfile) if (c == '.') c = '_';

        script << "\n# height = " << H_cm_list[i] << " cm\n";
        script << "set output '" << outfile << "'\n";
        script << "set multiplot layout 3,1 title 'Impact at H=" << H_cm_list[i] << " cm'\n";
        script << "set xlabel 't, s'\n";
        script << "set ylabel 'x, m'\n";
        script << "plot '" << datfile << "' using 1:2 with lines title 'Displacement'\n";
        script << "set ylabel 'v, m/s'\n";
        script << "plot '" << datfile << "' using 1:3 with lines title 'Velocity'\n";
        script << "set ylabel 'F, N'\n";
        script << "plot '" << datfile << "' using 1:4 with lines title 'Force'\n";
        script << "unset multiplot\n";
    }
    script.close();

    cout << "\nТраектории сохранены в файлы trajectory_v2_H*cm.txt\n";
    cout << "Таблица -- table_results_v2.txt\n";
    cout << "Для построения графиков выполните: gnuplot plot_all_v2.gnu\n";

    return 0;
}
