//메모리: 2412KB, 시간: 12ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    cin >> x;
    sort(v.begin(), v.end());

    int s = 0, e = n - 1;
    while (s < e) {
        if (v[s] + v[e] > x) e--;
        else if (v[s] + v[e] < x) s++;
        else { ret++; s++; e--; }
    }
    cout << ret << '\n';

    return 0;
}