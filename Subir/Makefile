

all: punto_1.pdf punto_3.pdf punto_4.pdf


punto_1.pdf: plot_1.gp datos_1.txt
	gnuplot $<

datos_1.txt: punto_1.out
	./$< > $@

punto_1.out: punto_1.cpp funciones.cpp funciones.h
	g++ -g -pg $< funciones.cpp -o punto_1.out





punto_3.pdf: plot_3.gp datos_3.txt
	gnuplot $<

datos_3.txt: punto_3.out
	./$< > $@

punto_3.out: punto_3.cpp funciones.cpp funciones.h
	g++ -g -pg $< funciones.cpp -o punto_3.out




punto_4.pdf: plot_4.gp datos_4.txt
	gnuplot $<

datos_4.txt: punto_4.out
	./$< > $@

punto_4.out: punto_4.cpp funciones.cpp funciones.h
	g++ -g -pg $< funciones.cpp -o punto_4.out




gprof: report_gprof.txt

report_gprof.txt: simulacion_taza.cpp funciones.cpp
	g++ -g -pg $< funciones.cpp -o report.x
	./report.x
	gprof ./report.x gmon.out > $@



clean:
	rm -f *.out *.x *.txt *.png *.pdf
