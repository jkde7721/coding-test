#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, price[10][10], ret = 987654321;
bool visited[10][10];

class Flower {
private:
    int cy, cx, ty, tx, ry, rx, by, bx, ly, lx;
public:
    void setPos(int cy, int cx) {
        this->cy = cy; this->cx = cx;
        ty = cy + dy[0]; tx = cx + dx[0];
        ry = cy + dy[1]; rx = cx + dx[1];
        by = cy + dy[2]; bx = cx + dx[2];
        ly = cy + dy[3]; lx = cx + dx[3];
    }
    bool canPlant() {
        return !visited[cy][cx] && !visited[ty][tx] && !visited[ry][rx] && !visited[by][bx] && !visited[ly][lx];
    }
    void plant(int value) {
        visited[cy][cx] = value;
        visited[ty][tx] = value;
        visited[ry][rx] = value;
        visited[by][bx] = value;
        visited[ly][lx] = value;
    }
    int getPrice() {
        return price[cy][cx] + price[ty][tx] + price[ry][rx] + price[by][bx] + price[ly][lx];
    }
};

void go(int y, int x, int cnt, int sum) {
    if (cnt == 3) {
        ret = min(ret, sum);
        return;
    }

    Flower flower;
    for (int i = y; i < n - 1; i++) {
        for (int j = x; j < n - 1; j++) {
            flower.setPos(i, j);
            if (!flower.canPlant()) continue;

            flower.plant(1);
            go(y, x + 3, cnt + 1, sum + flower.getPrice());
            flower.plant(0);
        }
        x = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> price[i][j];
        }
    }
    go(1, 1, 0, 0);
    cout << ret << '\n';

    return 0;
}