//메모리: 3424KB, 시간: 4ms
//3번 조건은 최적해일 때 자동으로 만족 → 1, 2번 조건만 신경쓰면 됨
#include <bits/stdc++.h>
using namespace std;

//dp 배열: 현재 마을이 우수 마을이거나 아닐 때, 앞으로 우수 마을의 주민 수 총 합의 최대값 저장
int n, num[10001], a, b, dp[10001][2], ret;
vector<int> adj[10001];

int go(int idx, bool exc, int pre) {
    int& ret = dp[idx][exc];
    if (ret == -1) {
        ret = exc ? num[idx] : 0;
        for (int next : adj[idx]) {
            if (next == pre) continue; //이전에 방문한 노드는 다시 방문X
            if (exc) ret += go(next, 0, idx);
            else ret += max(go(next, 1, idx), go(next, 0, idx));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> num[i];
    for (int i = 1; i < n; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //1번 마을은 우수 마을이거나 아니거나
    cout << max(go(1, 1, 0), go(1, 0, 0)) << '\n';
    return 0;
}