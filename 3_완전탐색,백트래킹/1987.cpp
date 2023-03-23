//메모리: 2024KB, 시간: 496ms
#include <iostream>
#include <tuple>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, ret;
bool alpha[26];
char board[20][20];
string str;

void dfs(int y, int x, int cnt) {
    bool isMove = false;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (alpha[board[ny][nx] - 'A']) continue;
        isMove = true;

        alpha[board[ny][nx] - 'A'] = 1;
        dfs(ny, nx, cnt + 1);
        alpha[board[ny][nx] - 'A'] = 0;
    }
    if (!isMove) ret = max(ret, cnt);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            board[i][j] = str[j];
        }
    }
    alpha[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << ret << '\n';

    return 0;
}