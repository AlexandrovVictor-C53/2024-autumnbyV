#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

const double PI = acos(-1.0);
const double g = 9.81;

// Система безразмерных ОДУ
void derivatives(double tau, double Ksi, double Eta, double F, double f,
                 double& dKsi_dTau, double& dEta_dTau, double& dF_dTau, double& df_dTau,
                 double alpha, double beta, double rho) {
    dKsi_dTau = Eta;
    dEta_dTau = -alpha * F;
    dF_dTau = Eta * exp(beta * Ksi) - F + rho * f;
    df_dTau = Eta * exp(beta * Ksi);
}

// Один шаг Рунге–Кутты 4-го порядка
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
    // ---------- Физические параметры (все в СИ) ----------
    double m = 0.1;                // масса ударника, кг
    double d = 0.005;              // диаметр образца, м
    double h0 = 0.0023;            // толщина образца, м
    double A = PI * (d/2.0)*(d/2.0); // площадь контакта, м²
    double E0 = 5.6e6;             // мгновенный модуль, Па
    double rho = 0.3;              // отношение E∞/E0
    double tau_R = 3.0e-4;         // время релаксации, с
    double B = 6.2;                // параметр нелинейности
    double alpha = (A * E0 * tau_R * tau_R) / (m * h0);

    // ---------- Список высот (в сантиметрах) ----------
    double H_cm_list[] = {0.25, 0.5, 0.75, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0,
                          10.0, 11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0};
    const int numH = sizeof(H_cm_list) / sizeof(H_cm_list[0]);

    double H_values[numH], v0_values[numH], beta_values[numH];
    double e_values[numH], tau_c_values[numH];
    double Ek0_values[numH], dE_rel_values[numH];
    double Wdiss_values[numH];     // диссипированная энергия (Дж)

    // Предварительный расчёт для всех высот
    for (int i = 0; i < numH; ++i) {
        H_values[i] = H_cm_list[i] / 100.0;       // перевод в метры
        v0_values[i] = sqrt(2.0 * g * H_values[i]);
        beta_values[i] = (B * v0_values[i] * tau_R) / h0;
        Ek0_values[i] = 0.5 * m * v0_values[i] * v0_values[i];
    }

    double h_step = 0.001;          // шаг безразмерного времени
    double tau_end = 50.0;          // большой запас по времени

    cout << fixed << setprecision(4);
    cout << "\n--- Таблица результатов ---\n";
    cout << "H(см)\tv0(м/с)\tbeta\tE_k0(Дж)\ttau_c\te*\tdE_k/E_k0\tW_diss(Дж)\n";
    cout << "--------------------------------------------------------------------\n";

    // ---------- Основной цикл по высотам ----------
    for (int idx = 0; idx < numH; ++idx) {
        double v0 = v0_values[idx];
        double beta = beta_values[idx];
        double Ksi = 0.0, Eta = 1.0, F = 0.0, f = 0.0, tau = 0.0;
        bool contact_ended = false;
        double tau_c = 0.0, e_star = 0.0;

        // Векторы для сохранения траектории и напряжения/деформации
        vector<double> t_plot, x_plot, v_plot, F_plot;
        vector<double> sigma_plot, epsilon_plot;   // <-- для удобства
        t_plot.reserve(50000); x_plot.reserve(50000);
        v_plot.reserve(50000); F_plot.reserve(50000);
        sigma_plot.reserve(50000); epsilon_plot.reserve(50000);

        // Интегрируем до окончания контакта (F <= 0)
        while (tau <= tau_end && !contact_ended) {
            double t_dim = tau * tau_R;
            double x_dim = Ksi * v0 * tau_R;
            double v_dim = Eta * v0;
            double F_dim = (A * E0 / h0) * F;    // размерная сила (Н)

            // Сохраняем в векторы
            t_plot.push_back(t_dim);
            x_plot.push_back(x_dim);
            v_plot.push_back(v_dim);
            F_plot.push_back(F_dim);

            // Вычисляем напряжение и деформацию и сохраняем
            double sigma = F_dim / A;            // Па
            double eps   = x_dim / h0;           // безразмерная деформация
            sigma_plot.push_back(sigma);
            epsilon_plot.push_back(eps);

            // Проверка окончания контакта
            if (F <= 0.0 && tau > 0.001) {
                contact_ended = true;
                tau_c = tau;
                e_star = -Eta;                   // e* = -ε(τ_c)
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

        // ---------- Площадь петли гистерезиса (через σ и ε) ----------
        double loop_area_density = 0.0;   // площадь петли в координатах σ–ε (Дж/м³)
        for (size_t i = 0; i < sigma_plot.size() - 1; ++i) {
            double d_eps = epsilon_plot[i+1] - epsilon_plot[i];    // высота трапеции
            double avg_sigma = 0.5 * (sigma_plot[i] + sigma_plot[i+1]); // полусумма оснований
            loop_area_density += avg_sigma * d_eps;
        }
        // Диссипированная энергия = площадь петли (σ-ε) * объём образца
        double work = loop_area_density * A * h0;   // Дж
        Wdiss_values[idx] = work;

        // Вывод строки таблицы
        cout << H_cm_list[idx] << "\t" << v0 << "\t" << beta << "\t"
             << Ek0_values[idx] << "\t" << tau_c << "\t" << e_star << "\t"
             << dE_rel << "\t" << work << "\n";

        // ---------- Сохранение траектории в файл ----------
        ostringstream namestr;
        namestr << "trajectory_v2_H" << fixed << setprecision(2) << H_cm_list[idx] << "cm.txt";
        string fname = namestr.str();
        // Заменяем точку на подчёркивание, чтобы избежать проблем с именами
        for (char& c : fname) if (c == '.') c = '_';

        ofstream traj(fname);
        traj << "t(s)\tx(m)\tv(m/s)\tF(N)\tsigma(Pa)\tepsilon\n";
        for (size_t i = 0; i < t_plot.size(); ++i) {
            traj << t_plot[i] << "\t" << x_plot[i] << "\t" << v_plot[i] << "\t"
                 << F_plot[i] << "\t" << sigma_plot[i] << "\t" << epsilon_plot[i] << "\n";
        }
        traj.close();
    }

    // ---------- Сохранение общей таблицы ----------
    ofstream tab("table_results_v2.txt");
    tab << "H(cm)\tv0(m/s)\tbeta\tE_k0(J)\ttau_c\te*\tdE_k/E_k0\tW_diss(J)\n";
    for (int i = 0; i < numH; ++i)
        tab << H_cm_list[i] << "\t" << v0_values[i] << "\t"
            << beta_values[i] << "\t" << Ek0_values[i] << "\t"
            << tau_c_values[i] << "\t" << e_values[i] << "\t"
            << dE_rel_values[i] << "\t" << Wdiss_values[i] << "\n";
    tab.close();

    // ---------- Генерация gnuplot-скрипта для графиков σ(ε) ----------
    ofstream s_script("plot_stress_strain.gnu");
    s_script << "set terminal pngcairo size 800,600 enhanced font 'Arial,10'\n";
    for (int i = 0; i < numH; ++i) {
        ostringstream datname;
        datname << "trajectory_v2_H" << fixed << setprecision(2) << H_cm_list[i] << "cm.txt";
        string datfile = datname.str();
        for (char& c : datfile) if (c == '.') c = '_';

        ostringstream outname;
        outname << "stress_strain_H" << fixed << setprecision(2) << H_cm_list[i] << "cm.png";
        string outfile = outname.str();
        for (char& c : outfile) if (c == '.') c = '_';

        s_script << "\nset output '" << outfile << "'\n";
        s_script << "set xlabel 'Strain, x/h0'\n";
        s_script << "set ylabel 'Stress, Pa'\n";
        s_script << "set title 'Stress-Strain at H=" << H_cm_list[i] << " cm'\n";
        s_script << "set grid\n";
        s_script << "plot '" << datfile << "' using 6:5 with lines title 'loop'\n";
    }
    s_script.close();

    // ---------- Генерация скрипта для e* от v0 ----------
    ofstream e_script("plot_e_vs_v0.gnu");
    e_script << "set terminal pngcairo size 800,600 enhanced font 'Arial,10'\n";
    e_script << "set output 'e_vs_v0.png'\n";
    e_script << "set xlabel 'v0, m/s'\n";
    e_script << "set ylabel 'e*'\n";
    e_script << "set title 'Coefficient of restitution vs initial velocity'\n";
    e_script << "set grid\n";
    e_script << "plot 'table_results_v2.txt' using 2:6 with linespoints title 'e*'\n";
    e_script.close();

    cout << "\nТраектории и таблица сохранены.\n";
    cout << "Для графиков σ-ε выполните: gnuplot -c plot_stress_strain.gnu\n";
    cout << "Для графика e*(v0) выполните: gnuplot -c plot_e_vs_v0.gnu\n";

    return 0;
}
