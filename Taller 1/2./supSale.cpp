#include "utilities.h"
#define pii pair<int,int>
#define precio first
#define peso second
int t,n,g;vector<pii> producto;vector<int> amigo;



int main(){
	cin >> t;
	forn(i,t){
		cin >> n; producto.rz(n);
		forn(j,n) cin >> producto[j].precio;
		forn(j,n) cin >> producto[j].peso;
		cin >> g; amigo.rz(g);
		forn(j,g) cin >> amigo[j];
		solve();
	}
}
