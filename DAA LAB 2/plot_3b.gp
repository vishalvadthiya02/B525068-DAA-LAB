set title "Method 2 - Pairwise Merge"
set xlabel "Number of Arrays (k)"
set ylabel "Execution Time (seconds)"
set grid
plot "method2.dat" using 1:2 with linespoints lw 2 title "Method 2"