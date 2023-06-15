//�޸�: 16408KB, �ð�: 216ms
//���� ���� ���: x�� �������� Ȯ���� �տ� ���� �ִ��� dfs (���� ���� �ݴ�) 
//���� ���� ���: x�� �������� Ȯ���� �ڿ� ���� �ִ��� dfs
/*
2 �� 1
3 �� 4 �� 1
=> ���� ���� ���: 4, ���� ���� ���: 5
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, x, a, b;
bool visited[100001], visited2[100001];
vector<int> adj[100001], adj2[100001];

int dfs(vector<int>* adj, int u, bool* visited) {
    int dep = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = 1;
            dep += dfs(adj, v, visited);
        }
    }
    return dep;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    cout << dfs(adj2, x, visited2) << ' ' << (n - dfs(adj, x, visited) + 1) << '\n';
    return 0;
}