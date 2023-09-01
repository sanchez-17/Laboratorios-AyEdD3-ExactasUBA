#include "../../../utilities.h"
int N,L,INF = 1e7;
vector<int> C;vector<bool> usado;

bool noHayMasCortes(int i, int j){
    forr(k, i+1, j) if(!usado[k]) return false;
    return true;
}   

int s(int i,int j){
	if(noHayMasCortes(i,j)) {cout << "Caso Base:";DBG(usado);return 0;}
	else {
		DBG(usado);
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
		return (j-i) + min_coste;
	}
}

int main(){
	cin >> N >> L; C.rz(N);usado.rz(N,false);vector<int> I;
	forn(i,N) cin >> C[i];
	cout << s(0,L) << endl;
	return 0;
	
}
