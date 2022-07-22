#Data from marines salary history
#Minimum 36366.00
#Midpoint 45458.00
#Maximum 54551.00

#Minimum_L04-G14 77222
#Midpoint_L04-G14 96528
#Maximum_L04-G14 115836

#01-05-2015	0	34900.00	0.00	2500.00	L02-G09
#15-05-2016	380	35633.00	2.10	0.00	L02-G09
#01-08-2016	425	36380.00	2.10	2606.11	L02-G09
#10-03-2017	615	37411.00	2.83	0.00	L02-G09
#01-12-2017	882	49999.97	33.7	3581.66	L04-G13
#01-04-2018	1067	51750.00	3.50	0.00	L04-G13
#01-04-2019	1432	53612.96	0.00	0.00	L04-G13
#01-07-2019	1523	58920.69	0.00	0.00	L04-G14
#01-04-2020	1798	60806.13	0.00	0.00	L04-G14
#01-09-2020	1951	70000.05	0.00	0.00	L05-G16
#01-06-2021	2224	72380.09	0.00	0.00	L05-G16
#01-04-2022	2528	74913.41	0.00	0.00	L05-G16
#01-07-2022	2619	89896.01	20.0	6439.54
#01-04-2023	2893	107875.21	20.0	7727.45

## Fitting, uncomment the two lines below to calculate a new 'm' and 'c' values if new points are added to the data table
#f(x) = m*x+c
#fit [0:2893] f(x) "-" using 2:3 via m,c #the range must be updated if a new data point is available
m = 22.5668 #temporary value, always recalc if new data point are available
c = 26824.1 #also temporary
set key left top
set arrow 1 from 0,36366 to 6000,36366 nohead
set arrow 2 from 0,45458 to 6000,45458 nohead
set arrow 3 from 0,54551 to 6000,54551 nohead
set arrow 4 from 0,77222 to 6000,77222 nohead
set arrow 5 from 0,96528 to 6000,96528 nohead
set arrow 6 from 0,115836 to 6000,115836 nohead
set title "Projected Salary of Marine"
set xlabel "Days since employment started"
set ylabel "Annual Salary in Euro"
set xrange [0:6000]
set xtics 0,365,6000
set yrange [34900:120000]
set ytics 34900,5000,120000
set out "Salary_projection.png"
set terminal png size 2000,1500 enhanced font "Helvetica,20"

#Plotting
p "-" u 2:3 title "Actual Salary" w lp,\
	"-" u 2:3, m*x+c title "Projected Salary" w l

#date		day	annual	increase	(%)	monthly
01-05-2015	0	34900.00	0.00	2500.00
15-05-2016	380	35633.00	2.10	0.00
01-08-2016	425	36380.00	2.10	2606.11
10-03-2017	615	37411.00	2.83	0.00
01-12-2017	882	49999.97	33.7	3581.66
01-04-2018	1067	51750.00	3.50	0.00
01-04-2019	1432	53612.96	0.00	0.00
01-07-2019	1523	58920.69	0.00	0.00
01-04-2020	1798	60806.13	0.00	0.00
01-09-2020	1951	70000.05	0.00	0.00
01-06-2021	2224	72380.09	0.00	0.00
01-04-2022	2528	74913.41	0.00	0.00
01-07-2022	2619	89896.01	20.0	6439.54
01-04-2023	2893	107875.21	20.0	7727.45
end
