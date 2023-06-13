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
        //x 인덱스의 값이 상대적으로 더 크고, y 인덱스의 값은 상대적으로 더 작음
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