#include "../../../utilities.h"
int N, M, INF = 1e7; vector<vector<int>> A;

int f(int i, int j){
	if(i == N-1 && j == M-1) return max(1, 1-A[i][j]);
	else if(i >= N || j >= M) return INF;
	else {
		return max(1, min(f(i+1,j), f(i,j+1)) - A[i][j] );
	}
}

int main(){
	fastio;//Linea fachera
	cin >> N >> M; A.rz(N, vector<int>(M));
	forn(i, N) forn(j, M) cin >> A[i][j];
	cout << f(0,0) << endl;
	return 0;
}
