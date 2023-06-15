//메모리: 5712KB, 시간: 48ms
#include <iostream>
#include <vector>
using namespace std;

int n, ret, tmp, s, e;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<bool> num(n + 1);
    //에라토스테네스의 체
    num[0] = num[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (num[i]) continue;
        for (tmp = i + i; tmp <= n; tmp += i) num[tmp] = 1;
    }
    for (int i = 2; i <= n; i++) {
        if (!num[i]) v.push_back(i);
    }

    s = e = 0; tmp = 2;
    while (e < v.size()) {
        if (tmp > n) { tmp -= v[s++]; continue; }
        if (tmp == n) ret++;
        if (++e < v.size()) tmp += v[e];
    }
    cout << ret << '\n';

    return 0;
}