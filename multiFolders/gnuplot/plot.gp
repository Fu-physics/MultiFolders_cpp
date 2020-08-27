reset
set terminal qt 1 noraise enhanced
#set xlabel "Time (sec)"
#set ylabel "Displacement (m), Velocity (m/s)"
#set title "Vanderpol Oscillator using Runge Kutta's method"
#set key box top left spacing 1.5
plot 'cc.dat' using 1:2 with lines title '<set1 * set1>', \
     'cc.dat' using 1:3 with lines dashtype 1 linecolor 5 title '<set2 * set2>',\
     'cc.dat' using 1:4 with lines dashtype 2 linecolor 7 title '<set1 * set2>'
set terminal pdfcairo enhanced color notransparent
set output 'cc.pdf'
replot
unset output
unset terminal