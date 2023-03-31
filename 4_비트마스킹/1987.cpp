//�޸�: 2020KB, �ð�: 444ms => bool �迭 Ǯ��
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

//�޸�: 2020KB, �ð�: 460ms => ��Ʈ����ŷ Ǯ�� (���� bool Ÿ�� �迭 ��� int Ÿ�� ���� �ϳ� ���)
//�ڵ� ���̴� ���� �پ������ ���� �ǹ̴� ���� ��?
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