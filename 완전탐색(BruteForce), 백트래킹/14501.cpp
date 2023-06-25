#include <bits/stdc++.h>
#define MIN -1e9
using namespace std;

int n, t[15], p[15];

int dfs(int idx) {
    if (idx == n) return 0;
    if (idx > n) return MIN;
    //상담을 하거나 하지 않거나
    return max(dfs(idx + t[idx]) + p[idx], dfs(idx + 1));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t[i] >> p[i];
    cout << dfs(0) << '\n';
    return 0;
}