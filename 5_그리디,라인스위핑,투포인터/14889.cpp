//메모리: 2024KB, 시간: 52ms
/*
#include <iostream>
#include <vector>
using namespace std;

int n, s[20][20], ret = 987654321;
vector<int> v, v2;
bool t[20];

int getS(vector<int> team) {
    int sum = 0;
    for (int i = 0; i < team.size(); i++) {
        for (int j = i + 1; j < team.size(); j++) {
            sum += s[team[i]][team[j]]; sum += s[team[j]][team[i]];
        }
    }
    return sum;
}

void go(int idx) {
    if (v.size() == n / 2) {
        for (int i = 0; i < n; i++) {
            if (!t[i]) v2.push_back(i);
        }
        ret = min(ret, abs(getS(v) - getS(v2)));
        v2.clear();
        return;
    }
    for (int i = idx; i < n; i++) {
        v.push_back(i); t[i] = 1;
        go(i + 1);
        v.pop_back(); t[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> s[i][j];
        }
    }
    go(0);
    cout << ret << '\n';

    return 0;
}
*/

//메모리: 2024KB, 시간: 56ms
//비트마스킹 풀이
#include <iostream>
#include <vector>
using namespace std;

int n, s[20][20], ret = 987654321, num;

int getDiff(int t) {
    int s1 = 0, s2 = 0;
    vector<int> v, v2;
    for (int i = 0; i < n; i++) {
        if (t & (1 << i)) v.push_back(i);
        else v2.push_back(i);
    }
    for (int i = 0; i < n / 2; i++) {
        for (int j = i + 1; j < n / 2; j++) {
            s1 += s[v[i]][v[j]]; s1 += s[v[j]][v[i]];
            s2 += s[v2[i]][v2[j]]; s2 += s[v2[j]][v2[i]];
        }
    }
    return abs(s1 - s2);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> s[i][j];
    }
    for (int i = 1; i < (1 << (n - 1)); i++) {
//        num = 0;
//        for (int j = 0; j < n; j++) {
//            if (i & (1 << j)) num++;
//        }
//        if (num != n/2) continue;

//__builtin_popcount 함수: 위 주석처리한 코드와 동일한 기능, 켜져있는(값이 1인) 비트 수 count
        if (__builtin_popcount(i) != n / 2) continue;
        ret = min(ret, getDiff(i));
    }
    cout << ret << '\n';

    return 0;
}