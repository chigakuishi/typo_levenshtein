set terminal png
set output '/var/www/html/share/miss_count_cdf_log.png'
set multiplot
set logscale
set xlabel 'leveshtein / length'
set ylabel 'cdf'
set xrange [0.001 : 0.5 ]
set yrange [  : 1 ]
unset key
set grid

plot 'cdf.tmp' linecolor rgbcolor "red" w lp
plot 'cdf_typo.tmp' linecolor rgbcolor "green" w lp
plot 'cdf_typo_cng.tmp' linecolor rgbcolor "blue" w lp

set parametric
set trang[0:1]

exit
