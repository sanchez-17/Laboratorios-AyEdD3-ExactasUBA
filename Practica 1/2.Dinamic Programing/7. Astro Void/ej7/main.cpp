#include <iostream>
using namespace std;
#include <vector>

vector<int> P;
int N;
int INF = 1e7;
vector<vector<int>> memory;

int AV(int j,int c){
    if (c < 0 || c > j){
        return -INF;
    }
    else if (j == N){
        return 0;
    }
    else if (c > 0){
        if (memory[j][c] != INF){
            return memory[j][c];
        }
        else{
            int res = max(AV(j+1,c-1)+P[j], max(AV(j+1,c+1)-P[j], AV(j+1,c)));
            memory[j][c] = res;
            return res;
        }

    }
    else {
        if (memory[j][c] != INF){
            return memory[j][c];
        }
        else {
            int res = max(AV(j+1,c+1)-P[j], AV(j+1,c));
            memory[j][c] = res;
            return res;
        }

    }

}


int main() {
    cin >> N;
    memory.resize(N, vector<int>(N, INF));
    P.resize(N);
    for (int i = 0; i < N; i++){
        cin >> P[i];
    }
    cout << AV(0, 0);

    return 0;
}
