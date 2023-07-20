//N이 크므로 O(NlogN) 알고리즘 사용
//메모리: 5928KB, 시간: 160ms
#include <bits/stdc++.h>
using namespace std;

int n, tmp, lis[1000000], len;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        auto pos = lower_bound(lis, lis + len, tmp);
        if (*pos == 0) len++;
        *pos = tmp;
    }
    cout << len << '\n';
    return 0;
}