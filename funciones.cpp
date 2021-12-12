#include "funciones.h"

Eigen::MatrixXi creacion_matrix(int size, int nparticulas){
  Eigen::MatrixXi matriz(size, size);
  if (size%2==0){
    matriz(size/2 -1, size/2 -1) = nparticulas/4;
    matriz(size/2 -1, size/2) = nparticulas/4;
    matriz(size/2, size/2 -1) = nparticulas/4;
    matriz(size/2, size/2) = nparticulas/4 + (nparticulas%4);
  }
  else {
    matriz(size/2, size/2) = nparticulas;
  }
  return matriz;
}

Eigen::MatrixXi creacion_posiciones(Eigen::MatrixXi matrix, int nparticulas){
  int size = matrix.rows();
  int particula_i = nparticulas -1;
  Eigen::MatrixXi posiciones(nparticulas, 2);
  for(int ii = 0; ii<size; ii++){
    for(int jj = 0; jj<size; jj++){
      int contador_casilla = matrix(ii, jj);
      while (contador_casilla > 0){
	posiciones(particula_i, 0) = ii;
	posiciones(particula_i, 1) = jj;
	--particula_i;
	--contador_casilla;
      }
    }
  }
  return posiciones;
}

void print_system(Eigen::MatrixXi matrix, Eigen::MatrixXi posiciones, int t){
  std::cout<<"Casillas del sistema:\n";
  std::cout << matrix << std::endl;
  std::cout <<"Posiciones de las partículas:\n";
  std::cout << posiciones << std::endl;
  std::cout <<"Número de pasos: "<<t<<std::endl;
}

void step(Eigen::MatrixXi & matrix, Eigen::MatrixXi & posiciones, int & t, int & seed){
  int nparticulas = posiciones.rows();
  //Inserte codigo para numero aleatorio entre 0 y nparticulas-1
  int particula_i = aleatorio(seed, 0, nparticulas -1);
  seed += 5;
  //Inserte codigo para numero aleatorio entre 0 y 4 (movimientos)
  int movimiento = aleatorio(seed, 0, 4);
  seed += 5;
  if(movimiento==1){
    matrix(posiciones(particula_i, 0), posiciones(particula_i, 1)) -=1;
    matrix(posiciones(particula_i, 0) -1, posiciones(particula_i, 1)) += 1;
    posiciones(particula_i, 0) -= 1;
  }
  if(movimiento==2){
    matrix(posiciones(particula_i, 0), posiciones(particula_i, 1)) -=1;
    matrix(posiciones(particula_i, 0), posiciones(particula_i, 1) +1) += 1;
    posiciones(particula_i, 1) += 1;
  }
  if(movimiento==3){
    matrix(posiciones(particula_i, 0), posiciones(particula_i, 1)) -=1;
    matrix(posiciones(particula_i, 0) +1, posiciones(particula_i, 1)) += 1;
    posiciones(particula_i, 0) += 1;
  }
  if(movimiento==4){
    matrix(posiciones(particula_i, 0), posiciones(particula_i, 1)) -=1;
    matrix(posiciones(particula_i, 0), posiciones(particula_i, 1) -1) += 1;
    posiciones(particula_i, 1) -= 1;
  }
  t += 1;
}

int aleatorio(int semilla, int min, int max){
  typedef std::mt19937 MyRNG;
  uint32_t seed_val;
  MyRNG rng;
  
  rng.seed(semilla);
  
  std::uniform_int_distribution<uint32_t> uint_dist10(min, max);
  return uint_dist10(rng);
}

void test_aleatorio(int semilla, int min, int max){
  int i = semilla;
  int numbers = max - min +1;
  int data[numbers] = {0};
  while (i > 0){
    int n = aleatorio(i, min, max);
    int index = n - min;
    //std::cout<<n<<"\n";
    data[index] ++;
    i--;
  }
  double media = 0.0;
  for(int jj = 0; jj < numbers; jj++){
    double sum = data[jj];
    media = (sum + 0.0)/(semilla + 0.0);
    std::cout<<media<<"\n";
  }
}

double calcular_entropia(Eigen::MatrixXi matrix, int nparticulas){
  int size = matrix.rows();
  double sum = 0.0;
  for(int ii = 0; ii< size; ii++){
    for(int jj = 0; jj< size; jj++){
      if(matrix(ii, jj) != 0){
	double P_i = (matrix(ii, jj)+0.0)/(nparticulas+0.0);
	sum += (P_i * std::log(P_i));
      }
    }
  }
  return -sum;
}
