#include <iostream>
using std::cout;
using std::endl;
#include <NTL/ZZ.h>
using NTL::ZZ;
using NTL::ProbPrime;
using NTL::RandomBits_ZZ;

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
int main(){
    cout<<generarPrimoNTL(128)<<endl;


}
