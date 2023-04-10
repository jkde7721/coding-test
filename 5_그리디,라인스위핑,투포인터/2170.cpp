//메모리: 9840KB, 시간: 356ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, x, y, ret, len;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    x = v[0].first; y = v[0].second; len = y - x;
    for (int i = 1; i < n; i++) {
        if (y <= v[i].first) {
            ret += len;
            x = v[i].first; y = v[i].second;
            len = y - x;
        }
        else if (y < v[i].second) { 
            y = v[i].second; 
            len = y - x; 
        }
    }
    ret += len;
    cout << ret << '\n';

    return 0;
}