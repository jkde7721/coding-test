#include <iostream>
using namespace std;

int N, K, ret = 100000, num, visited[100001];

void find(int n, int cnt) {
    if (n < 0 || cnt > ret) return;
    if (n >= K) {
        if (n > K) cnt += (n - K);
        if (ret == cnt) num++;
        else if (ret > cnt) num = 1;
        ret = min(ret, cnt);
        return;
    }
    if (visited[n] > 0 && visited[n] < cnt) return;
    
    visited[n] = cnt;
    find(n * 2, cnt + 1);
    find(n + 1, cnt + 1);
    find(n - 1, cnt + 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;
    find(N, 0);
    cout << ret << '\n';
    cout << num << '\n';

    return 0;
}