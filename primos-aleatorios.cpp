#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::endl;

bool esPrimo(int numero){
  //Si no es par:
  if(numero % 2 == 0){
      return false;
  }
  // Casos especiales
  if (numero == 0 || numero == 1 || numero == 4) return false;
  //Comprobacion numero a numero
  for (int x = 3; x < numero / 2; x+=2) {
    if (numero % x == 0) return false;
  }
  return true;
  
}
int generador_primos(int min, int max){
  srand((unsigned int)time(NULL));
  int n = rand()%(max-min)+min;
  
  
  while(esPrimo(n)==0){
    n = rand()%(max-min)+min;
  }
  
  return n;
}

int main() {
  int res = generador_primos(0,100);
  cout<<res;
}
