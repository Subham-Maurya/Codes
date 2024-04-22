#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
#define piii pair<int, pii>
#define ff first
#define ss second
const int MAX = 8;

int BFS(int i1, int j1, int i2, int j2){
    queue<piii> q;
    q.push({0, {i1, j1}});

    while(!q.empty()){
        int i  = q.front().ss.ff;
        int j = q.front().ss.ss;
        int moves = q.front().ff;
        q.pop();

        if (i == i2 && j == j2){
            return moves;
        }

        if (i+2 <= MAX){ // up
            if (j-1 >= 1) q.push({moves+1, {i+2, j-1}});
            if (j+1 <= MAX) q.push({moves+1, {i+2, j+1}});
        }

        if (i-2 >= 1){ // down
            if (j-1 >= 1) q.push({moves+1, {i-2, j-1}});
            if (j+1 <= MAX) q.push({moves+1, {i-2, j+1}});
        }

        if (j+2 <= MAX){ // left
            if (i-1 >= 1) q.push({moves+1, {i-1, j+2}});
            if (i+1 <= MAX) q.push({moves+1, {i+1, j+2}});
        }

        if (j-2 >= 1){ // right
            if (i-1 >= 1) q.push({moves+1, {i-1, j-2}});
            if (i+1 <= MAX) q.push({moves+1, {i+1, j-2}});
        }
    }
    return -1;
}

void solve() {
    int i1, i2, j1, j2;
    char a,b;
    cin >> a >> j1 >>  b >> j2;
    i1 = (a - 'a') + 1;
    i2 = (b - 'a') + 1;
    // cout << "Start" << endl;
    // cout << i1 << " " << j1 << endl;
    // cout << "Target" << endl;
    // cout << i2 << " " << j2 << endl;
    cout << BFS(i1, j1, i2, j2) << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int t = 1;  cin >> t;
    while(t--) solve();
    return 0;
}