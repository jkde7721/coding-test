//�޸�: 28456KB, �ð�: 88ms
//2^2500�� �ð����⵵�� ��Ž Ǯ�̵� ����, but �ð��ʰ� �߻� �� DP Ǯ��
#include <bits/stdc++.h>
#define MOD 1000007;
using namespace std;

const int dy[] = {0, -1}, dx[] = {-1, 0};
//dp �迭: �ش� y, x ��ġ�� �����ϱ���� �ش� Ƚ����ŭ �ش� ��ȣ ���� �۰ų� ���� �������� �湮�ϴ� ����� ���� ���� (y, x ��ġ�� ������ ����)
int n, m, c, city[51][51], y, x, dp[51][51][51][51];

int go(int y, int x, int cnt, int num) {
    if (cnt < 0 || city[y][x] > num) return 0;
    int& ret = dp[y][x][cnt][num];
    if (ret == -1) {
        int ny, nx; ret = 0;
        for (int i = 0; i < 2; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 1 || nx < 1) continue;
            ret += go(ny, nx, cnt - (city[y][x] > 0), (city[y][x] > 0 ? city[y][x] : num));
            ret %= MOD;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        cin >> y >> x;
        city[y][x] = i;
    }
    memset(dp, -1, sizeof(dp)); 
    for (int i = 0; i < 51; i++) dp[1][1][(city[1][1] > 0)][i] = 1;
    for (int i = 0; i <= c; i++) {
        cout << go(n, m, i, c) << ' ';
    }

    return 0;
}