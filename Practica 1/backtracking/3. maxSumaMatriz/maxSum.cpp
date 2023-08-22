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
#define db(a,b) cout<<a<<b<<"-"
//Variables globales
matriz M;int SUMA=-1,N,K;vector<int> RES;

void validarSuma(vector<int>& I){
	int sum=0;
	forn(i,sz(I)) forn(j,sz(I)) sum+= M[I[i]][I[j]];
	if(sum>=SUMA)  {SUMA=sum;RES=I;}
}

void maxSum(int i,vector<int>& I){
	if(sz(I)==K || i==N) validarSuma(I);
	else{
		maxSum(i+1,I);
		I.pb(i);
		maxSum(i+1,I);
		I.ppb();
	}
}
void solve(){
	vector<int> I;
	maxSum(0,I);
}

int main(){
	cin >> N >> K;M.rz(N,vector<int>(N));
	forn(i,N) forn(j,N) cin >> M[i][j];
	solve();
	cout << SUMA << "\n";
	impVector(RES);
	return 0;
}
