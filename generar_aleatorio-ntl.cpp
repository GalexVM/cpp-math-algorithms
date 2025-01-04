#include <iostream>
using std::cout;
using std::endl;
#include <NTL/ZZ.h>
using NTL::ZZ;
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
int main(){

    cout<<generar_aleatorioNTL(16)<<endl;
    return 0;
}
