#include <iostream>
using std::cout;
using std::endl;

int moduloPositivo(long int dividendo, long int divisor){
	long int cociente=dividendo/divisor; //Definir cociente
	long int residuo=dividendo-(cociente*divisor);//Definir residuo
	if(residuo<0 && divisor>0){//Si el residuo es negativo y el divisor positivo
		residuo=divisor+residuo;
		cociente-=1;
	}else if(residuo<0 && divisor<0){//Si el residuo es negativo y el divisor negativo
		residuo=(-divisor)+residuo;
		cociente+=1;
	}
	return residuo;
}

int exponenciacionModular(int numero, int exponente, int modulo){
  bool end = false;
  int contadorExponencial = 1;
  int exponenteCopia=exponente;
  int valorBinario = 0;

  unsigned int valorModularAnterior=numero;
  unsigned int valorModular=numero;

  unsigned int resultadoAnterior=numero;
  unsigned int resultado=numero;

  int comprobador=0;

  while(end == 0){

    //Reorganizar valores
    valorModularAnterior=valorModular;
    if(valorBinario==1)
    resultadoAnterior=resultado;



    //Obtener 0 o 1 del exponente.
    if(exponente%2==0){
      valorBinario=0;
    }else{
      valorBinario=1;
    }

    if(valorBinario==1)
    comprobador+=contadorExponencial;

    //Obtener valor modular elevado al cuadrado.
    if(contadorExponencial==1){
      valorModular=numero;
    }else{
      valorModular= moduloPositivo((valorModularAnterior*valorModularAnterior),modulo);
    }

    //Obtener resultado parcial.

    if(contadorExponencial==1){
      resultado=numero;
    }else{
      if(valorBinario==1)
      resultado=moduloPositivo((resultadoAnterior*valorModular),modulo);
    }

    //Dividir exponente entre 2.
    exponente = exponente/2;

    //Aumentar contador.
    contadorExponencial = contadorExponencial*2;

    //Finalizar
    if(exponente == 0)
      end = 1;

  }
  if(comprobador==exponenteCopia){
    return resultado;
  }else{
    return 0;
  }

}
int main() {
  cout<<exponenciacionModular(188, 2, 221);
}
