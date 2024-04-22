#include <bits/stdc++.h>
using namespace std;

template<typename T> void display(vector<T>& arr) { for (const auto& element : arr) { cout << element << " "; } cout << endl; }
template<typename T> void displayFirst(vector<T>& arr) { for (const auto& element : arr) { cout << element.first << " "; } cout << endl; }
template<typename T> void displaySecond(vector<T>& arr) { for (const auto& element : arr) { cout << element.second << " "; } cout << endl; }
#define pii pair<int, int>
#define piii pair<int, pii>
#define x first
#define y second

#define MAX 1000005
vector<int> adj[MAX];
int visited[MAX];
int soldier[MAX];

/*

1. A particular city is guarded by atleast 1 guard.
2. check if a city already has a guard then it should not be in the range of any other guard

*/

bool BFS(int s, int d){
    queue<piii> q;
    q.push({0, {s, d}});

    while(!q.empty()){
        piii node = q.front();
        q.pop();

        if (node.y.y == 0) continue;

        int parent = node.x;
        int city = node.y.x;
        int strength = node.y.y;

        for (auto neighbour : adj[city]){
            if (neighbour == parent) continue;
            if (soldier[neighbour] != -1) return false;
            if (visited[neighbour] == 0){
                visited[neighbour] = 1;
                q.push({city, {neighbour, strength-1}});
            } 
        }
    }
    return true;
}

void solve() {
    int n,r,m, u,v, k, s;
    cin >> n >> r >> m;

    for (int i = 0; i <= n; i++){
        visited[i] = 0;
        adj[i].clear();
        soldier[i] = -1;
    }

    for (int i = 1; i <= r; i++){
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 1; i<= m; i++){
        cin >> k >> s;
        soldier[k] = s;
    }

    bool flag = true;

    for (int i= 1; i <= n; i++){
        if (soldier[i] != -1){
            int city = i;
            int strength = soldier[i];

            if (visited[i] == 0){
                visited[i] = 1;
                if (!BFS(city, strength)){
                    flag = false;
                    break;
                }
            }
            else {
                flag = false;
                break;
            }
        }
    }

    for (int i = 1; i<= n && flag; i++){
        if (visited[i] == 0){
            flag = false;
            break;
        }
    }

    if (flag) cout << "Yes\n";
    else cout << "No\n";
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int t = 1; cin >> t;
    while(t--) solve();
    return 0;
}