//최장 증가 부분 수열의 길이를 구하는 문제
//O(NlogN) 알고리즘 풀이
#include <bits/stdc++.h>
using namespace std;

int n, num, lis[1000], len;

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
    cout << len << '\n';
    return 0;
}

//O(N^2) 알고리즘 풀이
/*
#include <bits/stdc++.h>
using namespace std;

int n, num[1000], len[1000], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < n; i++) {
        len[i] = 1; //현재 인덱스까지의 LIS의 길이 초기화
        for (int j = 0; j < i; j++) {
            if (num[j] < num[i]) len[i] = max(len[i], len[j] + 1);
        }
        ret = max(ret, len[i]);
    }
    cout << ret << '\n';
    return 0;
}
*/