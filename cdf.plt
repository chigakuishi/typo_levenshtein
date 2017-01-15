set terminal png font "MigMix 2M,14"
set output '/var/www/html/share/cmp.png'
#set logscale
set xlabel 'leveshtein / length'
set ylabel 'cdf'
set xrange [0.001 : 0.5 ]
set yrange [  : 1 ]
set grid
set key right bottom
plot 'cdf.tmp' linecolor rgbcolor "red" lw 1 title "従来のLevenshtein距離"  w lp, 'cdf_typo_cng.tmp' linecolor rgbcolor "blue" lw 2 title "本手法を用いて算出した距離" w lp

set parametric
set trang[0:1]

exit
