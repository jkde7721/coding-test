//메모리: 2452KB, 시간: 64ms
#include <bits/stdc++.h>
using namespace std;

int R, C, M, T, _map[101][101], ret;
bool cat[10001];
typedef struct s {
    int r, c, s, d, z;
    void move() {
        int dir, dis = s;
        if (abs(d) == 1) {
            if (d > 0) {
                if (r - dis > 0) { r = r - dis; dis = 0; }
                else { dis -= r - 1; r = 1; d *= -1; }
            }
            if (dis) {
                dir = (r + dis - 1) / (R - 1);
                dis = (r + dis - 1) % (R - 1);
                d *= (int)pow(-1, dir);
                r = (d < 0 ? 1 + dis : R - dis);
            }
        } else {
            if (d < 0) {
                if (c - dis > 0) { c = c - dis; dis = 0; }
                else { dis -= c - 1; c = 1; d *= -1; }
            }
            if (dis) {
                dir = (c + dis - 1) / (C - 1);
                dis = (c + dis - 1) % (C - 1);
                d *= (int)pow(-1, dir);
                c = (d > 0 ? 1 + dis : C - dis);
            }
        }
    }
} shark;
shark shk[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> M;
    for (int i = 1; i <= M; i++) {
        cin >> shk[i].r >> shk[i].c >> shk[i].s >> shk[i].d >> shk[i].z;
        _map[shk[i].r][shk[i].c] = i;
        if (shk[i].d == 2) shk[i].d = -1;
        if (shk[i].d == 4) shk[i].d = -3;
    }

    while (T < C) {
        T++; //낚시왕 이동
        //상어잡기
        for (int i = 1; i <= R; i++) {
            if (_map[i][T]) {
                ret += shk[_map[i][T]].z;
                cat[_map[i][T]] = 1;
                break;
            }
        }
        //상어이동
        int r, c, num;
        for (int i = 1; i <= M; i++) _map[shk[i].r][shk[i].c] = 0;
        for (int i = 1; i <= M; i++) {
            if (cat[i]) continue;
            shk[i].move();
            r = shk[i].r; c = shk[i].c;
            if ((num = _map[r][c])) {
                if (shk[i].z > shk[num].z) {
                    _map[r][c] = i;
                    cat[num] = 1;
                }
                else cat[i] = 1;
            }
            else _map[r][c] = i;
        }
    }
    cout << ret << '\n';

    return 0;
}

//메모리: KB, 시간: ms
/*
죽었는지 여부 struct 내부에서 관리
2차원 배열 0부터 시작하도록 변경
방향 벡터 사용 + 상하우좌(0123) + 방향 변경 시 1과 XOR 연산 
→ 위 방식으로 다시 풀어보기 
*/