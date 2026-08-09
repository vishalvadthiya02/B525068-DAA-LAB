set title "Merge Sort vs Modified Merge Sort"
set xlabel "Input Size"
set ylabel "Execution Time (seconds)"
set grid
set key left top

plot "merge.dat" using 1:2 with linespoints lw 2 title "Merge Sort", \
     "merge.dat" using 1:3 with linespoints lw 2 title "Modified Merge Sort"