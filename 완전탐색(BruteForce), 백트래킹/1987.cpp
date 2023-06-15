//메모리: 2020KB, 시간: 444ms => bool 배열 풀이
/*
#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, ret;
char board[20][20];
bool alpha[26];

void dfs(int y, int x, int cnt) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        if (alpha[board[ny][nx] - 'A']) continue;
        alpha[board[ny][nx] - 'A'] = 1;
        dfs(ny, nx, cnt + 1);
        alpha[board[ny][nx] - 'A'] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    alpha[board[0][0] - 'A'] = 1;
    dfs(0, 0, 1);
    cout << ret << '\n';

    return 0;
}
*/

//메모리: 2020KB, 시간: 460ms => 비트마스킹 풀이 (위의 bool 타입 배열 대신 int 타입 숫자 하나 사용)
//코드 길이는 조금 줄어들지만 딱히 의미는 없는 듯?
#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, ret, tmp;
char board[20][20];

void dfs(int y, int x, int cnt, int alpha) {
    ret = max(ret, cnt);
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
        tmp = 1 << (board[ny][nx] - 'A');
        if (tmp & alpha) continue;
        dfs(ny, nx, cnt + 1, tmp | alpha);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> board[i][j];
        }
    }
    dfs(0, 0, 1, 1 << (board[0][0] - 'A'));
    cout << ret << '\n';

    return 0;
}