#include <iostream>
#include "../backtracking/utilities.h"
#define ll long long
using namespace std;
int N;vector<vector<ll>> M;ll MOD = 1e9 + 7;
ll SUM_MIN=1e9;

void f(vector<bool>& usados,ll descGral,ll tiempo,int cnt){
    if(cnt==N) SUM_MIN = descGral < SUM_MIN ? descGral : SUM_MIN;
    else{
        forn(i,N) if(!usados[i]){
            usados[i] = true;
            ll tiempoActual =  tiempo+M[0][i];
            f(usados, ( descGral % MOD +  (tiempoActual * M[1][i]) % MOD ) % MOD,tiempoActual, cnt+1);
            usados[i] = false;
        }
    }
}

void solve(){
    vector<bool> usados(N,false);
    f(usados,0,0,0);
    cout<<SUM_MIN<<"\n";
}

int main(){
    int m;cin>>m;
    forn(i,m) {
        cin >> N; M.clear(); M.rz(2,vector<ll>(N));
        forn(i,2) forn(j,N) cin >> M[i][j];
        impMatriz(M);
        solve();
        SUM_MIN = 1e9;
    }

    return 0;
}