set terminal svg
set output '/var/www/html/share/miss_count_cdf.svg'
set multiplot
#set logscale
set xlabel 'leveshtein / length'
set ylabel 'cdf'
set xrange [0.001 : 2 ]
set yrange [  : 1 ]
unset key
set grid

plot 'cdf.tmp' w lp
plot 'cdf_typo.tmp' w lp

set parametric
set trang[0:1]

exit
