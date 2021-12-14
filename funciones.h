#ifndef FUNCIONES_H_
#define FUNCIONES_H_
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cmath>
#include <eigen3/Eigen/Dense>
#include <random>

Eigen::MatrixXi creacion_matrix(int size, int nparticulas);
Eigen::MatrixXi creacion_posiciones(Eigen::MatrixXi matrix, int nparticulas);
void print_system(Eigen::MatrixXi matrix, Eigen::MatrixXi posiciones, int t);
void step(Eigen::MatrixXi & matrix, Eigen::MatrixXi & posiciones, int & t, int & seed);
int aleatorio(int & semilla, int min, int max);
void test_aleatorio(int & semilla, int min, int max);
double calcular_entropia(Eigen::MatrixXi matrix, int nparticulas);
double calcular_entropia_2(Eigen::MatrixXi matrix, int nparticulas);
double calcular_entropia_3(Eigen::MatrixXi matrix, int nparticulas);

#endif
