//�޸�: 2020KB, �ð�: 988ms
/*
#include <iostream>
using namespace std;

int n, m, h, y, x, ladder[31][11], ret = 987654321;

bool isOk() {
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int j = 1; j <= h; j++) {
            if (ladder[j][cur]) cur = ladder[j][cur];
        }
        if (cur != i) return false;
    }
    return true;
}

void build(int hor, int ver, int cnt) {
    if (cnt > ret || cnt > 3) return;
    if (isOk()) {
        ret = min(ret, cnt);
        return;
    }

    for (int i = hor; i <= h; i++) {
        for (int j = ver; j < n; j++) {
            if (ladder[i][j] || ladder[i][j + 1]) continue;
            ladder[i][j] = j + 1;
            ladder[i][j + 1] = j;
            build(i, j + 2, cnt + 1);
            ladder[i][j] = 0;
            ladder[i][j + 1] = 0;
        }
        ver = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> y >> x;
        ladder[y][x] = x + 1;
        ladder[y][x + 1] = x;
    }
    build(1, 1, 0);
    cout << (ret == 987654321 ? -1 : ret) << '\n';

    return 0;
}
*/

//�޸�: 2020KB, �ð�: 876ms
/*
#include <iostream>
#define INF 987654321
using namespace std;

int n, m, h, a, b, ladder[31][11], ret = INF;

bool check() {
    int tmp;
    for (int i = 1; i <= n; i++) {
        tmp = i;
        for (int j = 1; j <= h; j++) {
            if (ladder[j][tmp]) tmp = ladder[j][tmp];
        }
        if (tmp != i) return false;
    }
    return true;
}

void go(int y, int x, int cnt) {
    if (cnt > 3 || cnt >= ret) return;
    if (check()) { ret = min(ret, cnt); return; }

    for (int i = y; i <= h; i++) {
        for (int j = x; j < n;) {
            if (ladder[i][j]) { j += 2; continue; }
            if (ladder[i][j + 1]) { j += 3; continue; }
            ladder[i][j] = j + 1;
            ladder[i][j + 1] = j;
            go(i, j + 2, cnt + 1);
            ladder[i][j] = 0;
            ladder[i][j + 1] = 0;
            j++;
        }
        x = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ladder[a][b] = b + 1;
        ladder[a][b + 1] = b;
    }
    go(1, 1, 0);
    cout << (ret == INF ? -1 : ret) << '\n';
    
    return 0;
}
*/

//�ð� 0ms�� ���̱�
//�޸�: 2020KB, �ð�: 20ms
#include <iostream>
#define INF 987654321
using namespace std;

int n, m, h, a, b, ladder[31][11], ret = INF;

bool check() {
    int tmp;
    for (int i = 1; i <= n; i++) {
        tmp = i;
        for (int j = 1; j <= h; j++) {
            if (ladder[j][tmp]) tmp = ladder[j][tmp];
        }
        if (tmp != i) return false;
    }
    return true;
}

//���ڷ� x, y �ѱ�� for���� i, j�� �� ������ �ʱ�ȭ �ϸ� Ʋ��
//�̷��� ���ٰ� ��ٸ��� �����Ŀ� ���� a, b�� ���� �޶��� �� �ֱ� ����
//�Է�: 3 2 4 1 1 2 2 �غ��� (��: 2)
void go(int cnt) {
    if (cnt > 3 || cnt >= ret) return;
    if (check()) { ret = min(ret, cnt); return; }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= h; j++) {
            if (ladder[j][i] || ladder[j][i + 1]) continue;
            ladder[j][i] = i + 1;
            ladder[j][i + 1] = i;
            go(cnt + 1);
            ladder[j][i] = 0;
            ladder[j][i + 1] = 0;
            //���� ���� a��� b�� ���̿��� �յڷ� ��ٸ� ������, a�࿡ ��ٸ� ������ b�࿡ ��ٸ� ������ same �� skip
            while (j <= h && !ladder[j][i] && !ladder[j][i + 1]) j++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        ladder[a][b] = b + 1;
        ladder[a][b + 1] = b;
    }
    go(0);
    cout << (ret == INF ? -1 : ret) << '\n';
    
    return 0;
}