//запускать gnuplot через MSYS2 MinGW64
//компил€ци€ g++ Forecast.cpp -o forecast.exe -mconsole

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include <cstdlib>

#define MAX_MATCHES 10000

struct Match 
{
    std::string date, home, away;
    double xg_home, xg_away;
    int goals_home, goals_away;
};

bool safe_stod(const std::string& s, double& r) 
{
    try { r = std::stod(s); return true; }
    catch (...) { return false; }
}
bool safe_stoi(const std::string& s, int& r) 
{
    try { r = std::stoi(s); return true; }
    catch (...) { return false; }
}

int main(int argc, char* argv[]) 
{
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " <csv> <HomeTeam> <AwayTeam>\n";
        return 1;
    }
    std::string path = argv[1], teamH = argv[2], teamA = argv[3];
    std::ifstream in(path);
    if (!in) {
        std::cerr << "Cannot open file: " << path << "\n";
        return 1;
    }

    // Read CSV
    std::string line;
    std::getline(in, line); 
    Match arr[MAX_MATCHES];
    int n = 0;
    while (std::getline(in, line) && n < MAX_MATCHES) 
    {
        std::stringstream ss(line);
        std::string tok;
        Match m;
        for (int i = 0; i < 3; ++i) std::getline(ss, tok, ';');
        std::getline(ss, m.date, ';');
        std::getline(ss, tok, ';'); std::getline(ss, m.home, ';');
        std::getline(ss, tok, ';'); std::getline(ss, tok, ';');
        std::getline(ss, m.away, ';'); std::getline(ss, tok, ';');
        std::getline(ss, tok, ';'); if (!safe_stoi(tok, m.goals_home)) continue;
        std::getline(ss, tok, ';'); if (!safe_stoi(tok, m.goals_away)) continue;
        std::getline(ss, tok, ';'); if (!safe_stod(tok, m.xg_home)) continue;
        std::getline(ss, tok, ';'); if (!safe_stod(tok, m.xg_away)) continue;
        arr[n++] = m;
    }
    in.close();
    std::cout << "Loaded " << n << " matches.\n";

    // Compute season averages
    double seasonH = 0, seasonA = 0;
    int cntH = 0, cntA = 0;
    for (int i = 0; i < n; ++i) 
    {
        if (arr[i].home == teamH) { seasonH += arr[i].xg_home; ++cntH; }
        if (arr[i].away == teamA) { seasonA += arr[i].xg_away; ++cntA; }
    }
    double avgH = cntH ? seasonH / cntH : 0;
    double avgA = cntA ? seasonA / cntA : 0;
    std::cout << "Season avg xG: " << teamH << "=" << avgH
        << ", " << teamA << "=" << avgA << "\n";

    // Write plot data for last two years
    std::ofstream f1("home.dat"), f2("away.dat");
    int idx1 = 0, idx2 = 0;
    int currentYear = std::stoi(arr[n - 1].date.substr(0, 4));
    int cutoff = currentYear - 2;
    for (int i = 0; i < n; ++i) 
    {
        int year = std::stoi(arr[i].date.substr(0, 4));
        if (year < cutoff) continue;
        if (arr[i].home == teamH) f1 << ++idx1 << " " << arr[i].xg_home << "\n";
        if (arr[i].away == teamA) f2 << ++idx2 << " " << arr[i].xg_away << "\n";
    }
    f1.close(); f2.close();

    // Generate gnuplot script
    std::ofstream gp("plot.gp");
    gp << "set terminal pngcairo size 800,600 enhanced font 'Arial,10'\n";
    gp << "set output 'xg.png'\n";
    gp << "set title 'xG per Match for Last Two Seasons: " << teamH
        << " vs " << teamA << "'\n";
    gp << "set xlabel 'Match # (last two years)'\n";
    gp << "set ylabel 'xG'\n";
    gp << "set grid\n";
    gp << "plot 'home.dat' using 1:2 with linespoints lt 1 lw 2 pt 7 lc rgb 'blue' title '"
        << teamH << "', \\" << "\n";
    gp << "     'away.dat' using 1:2 with linespoints lt 1 lw 2 pt 5 lc rgb 'red' title '"
        << teamA << "'\n";
    gp.close();

    // Run gnuplot
    int res = system("gnuplot plot.gp");
    if (res == 0) std::cout << "Saved xg.png\n";
    else std::cerr << "Failed to run gnuplot\n";

    return 0;
}



