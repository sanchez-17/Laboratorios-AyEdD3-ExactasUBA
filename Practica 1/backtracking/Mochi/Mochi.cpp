#include <iostream>
#include <vector>
#define forr(i,a,b) for(int i= (int)a;i<(int)b;i++)
#define forn(i,n) forr(i,0,n)
#define mp make_pair
#define fst first
#define snd second
using namespace std;
typedef pair<int,int> ii;

int INF = 1e9;

int N,P;
vector<ii> p;

int Mochi(int i,int P){
    if(i==N) return (P<0?-INF:0);
    else return max( Mochi(i+1,P - p[i].fst) + p[i].snd , Mochi(i+1,P) );
}

int main(){
    cin >> N >> P;
    p.resize(N,mp(-1,-1));
    forn(i,N) cin >> p[i].fst >> p[i].snd;

    cout << Mochi(0,P);
}
