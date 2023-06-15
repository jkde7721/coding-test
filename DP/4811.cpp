/*
카탈란 수: y=x를 넘지 않는(작거나 같은) 경로의 수
수식: (2n)! / (n! * n! * (n + 1)) → n의 최대값인 30인 경우 60! 계산 필요, but long long 범위 초과
점화식: Cn = Cn-1*C0 + Cn-2*C1 + ... + C0*Cn-1
*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, cnt[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cnt[0] = cnt[1] = 1;
    for (int i = 2; i <= 30; i++) {
        for (int j = 0; j < i; j++) {
            cnt[i] += cnt[i-1-j] * cnt[j];
        }
    }
    while (1) {
        cin >> n;
        if (n == 0) break;
        cout << cnt[n] << '\n';
    }

    return 0;
}
*/

//DP 기반 풀이
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//cnt 배열: 현재 W 몇 개, H 몇 개 남은 상황에서 이후 만들어지는 문자열의 개수 저장
ll cnt[31][31], n;

ll go(int w, int h) {
    if (!w && !h) return 1;
    ll& ret = cnt[w][h];
    if (!ret) {
        if (w > 0) ret += go(w - 1, h + 1); //한 조각 꺼냄  
        if (h > 0) ret += go(w, h - 1); //반 조각 꺼냄
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while ((cin >> n) && n) {
        cout << go(n, 0) << '\n';
    }

    return 0;
}