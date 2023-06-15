#include <iostream>
#include <vector>
using namespace std;

vector<int> adj[50];
int n, tmp, num, ret;
bool visited[50];

void dfs(int node) {
    visited[node] = 1;
    for (int sub : adj[node]) {
        if (visited[sub]) continue;
        dfs(sub);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp != -1) {
            adj[tmp].push_back(i);
        }
    }
    cin >> num;
    dfs(num);

    for (int i = 0; i < n; i++) {
        if (visited[i] || adj[i].size() > 1) continue;
        if (adj[i].size() == 1 && adj[i].back() != num) continue;
        ret++;
    }
    cout << ret << '\n';

    return 0;
}