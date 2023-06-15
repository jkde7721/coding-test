//메모리: 19864KB, 시간: 28ms
#include <iostream>
#define INF 987654321
using namespace std;

int num[100001], dp[5][5][100001], tmp, n;
int weight[5][5] = {{0, 2, 2, 2, 2}, {0, 1, 3, 4, 3}, {0, 3, 1, 3, 4}, 
    {0, 4, 3, 1, 3}, {0, 3, 4, 3, 1}};

int go(int l, int r, int idx) {
    if (idx && l == r) return INF;
    if (idx == n) return 0;
    int& ret = dp[l][r][idx];
    if (!ret) {
        ret = INF;
        ret = min(ret, go(num[idx], r, idx + 1) + weight[l][num[idx]]); //왼발 움직임
        ret = min(ret, go(l, num[idx], idx + 1) + weight[r][num[idx]]); //오른발 움직임
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while ((cin >> tmp) && tmp != 0) num[n++] = tmp;
    cout << go(0, 0, 0) << '\n';

    return 0;
}