#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, ret[100001];
bool visited[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        //x �ε����� ���� ��������� �� ũ��, y �ε����� ���� ��������� �� ����
        ret[x]++; ret[y]--;
    }
    for (int i = 1; i <= n; i++) {
        ret[i] += i;
        if (visited[ret[i]]) { cout << "-1\n"; return 0; }
        visited[ret[i]] = 1;
    }
    for (int i = 1; i <= n; i++) cout << ret[i] << ' ';

    return 0;
}