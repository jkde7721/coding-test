//DP 풀이
//메모리: 64524KB, 시간: 88ms
#include <bits/stdc++.h>
using namespace std;

int ret, dp[4000][4000];
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s1 >> s2;
    //같은 문자 찾기
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (s1[i] == s2[j]) { dp[i][j] = 1; ret = 1; }
        }
    }
    //같은 문자열 찾기
    for (int i = 1; i < s1.size(); i++) {
        for (int j = 1; j < s2.size(); j++) {
            if (s1[i] == s2[j]) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + 1);
                ret = max(ret, dp[i][j]);
            }
        }
    }
    cout << ret << '\n';
    return 0;
}

//KMP 알고리즘 풀이 (참고: https://www.youtube.com/watch?v=yWWbLrV4PZ8)
//메모리: 2040KB, 시간: 100ms
/*
#include <bits/stdc++.h>
using namespace std;

int jump[4000], idx, ret;
string s1, s2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s1 >> s2;
    for (int i = 0; i < s1.size(); i++) {
        idx = i; jump[i] = i;
        for (int j = i + 1; j < s1.size(); j++) {
            while (idx > i && s1[idx] != s1[j]) idx = jump[idx-1];
            if (s1[idx] == s1[j]) jump[j] = ++idx; //j+1에서 불일치가 발생하면 jump[j]부터 다시 비교 시작
        }
        idx = i;
        for (int j = 0; j < s2.size(); j++) {
            //s1[idx] != s2[j]일 때 jump[idx-1]의 인덱스부터 다시 비교 시작
            while (idx > i && s1[idx] != s2[j]) idx = jump[idx-1];
            if (s1[idx] == s2[j]) { ret = max(ret, idx-i+1); idx++; }
        }
    }
    cout << ret << '\n';
    return 0;
}
*/