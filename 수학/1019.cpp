//참고: https://blog.naver.com/jjys9047/222159640586
#include <bits/stdc++.h>
using namespace std;

int n, digit = 1, cnt[10];
string str;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> str;
    for (int i = 1; i < str.size(); i++) digit *= 10; //pow 함수 사용 시 오차 발생
    for (int i = 0; digit; i++, digit /= 10) {
        n = str[i] - '0';
        for (int j = (i == 0 ? 1 : 0); j < n; j++) {
            cnt[j] += digit; //ex. 백의 자리에 있는 1은 100번 등장 (100~199)
        }
        cnt[n] += (digit == 1 ? 1 : stoi(str.substr(i + 1)) + 1);
        if (i == 0) continue;
        for (int j = 0; j <= 9; j++) {
            cnt[j] += digit * stoi(str.substr(0, i));
        }
        cnt[0] -= digit; //맨 앞 숫자가 0인 페이지 제외
    }
    for (int i = 0; i <= 9; i++) cout << cnt[i] << ' ';
    return 0;
}