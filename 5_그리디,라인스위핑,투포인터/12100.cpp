//메모리: 2024KB, 시간: 8ms
/*
대강 시간복잡도
(4번(상하좌우) ^ 최대 5번 이동) * 20(최대 행수) * 20(최대 열 수) * 20(ex.배열 시작에서 끝으로 이동하는 경우, 시작-끝 사이는 모두 0)
= 8,192,000번 연산 (possible)
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
        int i = (k == 2 ? n - 1 : 0); //아래인 경우
        while ((k == 2 && i >= 0) || (k != 2 && i < n)) {
            int j = (k == 1 ? n - 1 : 0); //오른쪽인 경우
            while ((k == 1 && j >= 0) || (k != 1 && j < n)) {
                //int y = i, x = j, ny, nx; //이 경우 segfault 오류 발생!
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
1. 64 32 32 배열에서 오른쪽 방향으로 이동 시 결과가 64 64가 되어야 하는데, 32 + 32가 64로 합쳐진 뒤 뒤의 64와 다시 합쳐져 128이 됨
→ 합쳐진 블록 여부 com 배열로 관리, 64 64에서 두 블록 값이 같더라도 오른쪽 블록은 이미 합쳐진 블록이므로 다시 합쳐질 수 없음

2. 이전 단계(ex. cnt = 1일 때) 결과의 com 배열이 다음 단계(ex. cnt = 2일 때)에 영향을 미침 
→ 매 경우의 수(상하좌우)마다 memset(com, 0, sizeof(com)); 해서 com 배열 0으로 초기화

3. 현재 블록과 다음 블록 값이 서로 같지만 다음 블록이 이미 합쳐진 블록인 경우 break하지 않고 계속 진행 
ex. 64 32 32 64 배열에서 오른쪽 방향으로 이동 시 올바른 결과: 64 64 64 / 잘못된 결과: 64 0 128 (64 64(합쳐진 블록) 64에서 맨 왼쪽 64는 가운데 64와 같으나 
가운데 블록은 이미 합쳐진 블록이므로 break해야 함, but break하지 않고 계속 진행해서 가운데 64와 맨 오른쪽 64가 합쳐짐)
→ 다음 블록 값(b[ny][nx])이 0이 아닌 경우에는 항상 break하도록 수정

4. segfault 오류: 재귀함수(go) → for → while → while 안에 int y = i, x = j, ny, nx; 해당 선언문 존재, 이 경우 매 반복마다 해당 변수에 대한 메모리 할당과 해제가 발생
→ y, x, ny, nx 변수를 전역변수로 선언

→ 배열의 인덱스를 기반으로 풀다보니 세세하게 신경써줘야 하는 부분 많이 발생 → 큐로 다시 풀어보기
*/

//메모리: 2028KB, 시간: 4ms
//큐를 이용한 풀이
/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

int n, b[20][20], ret, pre;
queue<int> q;

//TODO: 상하좌우 이동 로직에서 중복 부분 없애보기
void move(int dir) {
    int j, idx = (dir == 1 || dir == 2 ? -1 : 1);
    //오른쪽, 왼쪽
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
    //위, 아래
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

//메모리: 2028KB, 시간: 4ms
//큐를 이용한 풀이 + 배열을 rotate하여 상하좌우로 미는 로직의 중복 제거
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