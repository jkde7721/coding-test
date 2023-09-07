#include <bits/stdc++.h>
using namespace std;

int n, num, lis[200], len;

//LIS를 찾고 얘네를 기준으로 나머지 애들을 옮김
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        auto pos = lower_bound(lis, lis + len, num);
        if (*pos == 0) len++;
        *pos = num;
    }
    cout << n - len << '\n';
    return 0;
}