//메모리: 2048KB, 시간: 4ms
#include <bits/stdc++.h>
using namespace std;

//key 배열: 해당 열쇠 획득 여부 저장
//door 배열: 해당 문을 열 수 있는 열쇠가 현재는 없지만, 나중에 열쇠 획득 시 오픈할 문의 위치 저장
//문 도착X, 키X / 문 도착O, 키X / 문 도착X, 키O / 문 도착O, 키 O → 이 경우에만 큐에 push하고 방문 처리
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int t, h, w, y, x, ny, nx, cnt;
bool key[26], visited[100][100];
string k;
char _map[100][100], c;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        memset(key, 0, sizeof(key)); memset(visited, 0, sizeof(visited));
        vector<pair<int, int>> door[26]; cnt = 0;
        cin >> h >> w;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> c; _map[i][j] = c;
                if (i == 0 || i == h-1 || j == 0 || j == w-1) { //가장자리 체크
                    if (c >= 'A' && c <= 'Z') door[c - 'A'].push_back({i, j}); //문
                    else if (c != '*') {
                        if (c >= 'a' && c <= 'z') key[c - 'a'] = 1; //열쇠
                        else if (c == '$') cnt++; //문서
                        q.push({i, j}); visited[i][j] = 1;
                    }
                }
            }
        }
        cin >> k;
        if (k != "0") {
            for (char c : k) key[c - 'a'] = 1;
        }
        //현재까지 획득한 열쇠로 가장자리 문 열 수 있는지 확인
        for (int i = 0; i < 26; i++) {
            if (!key[i]) continue;
            for (auto& it : door[i]) { q.push(it); visited[it.first][it.second] = 1; }
        }
        while (q.size()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i]; nx = x + dx[i];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w || _map[ny][nx] == '*' || visited[ny][nx]) continue;
                c = _map[ny][nx];
                //문에 도착해서 열쇠 없으면, 나중에 열쇠 획득하면 오픈할 곳으로 저장
                if (c >= 'A' && c <= 'Z' && !key[c - 'A']) { door[c - 'A'].push_back({ny, nx}); continue; }
                //해당 열쇠 없는 상태에서 획득하면, 열 수 있는 문 OPEN
                else if (c >= 'a' && c <= 'z' && !key[c - 'a']) {
                    key[c - 'a'] = 1;
                    for (auto& it : door[c - 'a']) { q.push(it); visited[it.first][it.second] = 1; }
                }
                else if (c == '$') cnt++;
                q.push({ny, nx}); visited[ny][nx] = 1;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}