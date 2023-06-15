//메모리: 2192KB, 시간: 48ms
#include <bits/stdc++.h>
using namespace std;

int t, n;
string dp[1001];
map<int, char> c = {{1, '('}, {2, ')'}, {3, '{'}, {4, '}'}, {5, '['}, {6, ']'}};

void convert(string& str) {
    for (int i = 0; i < str.size(); i++) {
        str[i] = c[str[i] - '0'];
    }
}

string getMin(string a, string b) {
    if (a.size() == 0 || a.size() > b.size()) return b;
    if (a.size() < b.size()) return a;
    return min(a, b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    dp[1] = "12"; dp[2] = "34", dp[3] = "56";
    for (int i = 4; i <= 1000; i++) {
        if (i % 2 == 0) dp[i] = getMin(dp[i], "1" + dp[i / 2] + "2");
        if (i % 3 == 0) dp[i] = getMin(dp[i], "3" + dp[i / 3] + "4");
        if (i % 5 == 0) dp[i] = getMin(dp[i], "5" + dp[i / 5] + "6");
        for (int j = 1; j < i; j++) {
            dp[i] = getMin(dp[i], dp[j] + dp[i - j]);
        }
    }
    for (int i = 1; i <= 1000; i++) convert(dp[i]);

    cin >> t;
    while (t--) {
        cin >> n;
        cout << dp[n] << '\n';
    }
    return 0;
}