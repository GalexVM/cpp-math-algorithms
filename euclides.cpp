#include<iostream>
using std::cout;
using std::cin;
using std::endl;

int euclides(int r1, int r2);

int main(){
	int a = 24564;
	int b = 217;
	int mcd = euclides(a,b);
	cout<<mcd<<endl;
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
