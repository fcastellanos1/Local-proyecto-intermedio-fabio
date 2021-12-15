punto_2.pdf: plot_2.gp datos_2.txt
	gnuplot $<

datos_2.txt: punto_2.out
	./$< > $@

punto_2.out: punto_2.cpp funciones.cpp funciones.h
	g++ -g -pg $< funciones.cpp -o $@

punto_1.png: plot_1.gp datos_1.txt
	gnuplot $<

datos_1.txt: punto_1.out
	./$< > $@

punto_1.out: punto_1.cpp funciones.cpp funciones.h
	g++ -g -pg $< funciones.cpp -o punto_1.out

gprof: report_gprof.txt

report_gprof.txt: simulacion_taza.cpp funciones.cpp
	g++ -g -pg $< funciones.cpp -o report.x
	./report.x
	gprof ./report.x gmon.out > $@

report: main.tex
	pdflatex informe

clean:
	rm -rf *.x *.out *.x.* *~
