//메모리: 2276KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;

//memo 배열: 몇초에 어떤 나무에 있으면서 몇 번 움직였을 때 받은 최대의 자두 개수 저장
/*
ex. 0번 나무(1초) → 1번 나무 → 1번 나무 / 0번 나무(1초) → 0번 나무 → 1번 나무
=> 3초에 있는 나무나 움직인 횟수는 same → 두 경우 중 받은 최대의 자두 개수만을 저장
=> 각 초마다 경우의 수 2가지: 다른 나무로 움직이거나 or 현재 나무에 머무름
=> 3초에 움직임 → 4초에 움직임/머무름 or 3초에 머무름 → 4초에 움직임/머무름
=> 3초 이후 4초에서부터 중복되는 케이스 많음(다른 초들도 마찬가지) → 이를 메모리제이션
*/
int t, w, a[1002], memo[1002][2][32];

//해당 경우 받은 최대의 자두 개수 반환
int go(int sec, int tree, int cnt) {
    if (cnt > w | sec == t) return 0;
    if (memo[sec][tree][cnt] == -1) {
        memo[sec][tree][cnt] = max(go(sec + 1, tree^1, cnt + 1), go(sec + 1, tree, cnt)) + (a[sec] == tree);
    }
    return memo[sec][tree][cnt];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t >> w;
    memset(memo, -1, sizeof(memo));
    for (int i = 0; i < t; i++) { cin >> a[i]; a[i]--; } //나무는 0 또는 1
    cout << max(go(0, 1, 1), go(0, 0, 0)) << '\n'; //처음에 움직임, 머무름

    return 0;
}