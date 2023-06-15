//메모리: 2248KB, 시간: 4ms
//Top-Down 방식 풀이
/*
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

//cnt 배열: 인덱스 금액이 되도록 하는 동전의 최소 개수 저장
int n, k, cnt[10001], coin[100];

//amt 금액을 만드는 동전의 최소 개수 반환
int go(int amt) {
    if (amt == 0) return 0;
    int& ret = cnt[amt];
    if (!ret) {
        ret = INF;
        for (int i = 0; i < n; i++) {
            if (amt >= coin[i]) ret = min(ret, go(amt - coin[i]) + 1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coin[i];
    int ret = go(k);
    cout << (ret == INF ? -1 : ret) << '\n';

    return 0;
}
*/

//메모리: 2060KB, 시간: 0ms
//Bottom-Up 방식 풀이
/*
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, k, cnt[10001], coin[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(cnt, cnt + 10001, INF);
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> coin[i];
    cnt[0] = 0;
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= coin[j]) {
                cnt[i] = min(cnt[i], cnt[i - coin[j]] + 1);
            }
        }
    }
    cout << (cnt[k] == INF ? -1 : cnt[k]) << '\n';

    return 0;
}
*/

//Knapsack 알고리즘 풀이
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, k, tmp, cnt[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(cnt, cnt + 10001, INF);
    cin >> n >> k;
    cnt[0] = 0;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        //만약 해당 동전을 1번만 사용 가능하다면, for (int j = k; j >= tmp; j--) 로 변경
        for (int j = tmp; j <= k; j++) {
            cnt[j] = min(cnt[j], cnt[j - tmp] + 1);
        }
    }
    cout << (cnt[k] == INF ? - 1 : cnt[k]) << '\n';

    return 0;
}