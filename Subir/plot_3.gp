set title 'Tamaño vs Tiempo'
set xlabel 'Número de pasos'; set ylabel 'Tamaño'
set grid
set term pdf; set out 'punto_1.pdf'
plot 'datos_3.txt' u 1:2 w lp t 'Tamaño'


