#include <NTL/ZZ.h>
using NTL::ZZ;

//Sin NTL
int moduloPositivo(long int dividendo, long int divisor);
int* euclidesExtendido(int r1, int r2, int s1=1, int s2=0, int t1=0, int t2=1);
int euclides(int r1, int r2);
bool esPrimo(int numero);
int generador_primos(int min, int max);
int generador_coprimos(int numero);
int inversa_modular(int n1, int n2);
int exponenciacionModular(int numero, int exponente, int modulo);
//Con NTL
ZZ moduloNTL(ZZ dividendo, ZZ divisor);
ZZ expModularNTL(const ZZ &a, const ZZ &e, const ZZ &n);
ZZ euclidesNTL(ZZ r1, ZZ r2);
ZZ* euclidesExtendidoNTL(ZZ r1, ZZ r2, int s1=1, int s2=0, int t1=0, int t2=1);
ZZ inversa_modularNTL(ZZ n1, ZZ n2);
ZZ generar_aleatorioNTL(int bits);
bool probarPrimoNTL(ZZ n);
ZZ generarPrimoNTL(int bits);
