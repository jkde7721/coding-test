//메모리: 2536KB, 시간: 16ms
#include <bits/stdc++.h>
using namespace std;

typedef struct Part {
    int y, x, d1, d2;
} Part;

int n, A[20][20], y, x, d1, d2, pop[5], ret = 1e9;
bool visited[20][20], pre;
vector<Part> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> A[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int d1 = 1; j-d1 >= 0; d1++) {
                for (int d2 = 1; i+d1+d2 < n && j+d2 < n; d2++) v.push_back({i, j, d1, d2});
            }
        }
    }
    for (Part p : v) {
        memset(pop, 0, sizeof(pop));
        memset(visited, 0, sizeof(visited));
        y = p.y; x = p.x; d1 = p.d1; d2 = p.d2; pre = 0;
        for (int i = 0; i <= d1; i++) visited[y+i][x-i] = 1;
        for (int i = 0; i <= d2; i++) visited[y+i][x+i] = 1;
        for (int i = 0; i <= d2; i++) visited[y+d1+i][x-d1+i] = 1;
        for (int i = 0; i <= d1; i++) visited[y+d2+i][x+d2-i] = 1;
        for (int i = y + 1; i < y + d1 + d2; i++) {
            for (int j = 0; j < n; j++) {
                if (!pre && visited[i][j]) pre = 1;
                else if (pre && visited[i][j]) pre = 0;
                else if (pre) visited[i][j] = 1;
            }
        }
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (visited[r][c]) pop[4] += A[r][c];
                else if (r < y + d1 && c <= x) pop[0] += A[r][c];
                else if (r <= y + d2 && c > x) pop[1] += A[r][c];
                else if (r >= y + d1 && c < x - d1 + d2) pop[2] += A[r][c];
                else pop[3] += A[r][c];
            }
        }
        ret = min(ret, *max_element(pop, pop + 5) - *min_element(pop, pop + 5));
    }
    cout << ret << '\n';

    return 0;
}