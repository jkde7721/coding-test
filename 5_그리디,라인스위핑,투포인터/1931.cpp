//�޸�: 3688KB, �ð�: 28ms
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, e, ret;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        v.push_back({s, e});
    }
    sort(v.begin(), v.end(), cmp);

    s = v[0].first; e = v[0].second;
    for (int i = 1; i < n; i++) {
        if (e <= v[i].first) {
            s = v[i].first; e = v[i].second;
            ret++;
        }
        else if (e <= v[i].second) continue;
        else {
            s = v[i].first; e = v[i].second;
        }
    }
    cout << (ret + 1) << '\n';

    return 0;
}
*/

//�޸�: 3688KB, �ð�: 28ms
//���� �ð� �������θ� �����ؼ� Ǯ���
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, s, e, ret = 1;
vector<pair<int, int>> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> e;
        v.push_back({e, s});
    }
    sort(v.begin(), v.end());

    s = v[0].second; e = v[0].first;
    for (int i = 1; i < n; i++) {
        if (v[i].second >= e) {
            s = v[i].second; e = v[i].first;
            ret++;
        }
    }
    cout << ret << '\n';

    return 0;
}