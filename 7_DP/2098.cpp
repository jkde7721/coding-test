//�޸�: 6116KB, �ð�: 28ms
/*
�׳� ����Ž������ Ǯ�� �ð����⵵ (N - 1)!(N�� ������ ���� 2�̻� 16����)���� �ð��ʰ� �߻�
Top-Down DP�� �޸������̼� �ʿ� 
�� ����� �湮���� �� ���� ��ġ���� ������(������ �����)���� ���� �ּ� ��� ����
�̶� ������� 0�� ���÷� ���� �� ��ȸ�̱� ������ ����� ���X ex. 0 �� 1 �� 2 �� 0 / 2 �� 0 �� 1 �� 2 ��� same
*/
#include <bits/stdc++.h>
#define INF 987654321
#define MAX_N 16
using namespace std;

int n, w[MAX_N][MAX_N], cost[MAX_N][(1 << MAX_N)];

//cur �� 0�� ����(�����)���� ��ȸ�ϴµ� ��� �ּ� ��� ��ȯ
int go(int cur, int visited) {
    if (visited == ((1 << n) - 1)) { //��� �湮
        //�� ���������� �湮�� ���ÿ��� 0�� ���÷� �̵������ؾ� ��ȸ ����
        return (w[cur][0] ? w[cur][0] : INF);
    }
    int &ret = cost[cur][visited];
    if (ret == -1) {
        ret = INF;
        for (int i = 0; i < n; i++) {
            if (!w[cur][i] || visited & (1 << i)) continue;
            ret = min(ret, go(i, visited | (1 << i)) + w[cur][i]);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(cost, -1, sizeof(cost));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> w[i][j];
    }
    cout << go(0, 1) << '\n';

    return 0;
}