//메모리: 2408KB, 시간: 4ms
/*
시간복잡도 2^30 → 완전탐색 불가
공간복잡도 10^9 → DP 불가
→ 'meet in the middle' 알고리즘: N이 클 때, N/2을 기반으로 완전탐색 2번 (시간복잡도 2^15 + 2^15)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, w[30], ret;
vector<int> v, v2; //각 경우 마다의 물건 무게의 합 저장

void dfs(int l, int r, vector<int> &v, int sum) {
    if (sum > c) return;
    if (l > r) { v.push_back(sum); return; }
    dfs(l + 1, r, v, sum + w[l]);
    dfs(l + 1, r, v, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> w[i];
    dfs(0, n / 2 - 1, v, 0);
    dfs(n / 2, n - 1, v2, 0);
    sort(v2.begin(), v2.end());

    for (int s : v) {
        if (c - s >= 0) ret += upper_bound(v2.begin(), v2.end(), c - s) - v2.begin();
    }
    cout << ret << '\n';
    return 0;
}