//메모리: 2508KB, 시간: 20ms
/*
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
*/

//메모리: 2500KB, 시간: 16ms
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

//dp 배열: 현재 인덱스 위치의 디스크로부터 디스크 3개의 상태에서 anw까지 디스크를 돌리는 최소 횟수 저장 
int n, dp[104][10][10][10], cur[104], anw[104];
string tmp, tmp2;

int go(int idx, int a, int b, int c) {
    if (idx == n) return 0;
    if (anw[idx] == a) return go(idx + 1, b, c, cur[idx + 3]);
    int& ret = dp[idx][a][b][c];
    if (ret == INF) {
        for (int i = 1; i <= 3; i++) {
            ret = min(ret, go(idx, (a + i) % 10, b, c) + 1);
            ret = min(ret, go(idx, (a + 10 - i) % 10, b, c) + 1);
            ret = min(ret, go(idx, (a + i) % 10, (b + i) % 10, c) + 1);
            ret = min(ret, go(idx, (a + 10 - i) % 10, (b + 10 -i) % 10, c) + 1);
            ret = min(ret, go(idx, (a + i) % 10, (b + i) % 10, (c + i) % 10) + 1);
            ret = min(ret, go(idx, (a + 10 - i) % 10, (b + 10 - i) % 10, (c + 10 -i) % 10) + 1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&dp[0][0][0][0], &dp[0][0][0][0] + 104*1000, INF);
    cin >> n >> tmp >> tmp2;
    for (int i = 0; i < n; i++) {
        cur[i] = tmp[i] - '0'; anw[i] = tmp2[i] - '0';
    }
    cout << go(0, cur[0], cur[1], cur[2]) << '\n';
    return 0;
}