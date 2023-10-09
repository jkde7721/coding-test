#include <bits/stdc++.h>
using namespace std;

//각 공장에서 구매할 라면의 개수는 공장 1개에서 구매, 공장 2개에서 같이 구매, 공장 3개에서 같이 구매한 경우로 나뉨 → 각각을 그리디하게 매번 업데이트
int n, a[10000], _one, _two, one, two, cnt, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        _one = _two = 0;
        if (i - 1 >= 0 && one > 0) { //이전 공장에서 비용 3으로 구매한 라면이 있다면 현재 공장에서 같이 구매 (비용 5)
            cnt = min(one, a[i]);
            ret -= cnt * 3; ret += cnt * 5;
            a[i] -= cnt; _two = cnt;
        }
        if (i - 2 >= 0 && two > 0) { //이전 공장에서 비용 5로 구매한 라면이 있다면 현재 공장에서 같이 구매 (비용 7)
            cnt = min(two, a[i]);
            ret -= cnt * 5; ret += cnt * 7;
            a[i] -= cnt;
        }
        if (a[i] > 0) { ret += a[i] * 3; _one = a[i]; } //어쩔 수 없이 현재 공장에서 혼자 구매 (비용 3)
        one = _one; two = _two;
    }
    cout << ret << '\n';
    return 0;
}