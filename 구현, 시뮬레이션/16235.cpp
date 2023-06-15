//메모리: 2328KB, 시간: 88ms
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, -1, -1, 0, 1, 1, 1, 0}, dx[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int n, m, k, a[11][11], land[11][11], x, y, z;
deque<int> tree[11][11];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    }
    for (int i = 0; i < m; i++) {
        cin >> y >> x >> z;
        tree[y][x].push_back(z);
    }

    fill(&land[0][0], &land[0][0] + 11*11, 5);
    while (k--) {
        //봄: 나무가 자신의 나이만큼 양분 먹음 → 나이 증가, 여름: 죽은 나무를 양분으로 
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= n; x++) {
                int tmp = 0, cnt = 0;
                for (int k = 0; k < tree[y][x].size(); k++) {
                    if (land[y][x] >= tree[y][x][k]) {
                        land[y][x] -= tree[y][x][k]++;
                    }
                    else { tmp += tree[y][x][k] / 2; cnt++; }
                }
                land[y][x] += tmp;
                while (cnt--) tree[y][x].pop_back();
            }
        }
        //가을: 5의 배수 나이의 나무 번식
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= n; x++) {
                for (int age : tree[y][x]) {
                    if (age % 5 == 0) {
                        int ny, nx;
                        for (int k = 0; k < 8; k++) {
                            ny = y + dy[k]; nx = x + dx[k];
                            if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
                            tree[ny][nx].push_front(1);
                        }
                    }
                }
            }
        }
        //겨울: 땅에 양분 추가
        for (int y = 1; y <= n; y++) {
            for (int x = 1; x <= n; x++) {
                land[y][x] += a[y][x];
            }
        }
    }
    //살아남은 나무의 수
    int ret = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ret += tree[i][j].size();
        }
    }
    cout << ret << '\n';
    
    return 0;
}