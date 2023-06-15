//메모리: 2060KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;

//cnt 배열: 주어진 동전으로 인덱스 금액을 만드는 경우의 수 저장
int n, k, tmp, cnt[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k; cnt[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = tmp; j <= k; j++) {
            cnt[j] += cnt[j - tmp];
        }
    }
    cout << cnt[k] << '\n';

    return 0;
}