//�޸�: 10032KB, �ð�: 8ms
//�־��� ���: (50,000 * 1,000,000)�� �ð����⵵ �� �� �ð��ʰ� �ȳ���?
#include <bits/stdc++.h>
#define MAX 500000
#define y1 abc
using namespace std;

//_x, _y �迭�� ������ count �迭
int n, x, y, _x[1000000], _y[1000000], x1, y1, x2, y2, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<int, int>> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> x >> y; x += MAX; y += MAX;
        v[i] = {x, y};
    }
    v[n] = v[0];
    for (int i = 0; i < n; i++) {
        tie(x1, y1) = v[i];
        tie(x2, y2) = v[i + 1];
        if (x1 == x2) {
            if (y1 > y2) swap(y1, y2);
            //y1 �� y2���� y2�� count (y1' �� y2', y1 �� y2���� y2' == y1�� �� 1���� count�ϱ� ����)
            for (int i = y1 + 1; i <= y2; i++) _y[i]++;
        }
        if (y1 == y2) {
            if (x1 > x2) swap(x1, x2);
            for (int i = x1 + 1; i <= x2; i++) _x[i]++;
        }
    }
    for (int i = 0; i < n; i++) {
        ret = max(ret, _x[v[i].first]);
        ret = max(ret, _y[v[i].second]);
    }
    cout << ret << '\n';

    return 0;
}