#include "funciones.h"

int main(void)
{
  int SIZE = 10; //poner 20
  int N = 5; //poner 400
  int seed = 0;
  int time = 0;
  int pasos_max = 10;
  Eigen::MatrixXi M = creacion_matrix(SIZE, N);
  Eigen::MatrixXi P = creacion_posiciones(M, N);
  print_system(M, P, time);
  std::cout<<"Entropia inicial: "<<calcular_entropia_3(M, N)<<"\n";
  for(int ii=1; ii<= pasos_max; ii++){
    std::cout<<"Haciendo un paso:\t";
    step_2(M, P, time, seed);
    print_system(M, P, time);
    std::cout<<"Entropia del paso t="<<time<<": "<<calcular_entropia_3(M, N)<<"\n \n";

    std::cout << "compo "<<std::sqrt(P(0,0))<< "," << SIZE/2 << "\n";
    std::cout << "tamano " << calcular_tamano(M , P, N) << "\n";
  }
  return 0;
}
