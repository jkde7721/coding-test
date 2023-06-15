//메모리: 2020KB, 시간: 0ms
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    
    ret = v[0].first + v[0].second;
    for (int i = 1; i < n; i++) {
        if (v[i].first > ret) ret = v[i].first + v[i].second;
        else ret += v[i].second;
    }
    cout << ret << '\n';

    return 0;
}