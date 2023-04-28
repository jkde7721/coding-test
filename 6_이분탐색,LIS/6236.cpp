//메모리: 2412KB, 시간: 16ms
//문제 조건 추가: 하루에 최대 1번만 인출 가능
#include <bits/stdc++.h>
using namespace std;

int n, m, mon[100000], l, r, mid, ret = 1000000000;

bool check(int k) {
    int tmp = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        tmp += mon[i];
        if (tmp > k) { cnt++; tmp = mon[i]; }
    }
    return cnt <= m;
}

//최소 인출 금액=최대 지출 금액, 최대 인출 금액=모든 지출 금액의 합
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mon[i];
        l = max(l, mon[i]);
        r += mon[i];
    }
    //지출 금액을 이분 탐색 (최대 30번 루프)
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ret = min(ret, mid);
        }
        else l = mid + 1;
    }
    cout << ret << '\n';

    return 0;
}