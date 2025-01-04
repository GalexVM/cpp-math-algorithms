#include <iostream>

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

int main(){
	int numero = 91;
	cout<<esPrimo(numero)<<endl;
}
