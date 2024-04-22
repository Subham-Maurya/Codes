#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef pair<int , pii> piii;
#define ff first
#define ss second

const int MAXN = 1e2 + 10;
int dx[4] = {1, -1, 0, 0};   // 4 possible moves i.e up, down, right, left respectively
int dy[4] = {0, 0, 1, -1};

int N, M, matrix[MAXN][MAXN], visited[MAXN][MAXN];
int isValid(int x, int y) { return min(x, y) >= 1 && x <= N && y <= M; }

int main() {
    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; tc++) {
        int ans = 0;
        scanf("%d %d", &N, &M);
        priority_queue<piii, vector<piii>, greater<piii> > pq;

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                scanf("%d", &matrix[i][j]);
                visited[i][j] = 0;
                if (i == 1 || i == N || j == 1 || j == M) {
                    pq.push({matrix[i][j], {i, j}});
                }
            }
        }

        while (!pq.empty()) {
            int x = pq.top().ss.ff, y = pq.top().ss.ss, h = pq.top().ff;
            pq.pop();
            if (visited[x][y]) continue;
            
            visited[x][y] = 1;
            ans += h - matrix[x][y];
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (isValid(nx, ny) && !visited[nx][ny])
                    pq.push({max(h, matrix[nx][ny]), {nx, ny}});
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}