//메모리: 8296KB, 시간: 620ms
#include <bits/stdc++.h>
using namespace std;

int t, n, m, tmp;

bool bs(const vector<int>& v, int num) {
    int l = 0, r = v.size() - 1, c;
    while (l <= r) {
        c = (l + r) / 2;
        if (v[c] == num) return 1;
        else if (v[c] > num) r = c - 1;
        else l = c + 1;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        vector<int> v;
        cin >> n;
        for (int i = 0; i < n; i++) { cin >> tmp; v.push_back(tmp); }
        sort(v.begin(), v.end());
        cin >> m;
        for (int i = 0; i < m; i++) { 
            cin >> tmp;
            cout << bs(v, tmp) << '\n';
        }
    }

    return 0;
}