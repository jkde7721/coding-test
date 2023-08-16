//분리 집합으로 사이클 찾는 풀이
//메모리: 7020KB, 시간: 32ms
//생성되는 사이클의 개수를 카운트 
//DFS마다 분리 집합 구성 → DFS 중 현재 분리 집합에 속한 노드로 가게 되면 사이클 형성
#include <bits/stdc++.h>
using namespace std;

int n, m, zone, idx = 1, disjoint[1000][1000];
string _map[1000];

void dfs(int y, int x) {
    disjoint[y][x] = idx;
    int ny = y, nx = x;
    if (_map[y][x] == 'U') ny--;
    else if (_map[y][x] == 'D') ny++;
    else if (_map[y][x] == 'L') nx--;
    else nx++;
    if (!disjoint[ny][nx]) dfs(ny, nx); 
    else if (disjoint[ny][nx] == idx) zone++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> _map[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!disjoint[i][j]) { dfs(i, j); idx++; }
        }
    }
    cout << zone << '\n';   
    return 0;
}

//DFS로 사이클 찾는 풀이
//메모리: 7880KB, 시간: 44ms
/*
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, zone, _map[1000][1000]; //지도 밖으로 나가는 방향은 없으므로 어떻게든 사이클에 휘말림
char tmp; 
bool visited[1000][1000], finished[1000][1000];

void dfs(int y, int x) {
    visited[y][x] = 1;
    int ny = y + dy[_map[y][x]], nx = x + dx[_map[y][x]];
    if (!visited[ny][nx]) dfs(ny, nx);
    else if (!finished[ny][nx]) zone++; //visited는 true인데 finished는 false이면 사이클 형성
    finished[y][x] = 1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (tmp == 'U') _map[i][j] = 0;
            else if (tmp == 'D') _map[i][j] = 2;
            else if (tmp == 'L') _map[i][j] = 3;
            else _map[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) dfs(i, j);
        }
    }
    cout << zone << '\n';
    return 0;
}
*/