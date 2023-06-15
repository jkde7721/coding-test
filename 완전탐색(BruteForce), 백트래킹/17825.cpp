#include <iostream>
using namespace std;

int turn[10], score, mx;
int _map[4][30] = {
    {-1, 2, 4, 6, 8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32, 34, 36, 38, 40},
    {10, 13, 16, 19, 25, 30, 35, 40},
    {20, 22, 24, 25, 30, 35, 40},
    {30, 28, 27, 26, 25, 30, 35, 40}
};
pair<int, int> mal[4];

bool isSamePlace(int y1, int x1, int y2, int x2) {
    if (y1 == y2 && x1 == x2) return true;
    if (_map[y1][x1] == 40 && _map[y2][x2] == 40) return true;
    if (y1 != 0 && y2 != 0 && _map[y1][x1] == _map[y2][x2]) return true;
    return false;
}

void go(int n) {
    if (n == 10) {
        mx = max(mx, score);
        return;
    }

    for (int i = 0; i < 4; i++) {
        int y = mal[i].first, x = mal[i].second;
        if (_map[y][x] == 0) continue;
        
        int ny = y, nx = x;
        if (y == 0 && (x == 5 || x == 10 || x == 15)) {
            ny = x / 5; 
            nx = turn[n];
        }
        else nx += turn[n];
        
        if (_map[ny][nx]) {
            bool isEmpty = true;
            for (int j = 0; j < 4; j++) {
                if (i == j) continue;
                if (isSamePlace(ny, nx, mal[j].first, mal[j].second)) isEmpty = false;
            }
            if (!isEmpty) continue;
        }

        score += _map[ny][nx];
        mal[i].first = ny; mal[i].second = nx;
        go(n + 1);
        score -= _map[ny][nx];
        mal[i].first = y; mal[i].second = x;
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        cin >> turn[i];
    }
    go(0);
    cout << mx << '\n';

    return 0;
}