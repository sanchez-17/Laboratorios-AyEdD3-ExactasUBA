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
//Variables globales
matriz M;int SUMA=1e7,N;vector<int> RES;
//En res guardare la permutacion que genera la min suma. En caso
//de haber mas de una permutacion posible, se queda con la primera.
//La permutacion que extiende a I, usando todos los elementos de 1 a n, y
//que la sumatoria S(ver apunte) sea minima.

void suma(vector<int>& I){
	int sum = 0;
	forn(i,N) sum += M[ I[i] ][ I[(i+1)%N] ];
	if(sum < SUMA){ SUMA = sum; RES = I;}
}


void minSuma(vector<bool>& usado,vector<int>& I){
	if(sz(I)==N){//Si ya tengo una permutacion de {1...N}
		suma(I);	
	}else{
		forn(i,N) if (!usado[i]){
				usado[i] = true; I.pb(i);
				minSuma(usado,I);
				usado[i] = false; I.ppb();
			}
		}
}

void solve(){
	vector<bool> usado(N,false);
	//Inicializo I como pi(i)=i. Para poder comenzar a comparar las sumas
	vector<int> I;
	minSuma(usado,I);
	cout << SUMA << "\n";
	impVector(RES);

}

int main(){
	cin >> N;M.rz(N,vector<int>(N));
	forn(i,N) forn(j,N) cin >> M[i][j];
	solve();
	return 0;
}
