#include <iostream>
#include <vector>
#define forr(i,a,b) for(int i= (int)a;i<(int)b;i++)
#define forn(i,n) forr(i,0,n)
#define fori(i,a,b) for(int i=(int)a;i>=(int)b;i--)
#define fore(i,n) fori(i,n,0)
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef pair<int,int> ii;

int INF = 1e9;

int N,P;
vector<ii> p;
vector<int> pesoRestante;

int Mochi(int i,int P){
    if (P<0) return -INF;
    if(pesoRestante[i]<=P) return pesoRestante[i];
    else return max( Mochi(i+1,P - p[i].fst) + p[i].snd , Mochi(i+1,P) );
}

int main(){
    cin >> N >> P;
    p.resize(N,mp(-1,-1));
    pesoRestante.resize(N+1,0);
    forn(i,N) cin >> p[i].fst >> p[i].snd;
    fore(i,N-1) pesoRestante[i] = pesoRestante[i+1] + p[i].fst;
    cout << Mochi(0,P);
}


