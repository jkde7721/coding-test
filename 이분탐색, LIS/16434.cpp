//메모리: 4916KB, 시간: 104ms
/*
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef struct Room {
    ll t, a, h;
} Room;
ll n, atk, cnt, l = 1, r = 1, mid, ret = 1e18;
Room room[123456];

bool check(ll maxHp) {
    ll catk = atk, curHp = maxHp;
    for (int i = 0; i < n; i++) {
        if (room[i].t == 1) {
            cnt = room[i].h / catk + (room[i].h % catk ? 0 : -1);
            curHp -= room[i].a * cnt;
        }
        else {
            catk += room[i].a;
            curHp += room[i].h;
            if (curHp > maxHp) curHp = maxHp;
        }
        if (curHp <= 0) return false;
    }
    return true;
}

//최대 생명력: 모든 몬스터와의 전투에서 살아남을 만큼의 생명력 (생명력 회복 고려X)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> atk; 
    ll catk = atk;
    for (int i = 0; i < n; i++) {
        cin >> room[i].t >> room[i].a >> room[i].h;
        if (room[i].t == 1) {
            cnt = room[i].h / catk + (room[i].h % catk ? 0 : -1); //용사가 공격받는 횟수
            r += room[i].a * cnt;
        }
        else catk += room[i].a;
    }
    //최대 60번 루프
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ret = min(ret, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ret << '\n';

    return 0;
}
*/

//메모리: 2020KB, 시간: 36ms
//구현 방식으로 풀이 (그리디)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, atk, maxHp, curHp, t, a, h, dam;

//curHp는 포션으로 만들어지는 현재 hp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> atk;
    //생명력이 0 미만일 때 죽는다고 가정
    while (n--) {
        cin >> t >> a >> h;
        if (t == 1) {
            dam = a * (ceil((double)h / atk) - 1);
            if (dam > curHp) { maxHp += dam - curHp; curHp = 0; }
            else curHp -= dam;
        }
        else {
            atk += a;
            curHp += h;
            if (curHp > maxHp) curHp = maxHp;
        }
    }
    //실제로는 생명력이 0 이하일 때 죽음 → +1
    cout << maxHp + 1 << '\n';

    return 0;
}