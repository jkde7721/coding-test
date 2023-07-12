## 최소 신장 트리(MST, Minimum Spanning Tree)

### 스패닝 트리(Spanning Tree)

> G = (V, E)인 그래프에서 최소 개수의 간선으로 모든 정점을 연결하는 비순환 그래프, 즉 G의 모든 정점을 연결하는 부분 그래프 중 간선 개수가 최소인 트리

- 정점의 개수가 N인 그래프 G에서 스패닝 트리의 간선 개수는 항상 N-1
- 즉 그래프에서 트리의 정의 '모든 정점이 N-1 개의 간선으로 연결된(모든 정점 간 경로가 존재) 비순환 그래프'를 만족시키는 정점과 간선들의 부분 집합
- 그래프에서 스패닝 트리는 여러 개 존재

### 최소 스패닝 트리(Minimum Spanning Tree)

> 가중치가 있는 그래프에서 가중치 합이 최소인 스패닝 트리

- 즉 그래프의 모든 정점을 연결하는 부분 그래프 중 간선 개수가 최소이면서 간선의 가중치 합 또한 최소인 트리

<br/>

## 구현 알고리즘

- 가장 간단한 방법: 가능한 모든 스패닝 트리를 찾아 가중치 합의 최소값을 계산 → Exponential
- 그리디한 방법: 지역적으로 가중치가 제일 작은 간선을 선택하면 전역적인 MST를 찾을 수 있음

### Kruskal 알고리즘

- 간선 선택을 기반으로 하는 알고리즘
- 이전 단계에서 만들어진 신장 트리와는 상관없이 무조건 최소 간선만을 선택하는 방법
- 각 단계에서 사이클을 이루지 않는 최소 가중치 간선을 선택

1. 그래프의 간선들을 가중치의 오름차순으로 정렬
2. 정렬된 간선 리스트에서 사이클을 형성하지 않는 간선 선택 (즉 가중치가 작은 간선을 먼저 선택)
3. 해당 간선을 현재의 MST 집합에 추가

**간선 선택 시 사이클 생성 여부 확인**

- 새로운 간선이 이미 다른 경로에 의해 서로 연결된 정점들을 연결할 경우 사이클 형성
- 추가할 새로운 간선의 양끝 정점이 같은 MST 집합에 속해있으면 해당 간선으로 인해 사이클 형성

➡️ **union-find 알고리즘**을 통해 정점이 속한 집합 확인

<br/>

### Union-Find(합집합 찾기)

> 여러 노드가 존재할 때 임의의 2개 노드가 서로 같은 트리에 속하는지 판별하는 알고리즘

- Disjoint Set을 표현하기 위한 알고리즘

  _Disjoint Set: 공통 원소가 없는 즉 상호 배타적인 부분 집합들로 나눠진 자료구조 (서로소 집합 자료구조)_

- 집합을 구현하기 위해 가장 효율적인 트리 자료구조를 사용

  - 같은 집합 = 하나의 트리
  - 집합 번호 = 루트 노드 번호

- Union 연산: 두 개의 서로 다른 집합을 하나의 집합으로 합침
- Find 연산: 특정 요소가 속한 집합을 찾음

- Union-Find 연산

  - `init()`: 각 원소를 유일한 원소로 하는 N개의 집합 생성(N은 원소 개수), 즉 각 노드가 루트 노드이면서 리프 노드인 N개의 트리 생성 (N은 노드 개수)
  - `_union(node1, node2)`: node1가 속한 집합과 node2가 속한 집합을 합침, 즉 node1 노드와 node2 노드를 연결하여 트리를 합치는 연산
  - `_find(node)`: node가 어떤 집합에 속해있는지 찾는 연산, 즉 node의 최상위 부모 노드(루트 노드)의 번호 반환
  - `isConn(node1, node2)`: node1이 속한 집합과 node2가 속한 집합이 같은지 확인, 즉 node1 노드와 node2 노드가 서로 연결되어 같은 트리에 속하는지 확인

- `_union` 함수의 `root[node1] = root[parent1] = root[node2] = root[parent2] = min(parent1, parent2)` 부분

  - 합쳐지는 트리의 루트 노드의 root 배열 값도 바꿔주어야 함 (바꿔주지 않으면 연결된 트리의 각 루트 노드 간 연결이 없는 것으로 판단)
  - 합져지는 트리 내 모든 노드의 root 배열 값을 모두 바꿔줄 필요 없이 루트 노드의 root 배열 값만 바꿔줘도 됨 (`_find` 함수에 의해 알아서 경로 압축)

  ```
  5 5
  1 4 3
  2 3 3
  4 3 5
  2 1 6
  4 5 9
  정답: 20
  오답: 26
  ```

- 예시
  **초기 상태**: 자기 자신이 루트 노드이면서 리프 노드인 N개의 트리 (N은 노드 개수)

  | 노드 번호      | 1   | 2   | 3   | 4   | 5   |
  | -------------- | --- | --- | --- | --- | --- |
  | 루트 노드 번호 | 1   | 2   | 3   | 4   | 5   |

  **노드 1과 2가 연결**

  | 노드 번호      | 1   | 2   | 3   | 4   | 5   |
  | -------------- | --- | --- | --- | --- | --- |
  | 루트 노드 번호 | 1   | 1   | 3   | 4   | 5   |

  _노드를 연결할 때는 일반적으로 더 작은 번호의 노드 쪽으로 합침 (알관성만 있으면 됨)_

  **노드 2와 3이 연결**

  | 노드 번호      | 1   | 2   | 3   | 4   | 5   |
  | -------------- | --- | --- | --- | --- | --- |
  | 루트 노드 번호 | 1   | 1   | 1   | 4   | 5   |

- 코드 구현

  ```c++
  #include <bits/stdc++.h>
  #define N 10
  using namespace std;

  int root[N]; //항상 해당 노드의 최상위 부모 노드(루트 노드) 번호만을 저장하고 있진 않음
  //즉 부모 노드 번호를 저장하고 있다가 _find 호출 시 루트 노드 번호로 업데이트될 수 있음
  //ex. 2-6 노드 연결 상태에서 1-2 노드 연결한 경우 6번 노드의 root[6] 값은 1이 아닌 2

  //자기 자신이 루트 노드이면서 리프 노드인 N개의 트리 생성
  void init() {
      for (int i = 0; i < N; i++) root[i] = i;
  }

  //노드가 속한 트리의 루트 노드 번호 반환 - 경로 압축으로 O(1) 시간복잡도 보장
  int _find(int node) {
      if (root[node] == node) return node;
      return root[node] = _find(root[node]); //경로 압축(https://www.acmicpc.net/board/view/108031) 안하면 시간초과
  }

  //트리 합침(두 노드 연결)
  void _union(int node1, int node2) {
    int parent1 = _find(node1), parent2 = _find(node2);
    if (parent1 != parent2) {
        root[node1] = root[parent1] = root[node2] = root[parent2] = min(parent1, parent2); //더 작은 번호의 부모 노드 선택
    }
  }

  //두 노드가 같은 트리에 속하는지 확인(두 노드가 연결되어 있는지 확인)
  bool isConn(int node1, int node2) {
      return _find(node1) == _find(node2);
  }
  ```

<br/>

### Prim 알고리즘

- 정점 선택을 기반으로 하는 알고리즘
- 이전 단계에서 만들어진 신장 트리를 확장하는 방법
- 임의의 시작 정점에서부터 출발하여 신장 트리 집합을 단계적으로

1. 시작 단계에서는 시작 정점만이 MST 집합에 포함
2. 앞 단계의 MST 집합의 인접합 정점들 중 최소 가중치의 간선으로 연결된 정점을 선택하여 트리를 확장 (즉 가중치가 작은 간선을 먼저 선택)
3. 위 과정을 트리가 N-1 개의 간선을 가질 때까지 반복

얘도 사이클 생성 여부 확인해야 하지 않나? `visited` 배열로 확인

**코드 구현**

```c++
#include <bits/stdc++.h>
using namespace std;

int v, e, a, b, c, ret;
bool visited[10001];
vector<pair<int, int>> adj[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    pq.push({0, 1}); //임의의 시작 노드
    while (pq.size()) {
        tie(c, b) = pq.top(); pq.pop();
        if (visited[b]) continue; //사이클 생성
        ret += c; visited[b] = 1;
        for (auto it : adj[b]) {
            if (visited[it.first]) continue;
            pq.push({it.second, it.first});
        }
    }
    cout << ret << '\n';

    return 0;
}
```

<br/>

### 참고

[최소 신장 트리(MST, Minimum Spanning Tree)란](https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html)

[크루스칼 알고리즘(Kruskal Algorithm)](https://www.youtube.com/watch?v=LQ3JHknGy8c)

[Union-Find 알고리즘](https://www.youtube.com/watch?v=AMByrd53PHM&list=PLRx0vPvlEmdDHxCvAQS1_6XV4deOwfVrz&index=19)
