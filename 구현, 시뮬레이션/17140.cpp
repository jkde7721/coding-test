#include <bits/stdc++.h>
using namespace std;

int r, c, rn = 3, cn = 3, k, A[100][100], ret, cnt[101];

void R() {
    int mx = 0;
    for (int i = 0; i < rn; i++) {
        vector<pair<int, int>> v;
        memset(cnt, 0, sizeof(cnt));
        for (int j = 0; j < cn; j++) {
            if (A[i][j]) cnt[A[i][j]]++;
        }
        for (int k = 1; k <= 100; k++) {
            if (cnt[k]) v.push_back({cnt[k], k});
        }
        sort(v.begin(), v.end());
        int idx = 0;
        for (auto it : v) {
            if (idx < 100) { A[i][idx] = it.second; idx++; }
            if (idx < 100) { A[i][idx] = it.first; idx++; }
        }
        for (int j = idx; j < cn; j++) A[i][j] = 0;
        mx = max(mx, idx);
    }
    cn = mx;
}

void C() {
    int mx = 0;
    for (int j = 0; j < cn; j++) {
        vector<pair<int, int>> v;
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < rn; i++) {
            if (A[i][j]) cnt[A[i][j]]++;
        }
        for (int k = 1; k <= 100; k++) {
            if (cnt[k]) v.push_back({cnt[k], k});
        }
        sort(v.begin(), v.end());
        int idx = 0;
        for (auto it : v) {
            if (idx < 100) { A[idx][j] = it.second; idx++; }
            if (idx < 100) { A[idx][j] = it.first; idx++; }
        }
        for (int i = idx; i < rn; i++) A[i][j] = 0;
        mx = max(mx, idx);
    }
    rn = mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> k; r--; c--;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> A[i][j];
    }
    while (1) {
        if (A[r][c] == k) break;
        if (ret >= 100) { ret = -1; break; }
        if (rn >= cn) R();
        else C();
        ret++;
    }
    cout << ret << '\n';
    return 0;
}