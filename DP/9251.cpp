//�޸�: 5932KB, �ð�: 12ms �� bottom-up Ǯ�̵� ����
//LCS(Longest Common Subsequence, ���� ���� �κ� ����)
#include <bits/stdc++.h>
using namespace std;

//dp �迭: �ش� �ε����κ����� ù��° ���ڿ�, �ش� �ε����κ����� �ι�° ���ڿ� �� LCS ���� ����
int dp[1000][1000];
string s1, s2;

int go(int idx1, int idx2) {
    if (idx1 >= s1.size() || idx2 >= s2.size()) return 0;
    int& ret = dp[idx1][idx2];
    if (ret == -1) {
        ret = go(idx1 + 1, idx2);
        if (s1[idx1] == s2[idx2]) ret = max(ret, go(idx1 + 1, idx2 + 1) + 1);
        else ret = max(ret, go(idx1, idx2 + 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> s1 >> s2;
    cout << go(0, 0) << '\n';
    return 0;
}