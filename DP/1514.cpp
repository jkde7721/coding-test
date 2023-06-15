//메모리: 2508KB, 시간: 20ms
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

//dp 배열: 해당 인덱스 직전까지는 비밀번호 맞춤, 해당 인덱스 기준 3개까지의 자물쇠 상태, 이후 자물쇠는 건드리지 않은 상태
int n, dir[] = {1, 2, 3, -1, -2, -3}, dp[100][10][10][10];
string pwd, start;

char rotate(int num, int diff) {
    num += diff;
    if (num < 0) num += 10;
    else if (num > 9) num -= 10;
    return num;
}

int go(int idx, int f, int s, int t) {
    for (int i = idx; i < n; i++) {
        if (f == (pwd[i] - '0')) {
            idx++;
            f = s; s = t; t = (idx + 2 < n ? start[idx + 2] - '0' : 0);
        }
        else break;
    }
    if (idx == n) return 0;
    int& ret = dp[idx][f][s][t];
    if (ret == INF) {
        for (int i = 0; i < 6; i++) {
            ret = min(ret, go(idx, rotate(f, dir[i]), s, t) + 1);
            if (idx + 1 < n) ret = min(ret, go(idx, rotate(f, dir[i]), rotate(s, dir[i]), t) + 1);
            if (idx + 2 < n) ret = min(ret, go(idx, rotate(f, dir[i]), rotate(s, dir[i]), rotate(t, dir[i])) + 1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> start >> pwd;
    fill(&dp[0][0][0][0], &dp[0][0][0][0] + 100000, INF);
    cout << go(0, start[0] - '0', (n > 1 ? start[1] - '0' : 0), (n > 2 ? start[2] - '0' : 0)) << '\n';

    return 0;
}