#include <bits/stdc++.h>
using namespace std;

int t, k, n1, n2, dir, ret;
string wh[1001];
vector<pair<int, int>> ro;

void rotateWh(int n, int d) {
    if (d == 1) rotate(wh[n].begin(), wh[n].end() - 1, wh[n].end());
    else rotate(wh[n].begin(), wh[n].begin() + 1, wh[n].end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    for (int i = 1; i <= t; i++) cin >> wh[i];
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n1 >> dir; n2 = n1;
        ro.push_back({n1, dir});
        while (n1 > 0 || n2 <= t) {
            n1--; n2++; dir *= -1;
            if (n1 > 0 && wh[n1][2] != wh[n1+1][6]) ro.push_back({n1, dir});
            else n1 = 0;
            if (n2 <= t && wh[n2][6] != wh[n2-1][2]) ro.push_back({n2, dir});
            else n2 = t + 1;
        }
        for (int i = ro.size() - 1; i >= 0; i--) {
            rotateWh(ro[i].first, ro[i].second);
            ro.pop_back();
        }
    }
    for (int i = 1; i <= t; i++) {
        if (wh[i][0] == '1') ret++;
    }
    cout << ret << '\n';

    return 0;
}