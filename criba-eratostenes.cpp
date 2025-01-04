#include <iostream>
using std::cout;
using std::endl;
#include <NTL/ZZ.h>
using NTL::ZZ;
using NTL::conv;
using NTL::RandomBits_ZZ;
#include <vector>
using std::vector;




ZZ pot(ZZ base, ZZ exponente) {
    if (exponente == 0) return ZZ(1);
    ZZ x = pot(base, exponente/2);
    if (exponente % 2 == 0) return x*x;
    return x*x*base;
}
ZZ mod(ZZ a, ZZ b){
	ZZ q= a/b;
	ZZ	r= a- (q*b);
	if(a<ZZ(0)){
		ZZ ar=r;
	    r= b+ar;
	}
	return r;
}

vector<ZZ> cribaEratostenes(int bit,vector<ZZ>vec={}){

    if(bit == 4){
        vector<ZZ> aux;
            aux.push_back(ZZ(2));
            aux.push_back(ZZ(3));
            aux.push_back(ZZ(5));
            aux.push_back(ZZ(7));
            aux.push_back(ZZ(11));
            aux.push_back(ZZ(13));
        return aux;
    }
    vec = cribaEratostenes(bit/2,vec);
    vector<ZZ>rowVec;
    ZZ bigInt ( pot( ZZ(2),conv<ZZ>(bit) ) );
    ZZ i ( bigInt / 2 );
    if( mod( i,ZZ(2) ) == 0 )i++;//Hacerlo impar.

    for( ; i < bigInt - 1; i+=2){//Numeros impares del bit
        rowVec.push_back(i);//Llenar vector.
    }
    cout<<"rowVec "<<bit<<": "<<endl;
    for(int i = 1; i < rowVec.size(); i++)
        cout<<rowVec[i]<<' ';
    cout<<endl;
    cout<<"vec "<<bit<<": "<<endl;
    for(int i = 1; i < vec.size(); i++)
        cout<<vec[i]<<' ';
    cout<<endl;

    for(int i = 1; i < vec.size(); i++){//Se salta el 2
        for(int j = 0; j < rowVec.size(); j++){
            if( mod( rowVec[j], vec[i] ) == 0 )rowVec.erase( rowVec.begin()+j );
        }
    }

    for(int i = 1; i < rowVec.size(); i++)//vec = vec + rowVec
        vec.push_back(rowVec[i]);

    //vec = rowVec;
    return vec;
}
int main(){

    vector<ZZ>criba = cribaEratostenes(16);
    cout<<"Primos:\n";
    for(int i = 0; i < criba.size(); i++)
        cout<<criba[i]<<' ';


    return 0;
}
