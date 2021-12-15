#include "funciones.h"

int main(void)
{
  int num_elementos;
  num_elementos=3;   
  double data[num_elementos];
  std::ifstream input("input.txt");
   
  for (int i = 0; i < num_elementos; i++) {
    input >> data[i];
    std::cout<< data[i]<<std::endl;
  }
   

  int seed = 0;
  int time = 0;
  Eigen::MatrixXi M = creacion_matrix(data[0], data[1]);
  Eigen::MatrixXi P = creacion_posiciones(M, data[1]);
  print_system(M, P, time);
  std::cout<<"Entropia inicial: "<<calcular_entropia_3(M, data[1])<<"\n";
  for(int ii=1; ii<= data[2]; ii++){
    std::cout<<"Haciendo un paso:\n"<<"\n";
    step(M, P, time, seed);
    print_system(M, P, time);
    std::cout<<"Entropia del paso t="<<time<<": "<<calcular_entropia_3(M, data[1])<<"\n";

  }
  return 0;
}

  
