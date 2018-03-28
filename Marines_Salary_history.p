#Data from marines salary history
#Minimum 36366.00
#Midpoint 45458.00
#Maximum 54551.00

#f(x) = m*x+c
#fit [0:882] f(x) "-" using 2:3 via m,c
m = 15.7667
c = 31605
set key left top
set arrow 1 from 0,45458 to 6000,45458 nohead
set arrow 2 from 0,54551 to 6000,54551 nohead
set arrow 3 from 0,65131 to 6000,65131 nohead
set title "Projected Salary of Marine"
set xlabel "Days since employment started"
set ylabel "Annual Salary in Euro"
set xrange [0:6000]
set xtics 0,365,6000
set yrange [34900:66000]
set ytics 34900,1000,66000
set out "Salary_projection.png"
set terminal png size 2000,1500 enhanced font "Helvetica,20"
plot "-" using 2:3, m*x+c title "Projected Salary" \
with lines, \
"-" using 2:3 title "Actual Salary" \
with points
#plot "-" using 2:3 title "Actual Salary" \
#with points, \
#"-" using 2:3, m*x+c title "Projected Salary = " \
#with lines
#date	day	annual	increase (%)	monthly
01-05-2015	0	34900.00	0.00	2500.00
15-05-2016	380	35633.00	2.10	0.00
01-08-2016	425	36380.00	2.10	2606.11
10-03-2017	615	37411.00	2.83	0.00
01-12-2017	882	50000.00	33.7	3581.66
01-04-2018	1067	51750.00	3.50	0.00
end
