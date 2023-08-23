#include <iostream>
#include <vector>
#include "../utilities.h"
using namespace std;

#define cubo vector<vector<int>>
//Punto a) Se generan (n^2)^(n^2) cubos
int N,RES=0;cubo C;

void force_brute(cubo& C,int i,int j){
	if(i==N){ impMatriz(C);cout<<"=============="<<RES;if(esMagico(C)) RES++;return;}
	else{
		int sig_j = j==N-1 ? 0 : j+1;
		int sig_i = sig_j==0 ? i+1 : i;
		forr(k,1,N*N+1){ 
			C[i][j]=k;
			force_brute(C,sig_i,sig_j);
		}
		return;
	}
}


int main(){
	cin >> N; //vector<bool> usados(n*n+1,false);
	C.rz(N,vector<int>(N,0));
	force_brute(C,0,0);
	cout<< RES <<"\n";
	return 0;
}
