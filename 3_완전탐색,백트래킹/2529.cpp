//메모리: 2024KB, 시간: 4ms
#include <iostream>
using namespace std;

int k;
char sign[9];
string min_ret = "9876543210", max_ret = "0", anw;
bool num[10];

string getMin(string a, string b) {
    if (stoll(a) < stoll(b)) return a;
    else return b;
}

string getMax(string a, string b) {
    if (stoll(a) > stoll(b)) return a;
    else return b;
}

bool isOk(int a, int b, char op) {
    if (op == '<') return a < b;
    return a > b;
}

void dfs(int dep) {
    if (dep == k + 1) {
        min_ret = getMin(min_ret, anw);
        max_ret = getMax(max_ret, anw);
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