//�޸�: 2508KB, �ð�: 20ms
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

//dp �迭: �ش� �ε��� ���������� ��й�ȣ ����, �ش� �ε��� ���� 3�������� �ڹ��� ����, ���� �ڹ���� �ǵ帮�� ���� ����
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