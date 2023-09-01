#include "../utilities.h"
int t,n;vector<int> precio;vector<bool> usado;int INF = 1e7;

int f(vector<bool>& usado, int elem, int cnt, int min){
	if (cnt == 3){ //DBG3("3 elem",min, elem);RAYA; 
			min =  elem < min  ? elem : min;
			return min + f( usado, elem, 0, min);
	}
	else{
		int maxDesc  = 0;
		forn(i,n) if(!usado[i]){
			usado[i] = true;
			min = precio[i] < min  ? precio[i] : min;
			int descActual = f( usado, precio[i], cnt+1, min);
			maxDesc = maxDesc < descActual ? descActual : maxDesc;
			usado[i] = false;
		}
		//DBG(maxDesc);RAYA;
		return maxDesc;
	}
}

void greedy(vector<int> precio){
	sort( all(precio));
	int res = 0;
	for(int i = n-3; i >= 0; i-=3) res += precio[i];
	cout << res;
}

int main(){
	cin >> t;
	forn(i,t){
		cin >> n;precio.rz(n);usado.rz(n, false);
		forn(j,n) cin >> precio[j];
		//cout << f(usado, 0, 0, INF);
		greedy(precio);
	}
	return 0;
}
