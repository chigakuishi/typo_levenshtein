set terminal svg
set output '/var/www/html/share/miss_count_cdf.svg'
set multiplot
set logscale
set xlabel 'leveshtein / length'
set ylabel 'cdf'
set xrange [  : 30 ]
set yrange [  : 1 ]
unset key
set grid

plot 'tmp' w lp

set parametric
set trang[0:1]
const = 0.1
plot const,t with lines

exit
