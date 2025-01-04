#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <NTL/ZZ.h>
using NTL::ZZ;
using NTL::conv;

ZZ* euclidesExtendidoNTL(ZZ r1, ZZ r2, int s1=1, int s2=0, int t1=0, int t2=1);
ZZ inversa_modularNTL(ZZ n1, ZZ n2);

int main(){
	ZZ a (13945577);
	ZZ b (98475077);
	ZZ resultado = inversa_modularNTL(a,b);
	cout<<resultado<<endl;

}

ZZ inversa_modularNTL(ZZ n1, ZZ n2){
	ZZ* euclArr = euclidesExtendidoNTL(n1,n2);
	ZZ res ( *(euclArr+1));
	return res;
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

