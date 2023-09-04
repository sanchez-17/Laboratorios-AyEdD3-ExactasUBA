#include "../../utilities.h"
#define pii pair<int,int>
#define precio first
#define peso second
int t,n,g;vector<pii> producto;vector<int> amigo;vector<vector<int>> memo;
int INF = 1e7;

int f(int i,int sum){
    if(i==n || sum < 0) return sum < 0 ? -INF : 0;
    if(memo[i][sum] != -1) return memo[i][sum];
    else{
        int res = max(f(i+1,sum - producto[i].peso ) + producto[i].precio, f(i+1, sum) );
        memo[i][sum] = res;
        return res;
    }
}

void solve(){
    int res = 0;
    forn(i,g) res += f( 0, amigo[i]);
    cout << res << endl;
}

int main(){
	cin >> t;
	forn(i,t){
		cin >> n; producto.rz(n); memo.rz(n,vector<int>(31, -1));
		forn(j,n) {
			cin >> producto[j].precio;
			cin >> producto[j].peso;
		}
		cin >> g; amigo.rz(g);
		forn(j,g) cin >> amigo[j];
		solve();
        producto.clear();amigo.clear();memo.clear();
	}
}
