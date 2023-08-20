#include <iostream>
#include <vector>
using namespace std;
#define forr(i,a,b) for(int i=(int)a;i<(int)b;i++)
#define forn(i,n) forr(i,0,n)
#define rz resize
#define sz size
#define pb push_back
#define ppb pop_back

//Punto f)
//Segun la guia los indices empiezan en 1. Tuve que modificar el codigo teniendo
//esto en cuenta
bool subset_sum(int C[],int i, int S){
	if(i==-1) return S==0;
	else      return subset_sum(C,i-1,S) || subset_sum(C,i-1,S-C[i]); 
}
//Punto h)
//Regla de factibilidad: la sumatoria de los elementos restantes no superan
//la suma a alcanzar
bool subset_sum_h(int C[],int i, int S){
	if(S<0)   return false;
	if(i==-1) return S==0;
	else      return subset_sum(C,i-1,S) || subset_sum(C,i-1,S-C[i]); 
}

//Punto j)
//Añadimos un vector p de soluciones parciales, que se imprime en pantalla
//si llega a ser solucion valida del problema.
bool subset_sum_h(int C[],int i, int S,vector<int>& p){
	if(S<0) return false;
	if(i==-1){
		if(S==0){
			forn(j,p.sz()) cout<<p[j]<<",";
			cout << "\n";
			return true;
		}else return false;
	}
	else{
		 bool a = subset_sum_h(C,i-1,S,p);
		 p.pb(C[i]);
		 bool b= subset_sum_h(C,i-1,S-C[i],p);
		 p.ppb();
		 return a || b; 
	}
}

int main(){
	int N,S;cin >> N >> S;
	int C[N];vector<int> p;
	forn(i,N) cin >> C[i]; 
	cout <<subset_sum_h(C,N-1,S,p) << "\n";
}
