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
  int size = matrix.rows();
  int nparticulas = posiciones.rows();
  //Función para numero aleatorio entre 0 y nparticulas-1 :
  int particula_i = aleatorio(seed, 0, nparticulas -1);
  int p_ii = posiciones(particula_i, 0);
  int p_jj = posiciones(particula_i, 1);
  int movimiento = aleatorio(seed, 0, 4);
  //Casos especiales en los bordes:
  if( p_ii == 0 || p_ii == (size-1) || p_jj == 0 || p_jj == (size-1) ){
    /*Del 1 al 4 son casos en las esquinas, del 5 al 8 son el resto de los bordes,
      y el caso 0 son los no-bordes, que es el default, el cual no entra al if.
    */
    if(p_ii == 0 && p_jj == 0){ //1
      while (movimiento == 1 || movimiento == 4){movimiento = aleatorio(seed, 0, 4);}
    }
    
    if(p_ii == 0 && p_jj == (size -1)){ //2
      while (movimiento == 1 || movimiento == 2){movimiento = aleatorio(seed, 0, 4);}
    }
    
    if(p_ii == (size -1) && p_jj == 0){ //3
      while (movimiento == 3 || movimiento == 4){movimiento = aleatorio(seed, 0, 4);}
    }

    if(p_ii == (size -1) && p_jj == (size -1)){ //4
      while (movimiento == 2 || movimiento == 3){movimiento = aleatorio(seed, 0, 4);}
    }

    if(p_ii == 0 && p_jj != 0 && p_jj != (size -1)){ //5
      while (movimiento == 1){movimiento = aleatorio(seed, 0, 4);}
    }
    
    if(p_jj == (size -1) && p_ii != 0 && p_ii != (size -1)){ //6
      while (movimiento == 2){movimiento = aleatorio(seed, 0, 4);}
    }
    
    if(p_ii == (size -1) && p_jj != 0 && p_jj != (size -1)){ //7
      while (movimiento == 3){movimiento = aleatorio(seed, 0, 4);}
    }
    
    if(p_jj == 0 && p_ii != 0 && p_ii != (size -1)){ //8
      while (movimiento == 4){movimiento = aleatorio(seed, 0, 4);}
    }
    
  }
  //Acciones: 0 (quieto), 1(arriba), 2(derecha), 3(abajo), 4(izquierda)
  if(movimiento==1){
    matrix(p_ii, p_jj) -=1;
    matrix(p_ii -1, p_jj) += 1;
    posiciones(particula_i, 0) -= 1;
  }
  if(movimiento==2){
    matrix(p_ii, p_jj) -=1;
    matrix(p_ii, p_jj +1) += 1;
    posiciones(particula_i, 1) += 1;
  }
  if(movimiento==3){
    matrix(p_ii, p_jj) -=1;
    matrix(p_ii +1, p_jj) += 1;
    posiciones(particula_i, 0) += 1;
  }
  if(movimiento==4){
    matrix(p_ii, p_jj) -=1;
    matrix(p_ii, p_jj -1) += 1;
    posiciones(particula_i, 1) -= 1;
  }
  t += 1;
}

int aleatorio(int & semilla, int min, int max){
  typedef std::mt19937 MyRNG;
  uint32_t seed_val;
  MyRNG rng;
  
  rng.seed(semilla);
  
  std::uniform_int_distribution<uint32_t> uint_dist10(min, max);
  semilla += 1;
  return uint_dist10(rng);
}

void test_aleatorio(int & semilla, int min, int max){
  int i = 10000;
  int numbers = max - min +1;
  int data[numbers] = {0};
  while (i > 0){
    int n = aleatorio(semilla, min, max);
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

double calcular_entropia_2(Eigen::MatrixXi matrix, int nparticulas){
  int size = matrix.rows();
  double sum = 0.0;
  for(int ii = 0; ii< size; ii++){
    for(int jj = 0; jj< size; jj++){
      if(matrix(jj, ii) != 0){
	double P_i = (matrix(jj, ii)+0.0)/(nparticulas+0.0);
	sum += (P_i * std::log(P_i));
      }
    }
  }
  return -sum;
}

double calcular_entropia_3(Eigen::MatrixXi matrix, int nparticulas){
  int size = matrix.size();
  double sum = 0.0;
  for(int i = 0 ; i < size; i++){
    int valor =  *(matrix.data() + i);
    if( valor != 0 ){
      double P_i = (valor+0.0) /(nparticulas+0.0);
      sum +=  (P_i * std::log(P_i));
    }
  }
  return -sum;
}
