#include <bits/stdc++.h>
using namespace std;

//(���� �迭�� ���� LIS ���� + ������ �迭�� ���� LIS ����)�� �ִ�
int n, a[1000], b[1000], dp[1000], dp2[1000], ret;

void lis(int num[], int len[]) {
    for (int i = 0; i < n; i++) {
        len[i] = 1;
        for (int j = 0; j < i; j++) {
            if (num[i] > num[j]) len[i] = max(len[i], len[j] + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) { cin >> a[i]; b[n-1-i] = a[i]; }
    lis(a, dp); lis(b, dp2);
    for (int i = 0; i < n; i++) {
        ret = max(ret, dp[i] + dp2[n-1-i] - 1);
    }
    cout << ret << '\n';
    return 0;
}