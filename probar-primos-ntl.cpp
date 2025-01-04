#include <iostream>
using std::cout;
using std::endl;
#include <NTL/ZZ.h>
using NTL::ZZ;
using NTL::ProbPrime;


bool probarPrimoNTL(ZZ n){
    return ProbPrime(n,10);
}
int main(){
    probarPrimoNTL(ZZ(52684));
}
