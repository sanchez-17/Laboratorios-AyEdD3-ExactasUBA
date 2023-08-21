#ifndef UTILITIES
#define UTILITIES

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
#define forr(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define forn(i,n) forr(i,0,n)

template<class T>
void impMatriz(vector<vector<T>>& M){
	int n = M.size();int m = M[0].size();
	forn(i,n)
	{ 
		cout << "\n";
		forn(j,m) cout << M[i][j] << " ";
	}
	cout << "\n";
}
template<class T>
void impVector(vector<T>& V){
	int n = V.size();
	//cout << "\n";
	forn(i,n) cout<<V[i]<<" ";
	cout << "\n";
}

#endif
