#include "../backtracking/utilities.h"
#include <algorithm>
int N1,N2;vector<int> C1,C2;
//Estrategia greedy: Ordenar de menor a mayor y empezar a sumar
void solve(){
	int i=0,j=0;int res = 0;
	while(i<sz(C1) && j<sz(C2)){
		if( abs(C1[i]-C2[j]) <= 1) {res++;i++,j++;}
		else{
			if( C1[i] < C2[j] ) i++;
			else              j++;
		}
	}
	cout<<res<<endl;
}

int main(){
	cin>>N1>>N2;C1.rz(N1);C2.rz(N2);
	forn(i,N1) cin >> C1[i];
	forn(i,N2) cin >> C2[i];
	//Si no esta ordenado
	sort(C1.begin(),C1.end());
	sort(C2.begin(),C2.end());
	//<<<<<<<<<<<<<<<<<<<
	solve();
	return 0;
}
