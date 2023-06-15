//메모리: 2032KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;

//p는 LIS 각 요소의 이전 값에 대한 인덱스
//c는 LIS의 가장 마지막 요소에 대한 인덱스
int n, a[1001], cnt[1001], pre[1001], ret, mx, p, c;
vector<int> lis;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        mx = 0; p = i;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && cnt[j] > mx) { mx = cnt[j]; p = j; }
        }
        cnt[i] = mx + 1; pre[i] = p;
        if (ret < cnt[i]) {
            c = i; ret = cnt[i];
        }
    }
    while (1) {
        lis.push_back(a[c]);
        if (c == pre[c]) break;
        c = pre[c];
    }
    cout << ret << '\n';
    for (int i = lis.size() - 1; i >= 0; i--) {
        cout << lis[i] << ' ';
    }

    return 0;
}