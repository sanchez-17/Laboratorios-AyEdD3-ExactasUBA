#include "../../../utilities.h"
#define peso first
#define soporte second
int N, INF = 1e7; vector<pii> cajas;vector<vector<int> > memo;

int f(int i, int soporteAct){
	if(memo[i][soporteAct] != -1 ) return memo[i][soporteAct];
	
	if(i==N ) return soporteAct < 0 ? -INF : 1;
	else{
		
		int res = max( f(i+1, soporteAct),
			1 + f(i+1, min(soporteAct, cajas[i].soporte) - cajas[i].peso ) );
		memo[i][soporteAct] = res;
		return res;
	}
}

int main(){
	fastio;
	cin >> N; cajas.rz(N); 
	forn(i,N){ 
		cin >> cajas[i].peso;
		cin >> cajas[i].soporte;
	}
	//Busco el mayor soporte posible para la estr de memoizacion
	int maxSoporte = -1;
	forn(i,N) maxSoporte = max(maxSoporte, cajas[i].soporte);
	memo.rz(N+1, vector<int>(maxSoporte + 1, -1));
	//
	cout << f(0,maxSoporte) << endl;
	return 0;
}
