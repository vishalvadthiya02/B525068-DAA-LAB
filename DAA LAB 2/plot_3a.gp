set title "Method 1 - Repeated Merge"
set xlabel "Number of Arrays (k)"
set ylabel "Execution Time (seconds)"
set grid
plot "method1.dat" using 1:2 with linespoints lw 2 title "Method 1"