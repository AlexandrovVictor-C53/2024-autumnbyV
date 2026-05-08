# Gnuplot script for impact graphs
set terminal pngcairo size 800,600 enhanced font 'Arial,10'

# height = 1 cm
set output 'plot_H1cm.png'
set multiplot layout 3,1 title 'Impact at H=1 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H1cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H1cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H1cm.txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 2 cm
set output 'plot_H2cm.png'
set multiplot layout 3,1 title 'Impact at H=2 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H2cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H2cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H2cm.txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 3 cm
set output 'plot_H3cm.png'
set multiplot layout 3,1 title 'Impact at H=3 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H3cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H3cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H3cm.txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 4 cm
set output 'plot_H4cm.png'
set multiplot layout 3,1 title 'Impact at H=4 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H4cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H4cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H4cm.txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 5 cm
set output 'plot_H5cm.png'
set multiplot layout 3,1 title 'Impact at H=5 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H5cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H5cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H5cm.txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 6 cm
set output 'plot_H6cm.png'
set multiplot layout 3,1 title 'Impact at H=6 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H6cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H6cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H6cm.txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 7 cm
set output 'plot_H7cm.png'
set multiplot layout 3,1 title 'Impact at H=7 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H7cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H7cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H7cm.txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 8 cm
set output 'plot_H8cm.png'
set multiplot layout 3,1 title 'Impact at H=8 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H8cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H8cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H8cm.txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 9 cm
set output 'plot_H9cm.png'
set multiplot layout 3,1 title 'Impact at H=9 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H9cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H9cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H9cm.txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 10 cm
set output 'plot_H10cm.png'
set multiplot layout 3,1 title 'Impact at H=10 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_H10cm.txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_H10cm.txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_H10cm.txt' using 1:4 with lines title 'Force'
unset multiplot
