reset
set terminal qt 1 noraise enhanced
#set xlabel "Time (sec)"
#set ylabel "Displacement (m), Velocity (m/s)"
#set title "Vanderpol Oscillator using Runge Kutta's method"
#set key box top left spacing 1.5
plot sin(x) 
set terminal pdfcairo enhanced color notransparent
set output 'cc.pdf'
replot
unset output
unset terminal