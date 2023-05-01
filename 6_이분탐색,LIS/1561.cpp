//메모리: 2100KB, 시간: 4ms
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, t[10001], l, r = 30, mid, ret;

//해당 mnt 시간 안에 마지막 아이가 놀이기구를 처음 탔다면 놀이기구 번호 반환
int check(ll mnt) {
    ll tmp = 0;
    for (int i = 1; i <= m; i++) {
        //mnt 시간까지 몇 명 태웠는지 계산
        tmp += ceil((double)mnt / t[i]);
    }
    //마지막 아이가 처음 놀이기구 탔더라도 어떤 순서로 놀이기구를 탔는지 모르기 때문에 재탐색
    if (tmp >= n) return 0;
    for (int i = 1; i <= m; i++) {
        //해당 mnt 시간에 놀이기구가 빔
        if (mnt % t[i] == 0) tmp++;
        if (tmp == n) return i;
    }
    return -1;
}

//마지막 아이가 놀이기구를 탈 때까지 걸리는 시간을 이분 탐색
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) { cin >> t[i]; r = min(r, t[i]); }
    r *= (n - 1); //운행 시간이 제일 짧은 놀이기구를 모든 아이들이 탈 때까지의 시간
    while (l <= r) {
        mid = (l + r) / 2;
        ret = check(mid);
        if (ret > 0) break; //놀이기구 번호 반환
        else if (ret == 0) r = mid - 1;
        else l = mid + 1;
    }
    cout << ret << '\n';

    return 0;
}