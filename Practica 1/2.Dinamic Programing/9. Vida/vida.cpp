#include "../../../utilities.h"
int N, M, INF = 1e7; vector<vector<int>> A, memo;

int f(int i, int j){
	if(i == N-1 && j == M-1)   return max(1, 1-A[i][j]);
	if(i >= N || j >= M)       return INF;
	else {
		if (memo[i][j] != INF) return memo[i][j];
		int res = max(1, min(f(i+1,j), f(i,j+1)) - A[i][j] );
		memo[i][j] = res;
		return res;
	}
}

int main(){
	fastio;//Linea fachera
	cin >> N >> M; A.rz(N, vector<int>(M)); memo.rz(N, vector<int>(M, INF));
	forn(i, N) forn(j, M) cin >> A[i][j];
	cout << f(0,0) << endl;
	return 0;
}
