//메모리: 2412KB, 시간: 16ms
#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, ret = 2000000000, a[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    while (e < n) {
        if (a[e] - a[s] >= m) {
            ret = min(ret, a[e] - a[s]);
            if (s == e) e++; //"같은 수일 수도 있다."
            else s++; //s가 e를 추월하지 못하도록 
        }
        else e++;
    }
    cout << ret << '\n';
    return 0;
}