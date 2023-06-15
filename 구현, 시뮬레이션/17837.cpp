#include <bits/stdc++.h>
using namespace std;

typedef struct M {
    int y, x, dir;
} Mal;

const int dy[] = {0, 0, 0, -1, 1}, dx[] = {0, 1, -1, 0, 0}, turn[] = {0, 2, 1, 4, 3};
int n, k, _map[14][14], cnt;
Mal mal[11];
vector<int> chess[14][14];
bool isOver;

//m번 말과 위의 말들을 y → ny, x → nx로 이동 
void move(int y, int x, int ny, int nx, int m) {
    int idx = chess[ny][nx].size(), tmp;
    for (int j = chess[y][x].size() - 1; j >= 0; j--) {
        tmp = chess[y][x][j]; chess[y][x].pop_back();
        chess[ny][nx].push_back(tmp); 
        mal[tmp].y = ny; mal[tmp].x = nx;
        if (tmp == m) break;
    }
    //흰색이면
    if (!_map[ny][nx]) reverse(chess[ny][nx].begin() + idx, chess[ny][nx].end());
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    fill(&_map[0][0], &_map[0][0] + 14*14, 2);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> _map[i][j];
    }
    for (int i = 1; i <= k; i++) {
        cin >> mal[i].y >> mal[i].x >> mal[i].dir;
        chess[mal[i].y][mal[i].x].push_back(i);
    }

    int y, x, ny, nx, dir;
    while (cnt++ <= 1000) {
        isOver = false;
        for (int i = 1; i <= k; i++) {
            y = mal[i].y; x = mal[i].x; dir = mal[i].dir;
            ny = y + dy[dir]; nx = x + dx[dir];
            //파란색인 경우
            if (_map[ny][nx] == 2) {
                mal[i].dir = dir = turn[dir]; //이동 방향 반대로
                ny = y + dy[dir]; nx = x + dx[dir];
                if (_map[ny][nx] == 2) continue;
            }
            //흰색 또는 빨간색인 경우 + 파란색 만나서 방향 바꾸고 다시 한 칸 이동하는 경우
            move(y, x, ny, nx, i);
            if (chess[ny][nx].size() >= 4) { isOver = true; break; }
        }
        if (isOver) break;
    }
    cout << (cnt > 1000 ? -1 : cnt) << '\n';

    return 0;
}