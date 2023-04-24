//�޸�: 2168KB, �ð�: 0ms
/*
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
*/

//�޸�: 2032KB, �ð�: 0ms
//���� ���� �巡�� Ŀ�꿡�� �߿��� ���� y, x ��ǥ ��ü�� �ƴ� ���� ���� 
//�� vector�� pair<int, int>�� �ƴ� int �ڷ����� ����ؼ� �ٽ� Ǯ���
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int N, x, y, d, g, ret;
bool _map[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        vector<int> v;
        _map[y][x] = _map[y+dy[d]][x+dx[d]] = 1;
        y += dy[d]; x += dx[d];
        v.push_back(d);
        while (g > 0) {
            for (int j = v.size() - 1; j >= 0; j--) {
                d = (v[j] + 1) % 4;
                y += dy[d]; x += dx[d];
                v.push_back(d);
                _map[y][x] = 1;
            }
            g--;
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (_map[i][j] && _map[i+1][j] && _map[i][j+1] && _map[i+1][j+1]) ret++;
        }
    }
    cout << ret << '\n';

    return 0;
}

//�޸�: 2164KB, �ð�: 0ms
/*
�巡�� Ŀ�꿡�� ���밡 ��� ���� �� ���� �ٸ� Ŀ���� ����� 4�� �ۿ� ����
���� ���� ���⿡ ���� Ŀ�갡 ����Ǵ� ����� �޶���, �̶� ���� ������ �����¿�� only 4��
��Ŀ���� ���� ����� vector�� ������ �� ���� ���� �־����� ��ü Ŀ���� ��ǥ�� ���� �� ����
*/
/*
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
int N, ret, x, y, d, g;
bool _map[101][101];
vector<int> v[4][11];

void makeDragon() {
    for (int i = 0; i < 4; i++) {
        v[i][0].push_back(i);
        v[i][1].push_back((i+1)%4);
        for (int j = 2; j <= 10; j++) {
            for (int k = v[i][j-1].size() - 1; k >= 0; k--) {
                v[i][j].push_back((v[i][j-1][k]+1)%4);
            }
            for (int k = 0; k < v[i][j-1].size(); k++) {
                v[i][j].push_back(v[i][j-1][k]);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    makeDragon(); //���� ���⿡ ���� 4���� ��ü ���� �巡�� Ŀ�� ����
    for (int i = 0; i < N; i++) {
        cin >> x >> y >> d >> g;
        _map[y][x] = 1;
        for (int j = 0; j <= g; j++) {
            for (int dir : v[d][j]) {
                y += dy[dir]; x += dx[dir];
                _map[y][x] = 1;
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (_map[i][j] && _map[i+1][j] && _map[i][j+1] && _map[i+1][j+1]) ret++;
        }
    }
    cout << ret << '\n';

    return 0;
}
*/