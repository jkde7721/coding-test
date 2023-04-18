//메모리: 2072KB, 시간: 0ms
//뱀이 이동 시 이동방향의 다음 칸에 머리가 추가되고, 다음 칸에 사과가 없다면 꼬리를 자름
//→ 머리, 꼬리에 대해 데이터 추가&삭제 발생 → deque 자료구조 사용
#include <iostream>
#include <queue>
using namespace std;

//상우하좌 → 0123
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, k, r, c, l, x, sec, _map[100][100], idx = 1, ny, nx;
char dir[10001], ch;
deque<pair<int, int>> dq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < k; i++) { cin >> r >> c; _map[r-1][c-1] = 2; }
    cin >> l;
    for (int i = 0; i < l; i++) { cin >> x >> ch; dir[x] = ch; }

    _map[0][0] = 1; dq.push_back({0, 0});
    while (1) {
        sec++;
        ny = dq.front().first + dy[idx]; nx = dq.front().second + dx[idx];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
        if (_map[ny][nx] == 1) break;
        if (_map[ny][nx] != 2) { //사과가 없다면
            _map[dq.back().first][dq.back().second] = 0;
            dq.pop_back();
        }
        _map[ny][nx] = 1; dq.push_front({ny, nx});

        if ((idx == 0 && dir[sec] == 'L') || (idx == 2 && dir[sec] == 'D')) idx = 3;
        else if ((idx == 0 && dir[sec] == 'D') || (idx == 2 && dir[sec] == 'L')) idx = 1;
        else if ((idx == 1 && dir[sec] == 'L') || (idx == 3 && dir[sec] == 'D')) idx = 0;
        else if ((idx == 1 && dir[sec] == 'D') || (idx == 3 && dir[sec] == 'L')) idx = 2;
    }
    cout << sec << '\n';

    return 0;
}