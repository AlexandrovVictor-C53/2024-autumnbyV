set terminal pngcairo size 800,600 enhanced font 'Arial,10'
set output 'xg.png'
set title 'xG per Match for Last Two Seasons: Tottenham vs Crystal Palace'
set xlabel 'Match # (last two years)'
set ylabel 'xG'
set grid
plot 'home.dat' using 1:2 with linespoints lt 1 lw 2 pt 7 lc rgb 'blue' title 'Tottenham', \
     'away.dat' using 1:2 with linespoints lt 1 lw 2 pt 5 lc rgb 'red' title 'Crystal Palace'
