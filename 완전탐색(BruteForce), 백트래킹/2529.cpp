//메모리: 2024KB, 시간: 4ms
#include <iostream>
using namespace std;

int k;
char sign[9];
string min_ret = "9876543210", max_ret = "0", anw;
bool num[10];

bool isGt(string a, string b) {
    if (a.size() == b.size()) return a > b;
    return a.size() > b.size();
}

bool isOk(int a, int b, char op) {
    if (op == '<') return a < b;
    return a > b;
}

void dfs(int dep) {
    if (dep == k + 1) {
        min_ret = isGt(min_ret, anw) ? anw : min_ret;
        max_ret = isGt(max_ret, anw) ? max_ret : anw;
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (num[i]) continue;
        if (anw.size() && !isOk(anw[anw.size() - 1] - '0', i, sign[dep - 1])) continue;

        num[i] = 1;
        anw.push_back(char(i + '0'));
        dfs(dep + 1);
        num[i] = 0;
        anw.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> sign[i];
    }
    dfs(0);
    cout << max_ret << '\n' << min_ret << '\n';

    return 0;
}

//메모리: 3692KB, 시간: 12ms 
//→ 생성되는 모든 숫자 문자열을 vector에 저장하고 후에 정렬하기 때문에 메모리 더 씀, 시간 더 걸림
/*
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k;
char sign[9];
bool nums[10];
vector<string> ret;

bool isOk(char a, char b, char s) {
    if (s == '<') return a < b;
    return a > b;
}

void go(int idx, string anw) {
    if (idx == k + 1) {
        ret.push_back(anw);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (nums[i]) continue;
        if (idx > 0 && !isOk(anw[anw.size() - 1], i + '0', sign[idx - 1])) continue;
        
        nums[i] = 1;
        go(idx + 1, anw + char(i + '0'));
        nums[i] = 0;
    }
}

bool cmp(string a, string b) {
    if (a.size() == b.size()) return a < b;
    return a.size() < b.size();
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> sign[i];
    }
    go(0, "");

    sort(ret.begin(), ret.end(), cmp);
    cout << ret[ret.size() - 1] << '\n' << ret[0] << '\n';

    return 0; 
}
*/