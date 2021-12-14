#include "funciones.h"

int main(void)
{
  int SIZE = 20;
  int N = 400;
  int seed = 0;
  int time = 0;
  int pasos_max = 100000;
  Eigen::MatrixXi M = creacion_matrix(SIZE, N);
  Eigen::MatrixXi P = creacion_posiciones(M, N);
  //print_system(M, P, time);
  std::cout<<"Entropia inicial: "<<calcular_entropia(M, N)<<"\n";
  for(int ii=1; ii<= pasos_max; ii++){
    std::cout<<"Haciendo un paso:\n"<<"\n";
    step(M, P, time, seed);
    //print_system(M, P, time);
    std::cout<<"Entropia del paso t="<<time<<": "<<calcular_entropia(M, N)<<"\n";
  }
  return 0;
}

  
