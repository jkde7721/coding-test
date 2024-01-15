#include <bits/stdc++.h>
using namespace std;

int N, value[100001], st, en, ret = 2000000000, idx1, idx2, tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N; en = N - 1;
    for (int i = 0; i < N; i++) {
        cin >> value[i];
    }
    while (st < en) {
        tmp = value[st] + value[en];
        if (ret > abs(tmp)) {
            ret = abs(tmp); idx1 = st; idx2 = en;
        }
        if (tmp < 0) st++;
        else en--;
    }
    cout << value[idx1] << ' ' << value[idx2] << '\n';
    return 0;
}