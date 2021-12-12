#include "funciones.h"

int main(void)
{
  int SIZE = 10;
  int N = 5;
  int seed = 1;
  int time = 0;
  Eigen::MatrixXi M = creacion_matrix(SIZE, N);
  Eigen::MatrixXi P = creacion_posiciones(M, N);
  print_system(M, P, time);
  std::cout<<"Entropia: "<<calcular_entropia(M, N)<<"\n";
  for(int ii=1; ii<= 10; ii++){
    std::cout<<"Haciendo un paso:\n"<<"\n";
    step(M, P, time, seed);
    print_system(M, P, time);
    std::cout<<"Entropia: "<<calcular_entropia(M, N)<<"\n";
  }
  return 0;
}

  
