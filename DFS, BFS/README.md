## 그래프(Graph)

- **정점의 모음** + 이 정점을 잇는 **간선의 모음**의 집합
- 정점의 집합을 V, 간선의 집합을 E, 그래프를 G라고 했을 때 G = (V, E)
- 간선으로 연결된 두 정점을 가리켜 서로 인접(Adjacent) 또는 이웃 관계에 있다고 지칭
- 간선에 방향성이 있으면 방향성 그래프(Directed Graph) / 방향성이 없으면 무방향성 그래프(Undirected Graph)
- 무방향성 그래프에서 각 정점은 다른 모든 정점과 연결되어 있음, 즉 두 정점 사이에 경로가 항상 존재 → 트리(Tree)

### 그래프 표현 방법: 인접 행렬(Adjacency Matrix)

- 정점끼리의 인접 관계를 나타내는 행렬
- 그래프의 정점 수가 N일 때, N x N 크기의 행렬을 생성하고 A 정점과 B 정점이 인접해있다면 행렬의 (A, B), (B, A) 요소를 1로 표시, 인접해있지 않다면 0으로 표시 (무방향성 그래프인 경우) / A 정점 → B 정점의 방향으로 인접해있다면 행렬의 (A, B) 요소만 1로 표시 (방향성 그래프인 경우)
- 무방향성 그래프의 인접 행렬은 주대각선 기준 대칭
- 정점 간의 인접 여부를 빠르게 알 수 있는 반면 인접하지 않는 관계 또한 저장하기 때문에 메모리 낭비 발생

### 그래프 표현 방법: 인접 리스트(Adjacency List)

- 각 정점이 자신과 인접한 모든 정점의 목록을 리스트로 관리
- 정점 간의 인접 여부를 알아내기 위해 인접 리스트에 대한 순차 탐색이 필요한 반면 정점과 간선의 삽입이 빠르고 인접 관계에 있는 정점만을 저장하기 때문에 사용되는 메모리 양이 인접 행렬에 비해 적음

### 정리

- 공간복잡도

  - 인접행렬: O(V^2)
  - 인접리스트: O(V + E)

- 시간복잡도: 간선 한 개 탐색

  - 인접행렬: O(1)
  - 인접리스트: O(V)

- 시간복잡도: 모든 간선 탐색
  - 인접행렬: O(V^2)
  - 인접리스트: O(V + E)

<br/>

## 트리(Tree)

- 부모 노드 & 자식 노드로 이루어진 계층 구조
- 무방향 그래프이면서 사이클이 없음 → 임의의 두 노드 사이의 경로는 '유일무이'하게 반드시 존재
- E = V - 1 만족하여 간선의 개수는 정점의 개수 - 1

<br/>

## 맵(2차원 배열)에서 4방향 탐색법

- 특정 위치(y, x)에서 4방향(상하좌우)으로 탐색 → 방향 벡터(`dy`, `dx`) 사용

```c++
//위쪽부터 시계 방향으로 탐색
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
for (int i = 0; i < 4; i++) {
    ny = y + dy[i];
    nx = x + dx[i];
}
```

### 주의사항

- `ny`, `nx` 값 오버플로우, 언더플로우 체크 (인덱스 범위 벗어나는지)
- 방문 여부 체크 → 이미 방문한 노드라면 재방문X, 해당 노드 탐색 시 `visited` 배열로 방문 표시 (체크하지 않으면 무한 루프로 stack overflow 발생)
- (문제 조건에 따라) 해당 `ny`, `nx` 위치가 탐색 가능한 곳인지 확인 ex. 해당 `ny`, `nx` 위치에 벽이 있으면 탐색 불가

```c++
const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m; //n은 세로 길이, m은 가로 길이
for (int i = 0; i < 4; i++) {
    ny = y + dy[i];
    nx = x + dx[i];
    if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
    if (visited[ny][nx]) continue;
    if (_map[ny][nx] == 0) continue; //해당 위치 탐색 불가
}
```

<br/>

## 그래프 탐색 알고리즘

### DFS(깊이 우선 탐색, Depth First Search)

- 루트 노드(혹은 다른 임의의 노드)에서 시작해 다음 분기(branch)로 넘어가기 전 해당 분기를 완벽하게 탐색하는 알고리즘
- 모든 노드를 방문하고자 하는 경우에 적합
- 스택 또는 재귀함수로 구현
- 현재 정점에서 갈 수 있는 정점까지 들어가면서 탐색, 더이상 가지못하면 바닥 찍고 이전 정점으로 되돌아옴
- 대표 문제 [1012번 유기농 배추](https://www.acmicpc.net/problem/1012)

```c++
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int t, n, m, k, y, x, ret, field[50][50];
bool visited[50][50];

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || !field[ny][nx]) continue; //값이 1인 지점만 탐색 가능
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> t;
    while (t--) {
        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));
        ret = 0;
        cin >> m >> n >> k;
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            field[y][x] = 1;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] && !visited[i][j]) {
                    dfs(i, j); //연결된 하나의 덩어리를 DFS로 탐색
                    ret++; //덩어리 개수 count
                }
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
```

→ **연결된 컴포넌트(Connected Component) 문제**: 연결된 하나의 덩어리를 하나씩 DFS로 탐색하면서 덩어리 개수 count (BFS 풀이도 가능)

<br/>

### BFS(너비 우선 탐색, Breadth First Search)

- 루트 노드(혹은 다른 임의의 노드)에서 시작해 인접한 노드를 먼저 탐색하는 알고리즘
- **같은 가중치**를 가진 그래프에서 최단거리 알고리즘으로 사용 → 최단거리 저장하는 `visited` 배열 필요
- 큐를 이용하여 구현
- 대표 문제 [2178번 미로 탐색](https://www.acmicpc.net/problem/2178)

```c++
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, miro[100][100], visited[100][100], y, x;
queue<pair<int, int>> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }
    //시작 지점
    visited[0][0] = 1;
    q.push({0, 0});
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || miro[ny][nx] == 0) continue; //미로에서 0은 이동할 수 없는 칸
            if (visited[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1; //다음 지점(ny, nx)까지의 최단거리 = 현재 지점(y, x)까지의 최단거리 + 1
        }
    }
    printf("%d\n", visited[n - 1][m - 1]);
    return 0;
}
```

<br/>

### 정리

- 그래프의 모든 정점을 방문하는 문제에서는 DFS, BFS 모두 가능 but 완전탐색은 **DFS**가 좀 더 적합
- 경로의 특징을 저장해야 하는 문제 ex. 각 정점에 숫자가 적혀있고 U ~ V까지의 경로를 구하는데 경로에 같은 숫자가 있으면 안되는 문제([1987번 알파벳](https://www.acmicpc.net/problem/1987)) → **DFS** (BFS는 경로의 특징 저장 불가)
- 가중치가 같은 최단거리 구하는 문제 → **BFS**
- 탐색 대상 그래프가 매우 크다면 **DFS** 고려
- 탐색 대상의 규모가 크지 않고, 탐색 시작 정점으로부터 원하는 대상이 별로 멀지 않다면 **BFS** 고려

> 문제에서 "퍼져나간다", "탐색한다" 키워드 있으면 DFS 혹은 BFS
