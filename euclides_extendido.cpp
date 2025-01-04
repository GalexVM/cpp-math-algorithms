#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int* euclidesExtendido(int r1, int r2, int s1=1, int s2=0, int t1=0, int t2=1);
void imprimirResultado(int*resultado);

int main(){
	int a = 12;
	int b = 15;
	int*resultado = euclidesExtendido(a,b);
	imprimirResultado (resultado);
}
void imprimirResultado(int*resultado){
	for(int i=0;i<3;i++){
		cout<<*(resultado + i)<<endl;
	}
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



