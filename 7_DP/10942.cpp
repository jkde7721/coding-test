//메모리: 5944KB, 시간: 272ms
//Bottom-Up 방식 DP
#include <bits/stdc++.h>
#define MAX 2002
using namespace std;

int n, m, s, e, idx, num[MAX], sn; //same number
bool dp[MAX][MAX];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> num[i]; dp[i][i] = 1; }
    s = e = idx = 0; sn = num[0];
    while (idx < n) {
        if (e+1 < n && num[e+1] == sn) dp[s][++e] = 1;
        else if (s-1 >= 0 && e+1 < n && num[s-1] == num[e+1]) {
            dp[--s][++e] = 1; sn = 0; //같은 숫자 seq 종료
        }
        else { s = e = ++idx; sn = num[idx]; }
    }

    cin >> m;
    while (m--) {
        cin >> s >> e;
        cout << dp[--s][--e] << '\n';
    }
    return 0;
}