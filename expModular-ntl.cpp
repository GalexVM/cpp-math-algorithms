#include <iostream>
using std::cout;
using std::endl;
using std::cin;
#include <NTL/ZZ.h>
using NTL::ZZ;
using NTL::conv;

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
int main(){
    cout<<expModularNTL(conv<ZZ>("30192"),conv<ZZ>("43791"),conv<ZZ>("65301"))<<endl;
}
