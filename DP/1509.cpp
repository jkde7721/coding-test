//�޸�: 8144KB, �ð�: 24ms
//Bottom-Up, Top-Down ��� DP (�׸����ϰ� Ǯ�� �ȵ�)
#include <bits/stdc++.h>
#define MAX 2501
using namespace std;

//dp �迭: �ش� �ε��� ������ �Ӹ�������� ���� ����
//cnt �迭: �ش� �ε����κ��� �� ������ �ε��������� �ּ� �Ӹ���� ���� ���� ����
int s, e, idx, n, cnt[MAX];
bool dp[MAX][MAX];
char ch;
string str;

int go(int idx) {
    if (idx == n) return 0;
    int& ret = cnt[idx];
    if (ret == MAX) {
        for (int i = idx; i < n; i++) {
            if (!dp[idx][i]) continue;
            ret = min(ret, go(i + 1) + 1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str; n = str.size();
    for (int i = 0; i < n; i++) dp[i][i] = 1;
    s = e = idx = 0; ch = str[0];
    while (idx < n) {
        if (e+1 < n && str[e+1] == ch) dp[s][++e] = 1;
        else if (s-1 >= 0 && e+1 < n && str[s-1] == str[e+1]) {
            dp[--s][++e] = 1; ch = 'a';
        }
        else { s = e = ++idx; ch = str[idx]; }
    }
    fill(cnt, cnt + MAX, MAX);
    cout << go(0) << '\n';
    return 0;
}