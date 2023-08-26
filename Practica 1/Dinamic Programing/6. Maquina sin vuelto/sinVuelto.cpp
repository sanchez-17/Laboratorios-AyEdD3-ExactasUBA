#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ii pair<int,int>
#define fst first
#define snd second
#define memory vector<vector<vector<ii>>>
#define sz(V) V.size()
#define rz resize
vector<int> B;
int N,sumaAPagar,INF=1e7;memory memo;
ii NULLT = {INF,INF};
ii cc_bt(int i,int sum,int cnt){
    if(i==N ) {
        sum = sum >= sumaAPagar ? abs( sumaAPagar - sum) : INF;
        return { sum,cnt};
    }
    else{
        return min(cc_bt(i+1,sum + B[i],cnt + 1),cc_bt(i+1,sum,cnt));
    }
}



ii cc_dp(int i,int sum,int cnt){
    if(i==N || sum <= 0) {
        sum = sum <=0 ? abs( sum) : INF;
        return { sum,cnt};
    }
    else{
        if (memo[i][sum][cnt] != NULLT) return  memo[i][sum][cnt];
        ii res = min(cc_dp(i+1,sum - B[i],cnt + 1),cc_dp(i+1,sum,cnt));
        memo[i][sum][cnt] = res;
        return res;
    }
}

int main() {
    cin >> N >> sumaAPagar; B.rz(N,-1);memo.rz(N+1,vector<vector<ii>>(sumaAPagar+1,vector<ii>(N+1,NULLT)));
    for(int i=0;i<N;i++) cin >> B[i];
    ii res = cc_dp(0,sumaAPagar,0);
    cout << "Cantidad de billetes: " << res.snd << endl;
    cout << "Exceso: " << res.fst << endl;
    return 0;
}

