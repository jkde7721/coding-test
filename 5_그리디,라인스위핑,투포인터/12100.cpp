//�޸�: 2024KB, �ð�: 8ms
/*
�밭 �ð����⵵
(4��(�����¿�) ^ �ִ� 5�� �̵�) * 20(�ִ� ���) * 20(�ִ� �� ��) * 20(ex.�迭 ���ۿ��� ������ �̵��ϴ� ���, ����-�� ���̴� ��� 0)
= 8,192,000�� ���� (possible)
*/

/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, b[20][20], ret, y, x, ny, nx;
bool com[20][20];

void go(int cnt) {
    if (cnt == 5) {
        ret = max(ret, *max_element(&b[0][0], &b[0][0] + 400));
        return;
    }

    int tmp[20][20];
    memcpy(tmp, b, sizeof(b));
    for (int k = 0; k < 4; k++) {
        memset(com, 0, sizeof(com));
        int i = (k == 2 ? n - 1 : 0); //�Ʒ��� ���
        while ((k == 2 && i >= 0) || (k != 2 && i < n)) {
            int j = (k == 1 ? n - 1 : 0); //�������� ���
            while ((k == 1 && j >= 0) || (k != 1 && j < n)) {
                //int y = i, x = j, ny, nx; //�� ��� segfault ���� �߻�!
                y = i; x = j;
                if (k == 1) j--; else j++;
                if (b[y][x] == 0) continue;
                
                while (1) {
                    ny = y + dy[k]; nx = x + dx[k];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= n) break;
                    if (b[ny][nx] != 0) {
                        if (b[ny][nx] == b[y][x] && !com[ny][nx]) {
                            b[ny][nx] *= 2; b[y][x] = 0;
                            com[ny][nx] = 1;
                        }
                        break;
                    }
                    b[ny][nx] = b[y][x]; b[y][x] = 0;
                    y = ny; x = nx;
                }
            }
            if (k == 2) i--; else i++;
        }
        go(cnt + 1);
        memcpy(b, tmp, sizeof(tmp));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> b[i][j];
    }
    go(0);
    cout << ret << '\n';

    return 0;
}
*/

/*
Trial & Error
1. 64 32 32 �迭���� ������ �������� �̵� �� ����� 64 64�� �Ǿ�� �ϴµ�, 32 + 32�� 64�� ������ �� ���� 64�� �ٽ� ������ 128�� ��
�� ������ ��� ���� com �迭�� ����, 64 64���� �� ��� ���� ������ ������ ����� �̹� ������ ����̹Ƿ� �ٽ� ������ �� ����

2. ���� �ܰ�(ex. cnt = 1�� ��) ����� com �迭�� ���� �ܰ�(ex. cnt = 2�� ��)�� ������ ��ħ 
�� �� ����� ��(�����¿�)���� memset(com, 0, sizeof(com)); �ؼ� com �迭 0���� �ʱ�ȭ

3. ���� ��ϰ� ���� ��� ���� ���� ������ ���� ����� �̹� ������ ����� ��� break���� �ʰ� ��� ���� 
ex. 64 32 32 64 �迭���� ������ �������� �̵� �� �ùٸ� ���: 64 64 64 / �߸��� ���: 64 0 128 (64 64(������ ���) 64���� �� ���� 64�� ��� 64�� ������ 
��� ����� �̹� ������ ����̹Ƿ� break�ؾ� ��, but break���� �ʰ� ��� �����ؼ� ��� 64�� �� ������ 64�� ������)
�� ���� ��� ��(b[ny][nx])�� 0�� �ƴ� ��쿡�� �׻� break�ϵ��� ����

4. segfault ����: ����Լ�(go) �� for �� while �� while �ȿ� int y = i, x = j, ny, nx; �ش� ���� ����, �� ��� �� �ݺ����� �ش� ������ ���� �޸� �Ҵ�� ������ �߻�
�� y, x, ny, nx ������ ���������� ����

�� �迭�� �ε����� ������� Ǯ�ٺ��� �����ϰ� �Ű����� �ϴ� �κ� ���� �߻� �� ť�� �ٽ� Ǯ���
*/

//�޸�: 2028KB, �ð�: 4ms
//ť�� �̿��� Ǯ��
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, b[20][20], ret, pre;
queue<int> q;

//TODO: �����¿� �̵� �������� �ߺ� �κ� ���ֺ���
void move(int dir) {
    int j, idx = (dir == 1 || dir == 2 ? -1 : 1);
    //������, ����
    if (dir == 1 || dir == 3) {
        for (int i = 0; i < n; i++) {
            for (j = (dir == 1 ? n - 1 : 0); j >= 0 && j < n; j += idx) {
                if (b[i][j] == 0) continue;
                q.push(b[i][j]);
            }

            q.push(0);
            pre = q.front(); q.pop();
            for (j = (dir == 1 ? n - 1 : 0); j >= 0 && j < n; j += idx) {
                if (q.empty()) { b[i][j] = 0; continue; }
                if (pre == q.front()) {
                    b[i][j] = pre * 2; q.pop();
                }
                else b[i][j] = pre;
                pre = q.front(); q.pop();
            }
        }
    } 
    //��, �Ʒ�
    else {
        for (int i = 0; i < n; i++) {
            for (j = (dir == 2 ? n - 1 : 0); j >= 0 && j < n; j += idx) {
                if (b[j][i] == 0) continue;
                q.push(b[j][i]);
            }

            q.push(0);
            pre = q.front(); q.pop();
            for (j = (dir == 2 ? n - 1 : 0); j >= 0 && j < n; j += idx) {
                if (q.empty()) { b[j][i] = 0; continue; }
                if (pre == q.front()) {
                    b[j][i] = pre * 2; q.pop();
                }
                else b[j][i] = pre;
                pre = q.front(); q.pop();
            }
        }
    }
}

void go(int cnt) {
    if (cnt == 5) {
        ret = max(ret, *max_element(&b[0][0], &b[0][0] + 400));
        return;
    }
    int tmp[20][20];
    memcpy(tmp, b, sizeof(b));
    for (int k = 0; k < 4; k++) {
        move(k);
        go(cnt + 1);
        memcpy(b, tmp, sizeof(tmp));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> b[i][j];
    }
    go(0);
    cout << ret << '\n';

    return 0;
}
*/

//�޸�: 2028KB, �ð�: 4ms
//ť�� �̿��� Ǯ�� + �迭�� rotate�Ͽ� �����¿�� �̴� ������ �ߺ� ����
#include <bits/stdc++.h>
using namespace std;

int n, b[20][20], ret, pre;
queue<int> q;

void rotateAll(int a[20][20]) {
    int tmp[20][20];
    memcpy(tmp, a, sizeof(tmp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) a[i][j] = tmp[n-1-j][i];
    }
}

void move() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!b[i][j]) continue;
            q.push(b[i][j]);
        }
        q.push(0);
        pre = q.front(); q.pop();
        for (int j = 0; j < n; j++) {
            if (q.empty()) { b[i][j] = 0; continue; }
            if (pre == q.front()) {
                b[i][j] = pre * 2; q.pop();
            }
            else b[i][j] = pre;
            pre = q.front(); q.pop();
        }
    }
}

void go(int cnt) {
    if (cnt == 5) {
        ret = max(ret, *max_element(&b[0][0], &b[0][0] + 400));
        return;
    }
    int tmp[20][20];
    memcpy(tmp, b, sizeof(b));
    for (int k = 0; k < 4; k++) {
        move();
        go(cnt + 1);
        rotateAll(tmp);
        memcpy(b, tmp, sizeof(tmp));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> b[i][j];
    }
    go(0);
    cout << ret << '\n';

    return 0;
}