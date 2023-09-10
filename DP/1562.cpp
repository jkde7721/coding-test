//공간복잡도 줄인 풀이
//메모리: 2036KB, 시간: 0ms
#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

//0, 9 모두 등장 = 0~9의 모든 수 등장 → 0, 9 등장 여부에 따라 상태가 4개로 나뉨
//0, 9 모두 등장X = 0 / 0만 등장 = 1 / 9만 등장 = 2 / 0, 9 모두 등장O = 3

int n, dp[101][10][4], tmp, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < 10; i++) dp[1][i][(i == 9 ? 2 : 0)] = 1;
    for (int i = 2; i <= n; i++) { //계단 수 길이
        for (int j = 0; j < 10; j++) { //계단 수의 끝 수
            for (int k = 0; k < 4; k++) { //0, 9 등장 여부
                tmp = (j != 0 && j != 9) ? 0 : (j == 0 ? 1 : 2);
                dp[i][j][k | tmp] += ((j != 0 ? dp[i-1][j-1][k] : 0) + (j != 9 ? dp[i-1][j+1][k] : 0)) % MOD;
                dp[i][j][k | tmp] %= MOD;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ret += dp[n][i][3]; ret %= MOD; //길이가 n이면서 0~9까지의 숫자가 모두 등장하는 계단 수이면서 끝 수가 각각 0인 경우 + ... + 9인 경우
    }
    cout << ret << '\n';
    return 0;
}

//비트마스킹 활용
//메모리: 6060KB, 시간: 4ms
/*
#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int n, dp[101][10][(1 << 10)], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < 10; i++) dp[1][i][(1 << i)] = 1;
    for (int i = 2; i <= n; i++) { //계단 수 길이
        for (int j = 0; j < 10; j++) { //계단 수의 끝 수
            for (int k = 0; k < (1 << 10); k++) { //0~9의 모든 수 등장 여부
                dp[i][j][k | (1 << j)] += ((j != 0 ? dp[i-1][j-1][k] : 0) + (j != 9 ? dp[i-1][j+1][k] : 0)) % MOD;
                dp[i][j][k | (1 << j)] %= MOD;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        ret += dp[n][i][1023]; ret %= MOD; //길이가 n이면서 0~9까지의 숫자가 모두 등장하는 계단 수이면서 끝 수가 각각 0인 경우 + ... + 9인 경우
    }
    cout << ret << '\n';
    return 0;
}
*/