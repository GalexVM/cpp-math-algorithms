#include <iostream>
using std::cout;
using std::endl;
#include <NTL/ZZ.h>
using NTL::ZZ;
using NTL::conv;
using NTL::RandomBits_ZZ;
#include <ctime>
#include <cstdlib>
#include "./math-functions.h"
//NTL
ZZ moduloNTL(ZZ dividendo, ZZ divisor){
	ZZ cociente=dividendo/divisor; //Definir cociente
	ZZ residuo=dividendo-(cociente*divisor);//Definir residuo
	if(residuo<0 && divisor>0){//Si el residuo es negativo y el divisor positivo
		residuo=divisor+residuo;
		cociente-=1;
	}else if(residuo<0 && divisor<0){//Si el residuo es negativo y el divisor negativo
		residuo=(-divisor)+residuo;
		cociente+=1;
	}
	return residuo;
}
ZZ expModularNTL(const ZZ &a, const ZZ &e, const ZZ &n)
{
   if (e == 0) return ZZ(1);

   long k = NumBits(e);

   ZZ res;
   res = 1;

   for (long i = k-1; i >= 0; i--) {
      res = (res*res) % n;
      cout<<bit(e,i)<<endl;
      if (bit(e, i) == 1) res = (res*a) % n;
   }

   if (e < 0)
      return InvMod(res, n);
   else
      return res;
}
ZZ euclidesNTL(ZZ r1, ZZ r2){
	ZZ q,r;
	while(r2>0){
		q = r1/r2;
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;
	}
	return r1;
}
ZZ* euclidesExtendidoNTL(ZZ r1, ZZ r2, int s1, int s2, int t1, int t2){
	ZZ q,r,s,t;
	ZZ S1 (conv<ZZ>(s1));
	ZZ S2 (conv<ZZ>(s2));
	ZZ T1 (conv<ZZ>(t1));
	ZZ T2 (conv<ZZ>(t2));
	while(r2>0){
		q = r1/r2;
		//Updating r's
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;
		//Updating s's
		s = S1 - (q*S2);
		S1 = S2;
		S2 = s;
		//Updating t's
		t = T1 - (q*T2);
		T1 = T2;
		T2 = t;
	}
	static ZZ resultados[3] = {r1,S1,T1};
	ZZ* rpta = resultados;
	return rpta;
}
ZZ inversa_modularNTL(ZZ n1, ZZ n2){
	ZZ* euclArr = euclidesExtendidoNTL(n1,n2);
	ZZ res ( *(euclArr+1));
	return res;
}
ZZ generar_aleatorioNTL(int bits){
    if(bits == 1)
        return RandomBits_ZZ(bits);
    ZZ numero(0);
    ZZ minNum(2);

    for(int x = 0;x<bits-2;x++)
        minNum= 2*minNum;

    while(numero<minNum)
        numero =RandomBits_ZZ(bits);

    return numero;
}
bool probarPrimoNTL(ZZ n){
    return ProbPrime(n,10);
}
ZZ generarPrimoNTL(int bits){
    ZZ numero (generar_aleatorioNTL(bits));
    while (probarPrimoNTL(numero) == false){
        numero = generar_aleatorioNTL(bits);
    }
    return numero;
}
//Sin NTL------------------------------------------------------------------------------------------------------------------------
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

int euclides(int r1, int r2){
	int q,r;
	while(r2>0){
		q = r1/r2;
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;
	}
	return r1;
}

int* euclidesExtendido(int r1, int r2, int s1, int s2, int t1, int t2){
	int q,r,s,t;
	while(r2>0){
		q = r1/r2;
		//Updating r's
		r = r1 - (q*r2);
		r1 = r2;
		r2 = r;
		//Updating s's
		s = s1 - (q*s2);
		s1 = s2;
		s2 = s;
		//Updating t's
		t = t1 - (q*t2);
		t1 = t2;
		t2 = t;
	}
	static int resultados[3] = {r1,s1,t1};
	int* rpta = resultados;
	return rpta;
}

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

int generador_coprimos(int numero){

	srand((unsigned int)time(NULL));
  	int n = rand()%(numero);

  	while(euclides(n,numero)!=1){
  		n = rand()%(numero);
  	}

  	return n;
}

int inversa_modular(int n1, int n2){
	int* euclArr = euclidesExtendido(n1,n2);
	int res = *(euclArr+1);
	return res;
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



