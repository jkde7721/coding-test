#include <bits/stdc++.h>
using namespace std;

int score, n, t, y, x, y2, x2;
bool green[6][4], blue[6][4];

void move(bool board[6][4], int t, int pos, int pos2, bool gb) {
    for (int i = 0; i <= 6; i++) {
        if (t == 1 && (i == 6 || board[i][pos])) { board[i-1][pos] = 1; break; }
        else if (!gb && t == 2 || gb && t == 3) {
            if (i == 6 || board[i][pos] || board[i][pos2]) { board[i-1][pos] = board[i-1][pos2] = 1; break; }
        }
        else {
            if (i == 6 || board[i][pos]) { board[i-2][pos] = board[i-1][pos] = 1; break; }
        }
    }
}

int full(bool board[6][4]) {
    int cnt = 0;
    for (int i = 5; i >= 0; i--) {
        if (board[i][0] && board[i][1] && board[i][2] && board[i][3]) {
            memset(board[i], 0, sizeof(board[i])); cnt++; continue;
        }
        if (cnt) {
            memcpy(board[i+cnt], board[i], sizeof(board[i]));
            memset(board[i], 0, sizeof(board[i]));
        }
    }
    return cnt;
}

void specialArea(bool board[6][4]) {
    int cnt = (accumulate(&board[0][0], &board[0][0] + 4, 0) ? 1 : 0) + (accumulate(&board[1][0], &board[1][0] + 4, 0) ? 1 : 0);
    if (!cnt) return;
    for (int i = 5 - cnt; i >= 0; i--) {
        memcpy(board[i+cnt], board[i], sizeof(board[i]));
        memset(board[i], 0, sizeof(board[i]));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int k = 0; k < n; k++) {
        cin >> t >> y >> x;
        if (t == 2) { y2 = y; x2 = x + 1; }
        else { y2 = y + 1; x2 = x; }
        //블록 이동
        move(green, t, x, x2, 0);
        move(blue, t, y, y2, 1);
        //행이나 열이 타일로 가득찬 경우 처리
        score += full(green);
        score += full(blue);
        //특별한 영역 처리
        specialArea(green);
        specialArea(blue);
    }
    cout << score << '\n';
    cout << accumulate(&green[0][0], &green[0][0] + 6*4, 0) + accumulate(&blue[0][0], &blue[0][0] + 6*4, 0) << '\n';
    return 0;
}