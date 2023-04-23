//�޸�: 2168KB, �ð�: 0ms
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int N, ret;
bool _map[101][101];
typedef struct d {
    int x, y, d, g;
} dragon;
dragon dr[20];

int getDir(int ddy, int ddx) {
    int k;
    for (k = 0; k < 4; k++) {
        if (dy[k] == ddy && dx[k] == ddx) break;
    }
    return (k == 0 ? 3 : k - 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> dr[i].x >> dr[i].y >> dr[i].d >> dr[i].g;
    }
    for (int i = 0; i < N; i++) {
        int y = dr[i].y, x = dr[i].x, d = dr[i].d, py, px, ny, nx, idx;
        vector<pair<int, int>> v;
        v.push_back({y, x}); v.push_back({y + dy[d], x + dx[d]});
        _map[y][x] = 1; _map[y + dy[d]][x + dx[d]] = 1;
        while (dr[i].g > 0) {
            for (int j = v.size() - 1; j > 0; j--) {
                y = v[j].first; x = v[j].second;
                py = v[j-1].first; px = v[j-1].second;
                idx = getDir(py - y, px - x); 
                ny = v.back().first + dy[idx]; nx = v.back().second + dx[idx];
                v.push_back({ny, nx});
                _map[ny][nx] = 1;
            }
            dr[i].g--;
        }
    }
    //���簢�� ���� count
    for (int y = 0; y < 100; y++) {
        for (int x = 0; x < 100; x++) {
            if (!_map[y][x]) continue;
            if (_map[y][x+1] + _map[y+1][x] + _map[y+1][x+1] == 3) ret++;
        }
    }
    cout << ret << '\n';

    return 0;
}

//�޸�: KB, �ð�: ms
//���� ���� �巡�� Ŀ�꿡�� �߿��� ���� y, x �ε��� ��ü�� �ƴ� ���� ���� 
//�� vector�� pair<int, int>�� �ƴ� int �ڷ����� ����ؼ� �ٽ� Ǯ���