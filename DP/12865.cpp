//메모리: 2412KB, 시간: 8ms
//물건을 한번만 넣을 수 있기 때문에 일반적인 DP 풀이(Top-Down 방식)는 불가
#include <bits/stdc++.h>
using namespace std;

int n, k, w, v, val[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        for (int j = k; j >= w; j--) {
            val[j] = max(val[j], val[j - w] + v);
        }
    }
    cout << val[k] << '\n';

    return 0;
}