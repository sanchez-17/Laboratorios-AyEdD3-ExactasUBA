#include "../../../utilities.h"
int N,L,INF = 1e7;
vector<int> C; vector<bool> usado; vector<vector<int>> memo;

bool noHayMasCortes(int i, int j){
    forn(k, N) if(!usado[k] && i<C[k] && C[k]<j) return false;
    return true;
}   

int s(int i,int j){
	if (memo[i][j] != -1) return memo[i][j];
	else {
		if(noHayMasCortes(i,j))return 0; /*{cout << "Caso Base:";DBG(usado);*/
		else {
			//DBG(usado);
			int min_coste = INF;
			//Falta chequear que los cortes k esten dentro del reango de i,j
			forn(k,N) if(!usado[k] && i<C[k] && C[k]<j){
				usado[k]=true;
				int coste_k = s(i,C[k]) + s(C[k],j);
				min_coste = min(coste_k, min_coste);
				//DBG4(i,j,C[k],coste_k);
				usado[k]=false;
			}
			//DBGY(cnt);DBG(min_coste);RAYA;
			// if (min_coste >= INF) return j-i;
			int res = (j-i) + min_coste;
			memo[i][j] = res;
			return res;
		}
	}
}

int main(){
	cin >> N >> L; C.rz(N); usado.rz(N,false); memo.rz(L+1, vector<int>(L+1, -1));
	forn(i,N) cin >> C[i];
	cout << s(0,L) << endl;
	return 0;
	
}
