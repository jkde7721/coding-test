//메모리: 2020KB, 시간: 40ms
#include <bits/stdc++.h>
using namespace std;

int n, m, tmp, mdg, ret;
bool b[10];

void go(int num, int dg) {
    if (dg) ret = min(ret, abs(n - num) + dg);
    if (dg == mdg + 1) return; //한 자릿수 큰 것까지는 ok
    for (int i = 0; i <= 9; i++) {
        if (b[i]) continue;
        go(num * 10 + i, dg + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) { 
        cin >> tmp; b[tmp] = 1;
    }
    tmp = n;
    while (tmp) { tmp /= 10; mdg++; }
    ret = abs(n - 100); go(0, 0);
    cout << ret << '\n';
    return 0;
}