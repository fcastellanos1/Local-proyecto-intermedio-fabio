#include "funciones.h"

int main(void)
{
  int SIZE = 20; //poner 20
  int N = 400; //poner 400
  int seed = 0;
  int time = 0;
  int pasos_max = 1000000;
  Eigen::MatrixXi M = creacion_matrix(SIZE, N);
  Eigen::MatrixXi P = creacion_posiciones(M, N);
  //print_system(M, P, time);
  std::cout<<"Entropia inicial: "<<calcular_entropia_3(M, N)<<"\n";
  for(int ii=1; ii<= pasos_max; ii++){
    std::cout<<"Haciendo un paso:\t";
    step_2(M, P, time, seed);
    //print_system(M, P, time);
    std::cout<<"Entropia del paso t="<<time<<": "<<calcular_entropia_3(M, N)<<"\n \n";
  }
  return 0;
}
