//�޸�: 8740KB, �ð�: 96ms
#include <iostream>
#include <cstring>
using namespace std;

int n, m, c, w[13], dp[10][21][1 << 13];

//������� steal ���·� ������ ��ġ�� �ش� ���濡 cap�� �뷮�� ���� ���¿��� ������ ��ĥ �� �ִ� �ִ� ���� ���� ��ȯ
int go(int idx, int cap, int steal) {
    if (idx == m) return 0;
    int& ret = dp[idx][cap][steal];
    if (ret == -1) {
        //���� �ش� ���濡 ������ �ƿ� ��ġ�� �ʰų� n���� ���� �� �ϳ��� ��ġ�ų�
        ret = max(ret, go(idx + 1, c, steal));
        for (int i = 0; i < n; i++) {
            if ((1 << i) & steal || cap < w[i]) continue; //�̹� ��ģ ���� or �뷮 ����
            ret = max(ret, go(idx, cap - w[i], (1 << i) | steal) + 1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) cin >> w[i];
    memset(dp, -1, sizeof(dp));
    cout << go(0, c, 0) << '\n';

    return 0;
}