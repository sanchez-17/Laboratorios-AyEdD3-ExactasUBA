#include <iostream>
#include <vector>
#include "../utilities.h"
using namespace std;
#define rz resize
#define forr(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define forn(i,n) forr(i,0,n)
#define matriz vector<vector<int>>
matriz D;
//La permutacion que extiende a I, usando todos los elementos de 1 a n, y
//que la sumatoria S(ver apunte) sea minima.
void minSuma(matriz& M,int idx, vector<bool>& usado){
	
}

int main(){
	int n;cin >> n;D.rz(n,vector<int>(n));
	forn(i,n) forn(j,n) cin >> D[i][j];
	//Genero lista de numeros de 1 a n inclusive
	vector<int> number(n+1); forn(i,n+1) number[i] = i;
	impMatriz(D);
	impVector(number);
	return 0;
}
