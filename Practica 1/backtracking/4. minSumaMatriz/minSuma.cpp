#include <iostream>
#include <vector>
#include "../utilities.h"
using namespace std;
#define rz resize
#define sz(V) V.size()
#define pb push_back
#define ppb pop_back
#define forr(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define forn(i,n) forr(i,0,n)
#define matriz vector<vector<int>>
matriz D;int SUMA,N;vector<int> res;
//En res guardare la permutacion que genera la min suma. No anda =(
//La permutacion que extiende a I, usando todos los elementos de 1 a n, y
//que la sumatoria S(ver apunte) sea minima.

int suma(matriz& M,vector<int>& I){
	int sum = 0;
	forn(i,N) sum += M[ I[i] ][ I[(i+1)%N] ];
	return sum;
}


void minSuma(matriz& M, vector<bool>& usado,vector<int>& I){
	if(sz(M)==N){//Si ya tengo una permutacion de {1...N}
		int sum = suma(M,I);
		if(sum <= SUMA){
			SUMA = sum; res = I;
		}
	}else{
		forn(i,N) if (!usado[i]){
				usado[i] = true; I.pb(i);
				minSuma(M,usado,I);
				usado[i] = false; I.ppb();
			}
		}
}

void solve(matriz& M){
	vector<bool> usado(N,false);
	//usado[0] = true;
	//Inicializo I como pi(i)=i. Para poder comenzar a comparar las sumas
	vector<int> I; forn(i,N) I.pb(i); res = I;
	impVector(res);
	SUMA = suma(M,I); I.clear();
	minSuma(M,usado,I);
	cout << SUMA << "\n";
	impVector(res);

}

int main(){
	cin >> N;D.rz(N,vector<int>(N));
	forn(i,N) forn(j,N) cin >> D[i][j];
	solve(D);
	return 0;
}
