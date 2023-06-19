//메모리: 8740KB, 시간: 8ms
#include <iostream>
#include <cstring>
using namespace std;

int n, m, c, w[13], dp[10][21][1 << 13];

//현재까지 steal 상태로 보석을 훔치고 해당 가방에 cap의 용량이 남은 상태에서 앞으로 훔칠 수 있는 최대 보석 개수 반환
int go(int idx, int cap, int steal) {
    if (idx == m) return 0;
    int& ret = dp[idx][cap][steal];
    if (ret == -1) {
        bool visited = 0;
        //그리디하게 현재 가방에 더이상 넣을 수 없을 때까지 훔침
        for (int i = 0; i < n; i++) {
            if ((1 << i) & steal || cap < w[i]) continue; //이미 훔친 보석 or 용량 부족
            ret = max(ret, go(idx, cap - w[i], (1 << i) | steal) + 1);
            visited = 1;
        }
        //현재 가방의 남아있는 용량 부족 → 다음 가방으로 넘어감
        if (!visited) ret = max(ret, go(idx + 1, c, steal));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    for (int i = 0; i < n; i++) cin >> w[i];
    memset(dp, -1, sizeof(dp));
    cout << go(0, c, 0) << '\n';
    return 0;
}