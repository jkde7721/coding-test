//DP 풀이
#include <bits/stdc++.h>
using namespace std;

//dp 배열: 해당 인덱스 좌석부터 끝 좌석까지 앉을 수 있는 경우의 수 저장
int n, m, tmp, dp[41];
bool fix[41];

int go(int idx) {
    if (idx >= n) return 1;
    int& ret = dp[idx];
    if (ret == -1) {
        ret = 0;
        if (fix[idx]) ret += go(idx + 1);
        else if (!fix[idx + 1]) ret += go(idx + 2) + go(idx + 1); //자리 바꾼 경우의 수 + 안바꾼 경우의 수
        else ret += go(idx + 2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) { cin >> tmp; fix[tmp] = 1; }
    memset(dp, -1, sizeof(dp));
    cout << go(1) << '\n';

    return 0;
}

//이동가능한 연속된 좌석수에 따른 경우의 수가 피보나치 수열 형태 
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 1, pre, cur, cnt[41];

int fibo(int idx) {
    if (cnt[idx] != 0) return cnt[idx];
    cnt[idx] = fibo(idx - 2) + fibo(idx - 1);
    return cnt[idx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cnt[0] = cnt[1] = 1; fibo(40);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> cur;
        ret *= cnt[cur - pre - 1];
        pre = cur;
    }
    ret *= cnt[n - pre];
    cout << ret << '\n';
    
    return 0;
}
*/