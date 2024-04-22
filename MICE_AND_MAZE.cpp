#include <bits/stdc++.h>
using namespace std;

// since the constraint is only 100 so you can choose each vertex and 
const int MAX = 1e2 + 7;
const int inf = 1e9;
vector<pair<int, int>> adj[MAX];
vector<int> d;
vector<bool> visited;
int n, e, T, m, a, b, c;

void dijkstra(int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    d.assign(n+1, inf);

    d[s] = 0;
    pq.push({0, s}); 

    while (!pq.empty()) {
        int v = pq.top().second; 
        pq.pop();

        for (auto e : adj[v]) {
            int to = e.first;
            int len = e.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                pq.push({d[to], to});
            }
        }
    }
}

void solve() {
    cin >> n >> e >> T >> m;

    for (int i = 1; i <= m ; i++){
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }

    int ans = 0;

    for (int i = 1; i <= n; i++){
        dijkstra(i);
        ans += (d[e] == inf || d[e] > T ? 0 : 1);
    }

    cout << ans << endl;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // #ifndef ONLINE_JUDGE
    //     freopen("input.txt", "r", stdin);
    //     freopen("output.txt", "w", stdout);
    // #endif

    int t = 1;// cin >> t;
    while(t--) solve();
    return 0;
}
