set title 'Numero Particulas vs Tiempo'
set xlabel 'Número de pasos'; set ylabel 'Numero Particulas'
set grid
set term pdf; set out 'punto_4.pdf'
plot 'datos_4.txt' u 1:2 w lp t 'Particulas


