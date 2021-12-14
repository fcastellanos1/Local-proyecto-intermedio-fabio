set title 'Entropía vs Tiempo'
set xlabel 'Número de pasos'; set ylabel 'Entropía'
set grid
set term png; set out 'punto_1.png'
plot 'datos_1.txt' u 1:2 w lp t 'Entropía'