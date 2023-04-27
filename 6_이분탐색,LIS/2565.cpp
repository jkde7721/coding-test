//메모리: 2020KB, 시간: 0ms
//lower_bound 이용한 풀이
#include <bits/stdc++.h>
using namespace std;

int n, lis[100], len;
pair<int, int> wire[100];

//A 전봇대의 위치 증가 → B 전봇대의 위치 또한 증가해야 전깃줄이 서로 교차하지 않음
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> wire[i].first >> wire[i].second;
    sort(wire, wire + n);
    //a 배열의 LIS의 개수 구하기
    for (int i = 0; i < n; i++) {
        auto pos = lower_bound(lis, lis + len, wire[i].second);
        if (*pos == 0) len++;
        *pos = wire[i].second;
    }
    cout << n - len << '\n';

	return 0;
}

//메모리: 2020KB, 시간: 0ms
/*
#include <bits/stdc++.h>
using namespace std;

int n, ret, cnt[100];
pair<int, int> wire[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> wire[i].first >> wire[i].second;
    sort(wire, wire + n);
    for (int i = 0; i < n; i++) {
        cnt[i] = 1;
        for (int j = 0; j < i; j++) {
            if (wire[j].second < wire[i].second && cnt[j] + 1 > cnt[i]) {
                cnt[i] = cnt[j] + 1;
            }
        }
        ret = max(ret, cnt[i]);
    }
    cout << (n - ret) << '\n';

	return 0;
}
*/