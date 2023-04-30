//�޸�: 4916KB, �ð�: 104ms
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

//�ִ� �����: ��� ���Ϳ��� �������� ��Ƴ��� ��ŭ�� ����� (����� ȸ�� ���X)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> atk; 
    ll catk = atk;
    for (int i = 0; i < n; i++) {
        cin >> room[i].t >> room[i].a >> room[i].h;
        if (room[i].t == 1) {
            cnt = room[i].h / catk + (room[i].h % catk ? 0 : -1); //��簡 ���ݹ޴� Ƚ��
            r += room[i].a * cnt;
        }
        else catk += room[i].a;
    }
    //�ִ� 60�� ����
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

//�޸�: 2020KB, �ð�: 36ms
//���� ������� Ǯ�� (�׸���)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, atk, maxHp, curHp, t, a, h, dam;

//curHp�� �������� ��������� ���� hp
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> atk;
    //������� 0 �̸��� �� �״´ٰ� ����
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
    //�����δ� ������� 0 ������ �� ���� �� +1
    cout << maxHp + 1 << '\n';

    return 0;
}