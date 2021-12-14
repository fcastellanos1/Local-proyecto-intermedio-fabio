gprof: report_gprof.txt

report_gprof.txt: simulacion_taza.cpp funciones.cpp
	g++ -g -pg $< funciones.cpp -o report.x
	./report.x
	gprof ./report.x gmon.out > $@
