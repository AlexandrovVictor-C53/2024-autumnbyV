set terminal pngcairo size 800,600 enhanced font 'Arial,10'
set output 'e_vs_v0.png'
set xlabel 'v0, m/s'
set ylabel 'e*'
set title 'Coefficient of restitution vs initial velocity'
set grid
plot 'table_results_v2.txt' using 2:6 with linespoints title 'e*'
