#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> com[10001], ret;
int n, m, a, b, hack, mx;
bool visited[10001];

int dfs(int i, int h) {
    visited[i] = 1; h++;
    for (int j : com[i]) {
        if (visited[j]) continue;
        h = dfs(j, h);
    }
    return h;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        com[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
        memset(visited, 0, sizeof(visited));
        hack = dfs(i, 0);
        if (hack == mx) ret.push_back(i);
        else if (hack > mx) {
            ret.clear();
            ret.push_back(i);
            mx = hack;
        }
    }
    for (int i : ret) {
        cout << i << ' ';
    }

    return 0;
}