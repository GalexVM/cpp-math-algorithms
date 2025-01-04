#include <iostream>
void moduloPositivo(long int dividendo, long int divisor){
	long int cociente=dividendo/divisor; //Definir cociente
	long int residuo=dividendo-(cociente*divisor);//Definir residuo
	if(residuo<0 && divisor>0){//Si el residuo es negativo y el divisor positivo
		residuo=divisor+residuo;
		cociente-=1;
	}else if(residuo<0 && divisor<0){//Si el residuo es negativo y el divisor negativo
		residuo=(-divisor)+residuo;
		cociente+=1;
	}
	std::cout<<"cociente: "<<cociente<<std::endl<<"residuo: "<<residuo<<std::endl;
}
int main() {
   moduloPositivo(34+17+17+17+17+17,30);
}

