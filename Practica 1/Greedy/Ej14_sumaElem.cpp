#include "../backtracking/utilities.h"
#include <algorithm>
int N;vector<int> numbers;
//Estrategia greedy: Ordenar de menor a mayor y empezar a sumar
void solve(){
	int sum = 0;
	int costo = 0;
	for(int n:numbers){
		sum += n;
		costo += sum;
	}
	cout<<costo<<endl;
	
}

//C={1,2,5} => 1 + (1+2) + (3+5) = 12
//C={3,5,1} => 3 + (3+5) + (8+1) = 20

int main(){
	cin>>N;numbers.rz(N);
	forn(i,N) cin >> numbers[i];
	sort(numbers.begin(),numbers.end());
	solve();
	return 0;
}
