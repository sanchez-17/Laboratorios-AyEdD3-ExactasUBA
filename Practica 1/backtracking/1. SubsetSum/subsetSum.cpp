#include <iostream>
#include <vector>
using namespace std;
#define forr(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define forn(i,n) forr(i,0,n)
#define rz resize

//Punto f)
//Segun la guia los indices empiezan en 1. Tuve que modificar el codigo teniendo
//esto en cuenta
bool subset_sum(int C[],int i, int S){
	if(i==0) return S-C[i]==0;
	else     return subset_sum(C,i-1,S) || subset_sum(C,i-1,S-C[i]); 
}

int main(){
	int N,S;cin >> N >> S;
	int C[N];
	forn(i,N) cin >> C[i]; 
	cout << subset_sum(C,N-1,S) << "\n";
}
