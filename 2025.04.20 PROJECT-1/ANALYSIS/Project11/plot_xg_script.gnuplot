set terminal pngcairo size 800,600 enhanced font 'Arial,10'
set output 'xg_season.png'
set title 'Season xG per Match: Tottenham vs Aston Villa'
set xlabel 'Match # (season)'
set ylabel 'xG'
set grid
set yrange [0:*]
plot 'home_season.dat' using 1:2 with linespoints lw 2 lc rgb 'blue' title 'Tottenham', \
     'away_season.dat' using 1:2 with linespoints lw 2 lc rgb 'red' title 'Aston Villa'
