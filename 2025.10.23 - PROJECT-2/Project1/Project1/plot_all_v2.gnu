set terminal pngcairo size 800,600 enhanced font 'Arial,10'

# height = 0.25 cm
set output 'plot_v2_H0_25cm_png'
set multiplot layout 3,1 title 'Impact at H=0.25 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H0_25cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H0_25cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H0_25cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 0.33 cm
set output 'plot_v2_H0_33cm_png'
set multiplot layout 3,1 title 'Impact at H=0.33 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H0_33cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H0_33cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H0_33cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 0.5 cm
set output 'plot_v2_H0_50cm_png'
set multiplot layout 3,1 title 'Impact at H=0.5 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H0_50cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H0_50cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H0_50cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 0.66 cm
set output 'plot_v2_H0_66cm_png'
set multiplot layout 3,1 title 'Impact at H=0.66 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H0_66cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H0_66cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H0_66cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 0.75 cm
set output 'plot_v2_H0_75cm_png'
set multiplot layout 3,1 title 'Impact at H=0.75 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H0_75cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H0_75cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H0_75cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 1 cm
set output 'plot_v2_H1_00cm_png'
set multiplot layout 3,1 title 'Impact at H=1 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H1_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H1_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H1_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 2 cm
set output 'plot_v2_H2_00cm_png'
set multiplot layout 3,1 title 'Impact at H=2 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H2_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H2_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H2_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 3 cm
set output 'plot_v2_H3_00cm_png'
set multiplot layout 3,1 title 'Impact at H=3 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H3_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H3_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H3_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 4 cm
set output 'plot_v2_H4_00cm_png'
set multiplot layout 3,1 title 'Impact at H=4 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H4_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H4_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H4_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 5 cm
set output 'plot_v2_H5_00cm_png'
set multiplot layout 3,1 title 'Impact at H=5 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H5_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H5_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H5_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 6 cm
set output 'plot_v2_H6_00cm_png'
set multiplot layout 3,1 title 'Impact at H=6 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H6_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H6_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H6_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 7 cm
set output 'plot_v2_H7_00cm_png'
set multiplot layout 3,1 title 'Impact at H=7 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H7_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H7_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H7_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 8 cm
set output 'plot_v2_H8_00cm_png'
set multiplot layout 3,1 title 'Impact at H=8 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H8_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H8_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H8_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 9 cm
set output 'plot_v2_H9_00cm_png'
set multiplot layout 3,1 title 'Impact at H=9 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H9_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H9_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H9_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 10 cm
set output 'plot_v2_H10_00cm_png'
set multiplot layout 3,1 title 'Impact at H=10 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H10_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H10_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H10_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 11 cm
set output 'plot_v2_H11_00cm_png'
set multiplot layout 3,1 title 'Impact at H=11 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H11_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H11_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H11_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 12 cm
set output 'plot_v2_H12_00cm_png'
set multiplot layout 3,1 title 'Impact at H=12 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H12_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H12_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H12_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 13 cm
set output 'plot_v2_H13_00cm_png'
set multiplot layout 3,1 title 'Impact at H=13 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H13_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H13_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H13_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 14 cm
set output 'plot_v2_H14_00cm_png'
set multiplot layout 3,1 title 'Impact at H=14 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H14_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H14_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H14_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 15 cm
set output 'plot_v2_H15_00cm_png'
set multiplot layout 3,1 title 'Impact at H=15 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H15_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H15_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H15_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 16 cm
set output 'plot_v2_H16_00cm_png'
set multiplot layout 3,1 title 'Impact at H=16 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H16_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H16_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H16_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 17 cm
set output 'plot_v2_H17_00cm_png'
set multiplot layout 3,1 title 'Impact at H=17 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H17_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H17_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H17_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 18 cm
set output 'plot_v2_H18_00cm_png'
set multiplot layout 3,1 title 'Impact at H=18 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H18_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H18_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H18_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 19 cm
set output 'plot_v2_H19_00cm_png'
set multiplot layout 3,1 title 'Impact at H=19 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H19_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H19_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H19_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot

# height = 20 cm
set output 'plot_v2_H20_00cm_png'
set multiplot layout 3,1 title 'Impact at H=20 cm'
set xlabel 't, s'
set ylabel 'x, m'
plot 'trajectory_v2_H20_00cm_txt' using 1:2 with lines title 'Displacement'
set ylabel 'v, m/s'
plot 'trajectory_v2_H20_00cm_txt' using 1:3 with lines title 'Velocity'
set ylabel 'F, N'
plot 'trajectory_v2_H20_00cm_txt' using 1:4 with lines title 'Force'
unset multiplot
