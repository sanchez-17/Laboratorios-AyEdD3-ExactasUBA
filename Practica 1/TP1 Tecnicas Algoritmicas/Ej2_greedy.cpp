#include <iostream>
#include <algorithm>
#include "../backtracking/utilities.h"
#define ll unsigned long long
#define pll pair<ll,ll>
#define fst first
#define snd second
using namespace std;
int N;
vector<vector<ll>> M;
vector<pll> info;
ll MOD = 1e9 + 7;
ll SUM_MIN=1e10;

void fg(){
	ll d = 0;
	ll t = 0; 
	forn(i,N){
		t += info[i].snd;
		d = d % MOD +  info[i].fst * t % MOD; 
	}
	SUM_MIN = d;
}

void f(vector<bool>& usados,ll descGral,ll tiempo,int cnt){
    if(cnt==N) SUM_MIN = descGral < SUM_MIN ? descGral : SUM_MIN;
    else{
        forn(i,N) if(!usados[i]){
            usados[i] = true;
            ll tiempoActual =  tiempo+M[0][i];
            f(usados, descGral +  tiempoActual * M[1][i],tiempoActual, cnt+1);
            usados[i] = false;
        }
    }
}

void solve(){
    vector<bool> usados(N,false);
    fg();
    cout<<SUM_MIN <<"\n";
}

int main(){
	vector<int> tiempo;
	vector<int> factor;
    int m;cin>>m;
    forn(i,m) {
        cin >> N;
        //M.clear(); M.rz(2,vector<ll>(N));
        info.rz(N);tiempo.rz(N);factor.rz(N);
        //forn(j,2) forn(k,N) cin >> M[j][k];
        forn(j,N) cin >> tiempo[j];
		forn(j,N){
			cin >> factor[j];
			info[j] = { factor[j],tiempo[j] };
			 
		}
        //impMatriz(M);
        //solve();
        sort(info.begin(),info.end());
        solve();
        SUM_MIN = 1e10;
    }

    return 0;
}
