//메모리: 2036KB, 시간: 0ms
//Top-Down 방식 풀이
/*
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;

//dp 배열: 해당 1차원 인덱스 값까지 만든 수가 해당 2차원 인덱스 값일 때 결과값을 만드는 경우의 수 저장
int n, m[100];
ll dp[100][21];

ll go(int idx, int num) {
    if (num < 0 || num > 20) return 0;
    if (idx == n - 2) {
        if (num == m[n - 1]) return 1;
        return 0;
    }
    ll& ret = dp[idx][num];
    if (ret == -1) {
        ret = 0;
        ret += go(idx + 1, num + m[idx + 1]); 
        ret += go(idx + 1, num + -1 * m[idx + 1]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> m[i];
    memset(dp, -1, sizeof(dp));
    cout << go(0, m[0]) << '\n';

    return 0;
}
*/

//Bottom-Up 방식 풀이
#include <iostream>
using namespace std;
typedef long long ll;

//dp 배열: 해당 인덱스에서 해당 수를 만드는 경우의 수 저장
int n, num[100];
ll dp[100][21];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];

    dp[0][num[0]] = 1;
    for (int i = 1; i < n - 1; i++) {
        for (int j = 0; j <= 20; j++) {
            if (j + num[i] <= 20) {
                dp[i][j + num[i]] += dp[i - 1][j];
            }
            if (j - num[i] >= 0) {
                dp[i][j - num[i]] += dp[i - 1][j];
            }
        }
    }
    cout << dp[n - 2][num[n - 1]] << '\n';

    return 0;
}