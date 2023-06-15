//�޸�: 2036KB, �ð�: 16ms
#include <iostream>
#include <tuple>
#include <vector>
#include <cstring>
using namespace std;

const int dyi[] = {0, 1, 0, -1}, dxi[] = {1, 0, -1, 0};
const int dyo[] = {1, 0, -1, 0}, dxo[] = {0, 1, 0, -1};
int n, m, a[51][51], k, r, c, s, ret = 987654321, sum;
vector<tuple<int, int, int>> v;
vector<int> tmp;
bool rot[6];

//���� vector ���� �ʰ� index �����Ͽ� ������ ȸ����Ű�� �͵� �������� ������
//���� �Ʒ� �������� �ߺ� ����
void rotate(int r, int c, int s) {
    int sy = r - s, sx = c - s, w = s*2, y, x, ny, nx, idx; 
    while (sy < r && sx < c) {
        y = sy, x = sx; idx = 0;
        do {
            tmp.push_back(a[y][x]);
            ny = y + dyi[idx]; nx = x + dxi[idx];
            if (ny < sy || ny > sy + w || nx < sx || nx > sx + w) { idx++; continue; }
            y = ny; x = nx;
        } while(y != sy || x != sx);

        idx = 0;
        do {
            a[y][x] = tmp.back(); tmp.pop_back();
            ny = y + dyo[idx]; nx = x + dxo[idx];
            if (ny < sy || ny > sy + w || nx < sx || nx > sx + w) { idx++; continue; }
            y = ny; x = nx;
        } while(y != sy || x != sx);

        sy++; sx++; w -= 2;
    }
}

void go(int cnt) {
    if (cnt == k) {
        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = 0; j < m; j++) sum += a[i][j];
            ret = min(ret, sum);
        }
        return;
    }

    int tmp[51][51];
    memcpy(tmp, a, sizeof(a));
    for (int i = 0; i < k; i++) {
        if (rot[i]) continue;
        tie(r, c, s) = v[i];
        rotate(r, c, s); rot[i] = 1;
        go(cnt + 1);
        memcpy(a, tmp, sizeof(tmp));
        rot[i] = 0;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> a[i][j];
    }
    for (int i = 0; i < k; i++) {
        cin >> r >> c >> s;
        v.push_back({r-1, c-1, s});
    }
    go(0);
    cout << ret << '\n';

    return 0;
}