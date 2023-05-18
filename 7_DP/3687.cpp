//메모리: 2164KB, 시간: 0ms
/*
#include <iostream>
#include <algorithm>
#define MAX "11111111111111111111111111111111111111111111111111"
using namespace std;

int t, n;
string mn[101], mx[101], ret, tmp;

bool cmp(string a, string b) {
    if (a[0] == '0') return false;
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(mn, mn + 101, MAX);
    mn[2] = "1"; mn[3] = "7"; mn[4] = "4"; mn[5] = "2";
    mn[6] = "0"; mn[7] = "8"; mx[2] = "1"; mx[3] = "7";
    for (int i = 8; i <= 100; i++) {
        for (int j = 2; j <= i / 2; j++) {
            ret = mn[j] + mn[i - j];
            sort(ret.begin(), ret.end());
            if (ret[0] == '0') {
                tmp = ret; tmp[0] = '6';
                auto pos = upper_bound(ret.begin(), ret.end(), '0');
                if (pos != ret.end()) swap(ret[0], ret[pos - ret.begin()]);
                if (cmp(tmp, ret)) ret = tmp;
            }
            if (cmp(ret, mn[i])) mn[i] = ret;
        }
    }
    for (int i = 4; i <= 100; i++) mx[i] = mx[i - 2] + "1";

    cin >> t;
    while (t--) {
        cin >> n;
        cout << (n == 6 ? "6" : mn[n]) << ' ' << mx[n] << '\n';
    }
    return 0;
}
*/

#include <iostream>
#define MAX "11111111111111111111111111111111111111111111111111"
using namespace std;

//num 배열: 해당 인덱스 개수의 성냥개비로 만들 수 있는 가장 작은 수
int t, n;
string mn[101], mx[101], ret, num[8] = {"", "", "1", "7", "4", "2", "0", "8"};

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(mn, mn + 101, MAX);
    mn[2] = "1"; mn[3] = "7"; mn[4] = "4"; mn[5] = "2"; mn[6] = "6"; mn[7] = "8"; mn[8] = "10"; 
    mx[2] = "1"; mx[3] = "7";
    for (int i = 9; i <= 100; i++) {
        for (int j = 2; j <= 7; j++) {
            ret = mn[i - j] + num[j];
            if (cmp(ret, mn[i])) mn[i] = ret;
        }
    }
    for (int i = 4; i <= 100; i++) mx[i] = mx[i - 2] + "1";

    cin >> t;
    while (t--) {
        cin >> n;
        cout << mn[n] << ' ' << mx[n] << '\n';
    }
    return 0;
}