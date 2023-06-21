//메모리: 5932KB, 시간: 12ms → bottom-up 풀이도 가능
//LCS(Longest Common Subsequence, 최장 공통 부분 수열)
#include <bits/stdc++.h>
using namespace std;

//dp 배열: 해당 인덱스로부터의 첫번째 문자열, 해당 인덱스로부터의 두번째 문자열 간 LCS 길이 저장
int dp[1000][1000];
string s1, s2;

int go(int idx1, int idx2) {
    if (idx1 >= s1.size() || idx2 >= s2.size()) return 0;
    int& ret = dp[idx1][idx2];
    if (ret == -1) {
        ret = go(idx1 + 1, idx2);
        if (s1[idx1] == s2[idx2]) ret = max(ret, go(idx1 + 1, idx2 + 1) + 1);
        else ret = max(ret, go(idx1, idx2 + 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> s1 >> s2;
    cout << go(0, 0) << '\n';
    return 0;
}