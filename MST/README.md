## 최소 신장 트리(MST, Minimum Spanning Tree)

### 스패닝 트리(Spanning Tree)

> G = (V, E)인 그래프에서 최소 개수의 간선으로 모든 정점을 연결하는 비순환 그래프, 즉 그래프의 모든 정점을 연결하는 부분 그래프 중 트리

- 정점의 개수가 N인 연결 그래프 G에서 스패닝 트리의 간선 개수는 항상 N-1
- 즉 연결 그래프에서 트리의 정의 '모든 정점이 N-1 개의 간선으로 연결된(모든 정점 간 경로가 존재) 비순환 그래프'를 만족시키는 정점과 간선들의 부분 집합
- 연결 그래프에서 스패닝 트리는 여러 개 존재

  <img src="https://github.com/jkde7721/coding-test/assets/65665065/331dbfa4-d5be-44bb-9e43-e69caab45883" width="55%"/>

### 최소 스패닝 트리(Minimum Spanning Tree)

> 연결 그래프에서 간선의 가중치 합이 최소인 스패닝 트리, 즉 그래프의 모든 정점을 연결하는 부분 그래프 중 간선의 가중치 합이 최소인 트리

<br/>

## 구현 알고리즘

- **가장 간단한 방법**: 가능한 모든 스패닝 트리의 가중치 합을 계산하여 MST를 찾음 → 시간초과
- **그리디한 방법**: 지역적으로 가중치가 최소인 간선을 선택하다 보면 MST를 찾음

### Kruskal 알고리즘

- **간선 선택**을 기반으로 하는 알고리즘
- 이전 단계에서 만들어진 신장 트리와는 상관없이 **무조건 최소 간선만을 선택**하는 방법
- 각 단계에서 **사이클을 이루지 않는 최소 가중치 간선을 선택**
- 간선이 가중치의 오름차순으로 정렬되어 주어진다면 O(E)의 시간복잡도
- 간선이 무작위 순서로 주어진다면 정렬에 의해 O(ElogE)의 시간복잡도
- 정점의 개수에 비해 간선의 개수가 적은 경우에 적합 (그래프가 Sparse한 경우)

1. 그래프의 간선들을 가중치의 오름차순으로 정렬
2. 정렬된 간선 리스트에서 사이클을 형성하지 않는 간선 선택 (즉 가중치가 작은 간선을 먼저 선택)
3. 해당 간선을 현재의 MST 집합에 추가

❗중요❗**간선 선택 시 사이클 생성 여부 확인**

- 새로운 간선이 이미 다른 경로에 의해 서로 연결된 정점들을 연결할 경우 사이클 형성
- 추가할 새로운 간선의 양끝 정점이 같은 MST 집합에 속해있으면 해당 간선으로 인해 사이클 형성 → 해당 간선 선택 불가

➡️ **Union-Find 알고리즘**으로 정점이 속한 집합 확인

<br/>

### Union-Find(합집합 찾기)

> 여러 원소가 존재할 때 임의의 두 원소가 서로 같은 집합에 속하는지 판별하는 알고리즘

- Disjoint Set을 표현하기 위한 알고리즘

  _Disjoint Set: 공통 원소가 없는 즉 상호 배타적인 부분 집합들로 나눠진 자료구조 (서로소 집합 자료구조)_

- 집합을 구현하기 위해 가장 효율적인 트리 자료구조를 사용

  - 같은 집합 = 하나의 트리
  - 집합 번호 = 루트 노드 번호

- **Union 연산**: 두 개의 서로 다른 집합을 하나의 집합으로 합침
- **Find 연산**: 특정 원소가 속한 집합을 찾음

**예시**

- **초기 상태**: 자기 자신이 루트 노드이면서 리프 노드인 N개의 트리 존재 (N은 노드 개수)

  | 노드 번호      | 1   | 2   | 3   | 4   | 5   |
  | -------------- | --- | --- | --- | --- | --- |
  | 루트 노드 번호 | 1   | 2   | 3   | 4   | 5   |

- **노드 1과 2가 연결**

  | 노드 번호      | 1   | 2   | 3   | 4   | 5   |
  | -------------- | --- | --- | --- | --- | --- |
  | 루트 노드 번호 | 1   | 1   | 3   | 4   | 5   |

  _노드를 연결할 때는 일반적으로 더 작은 번호의 노드 쪽으로 합침 (알관성만 있으면 됨)_

- **노드 2와 3이 연결**

  | 노드 번호      | 1   | 2   | 3   | 4   | 5   |
  | -------------- | --- | --- | --- | --- | --- |
  | 루트 노드 번호 | 1   | 1   | 1   | 4   | 5   |

**코드 구현**

```c++
#include <bits/stdc++.h>
#define N 10
using namespace std;

int root[N]; //해당 노드의 최상위 부모 노드(루트 노드) 번호 저장

//자기 자신이 루트 노드이면서 리프 노드인 N개의 트리 생성
void init() {
    for (int i = 0; i < N; i++) root[i] = i;
}

//해당 노드가 속한 트리의 루트 노드 번호 반환 - 경로 압축으로 O(1) 시간복잡도 보장
int _find(int node) {
    if (root[node] == node) return node;
    return root[node] = _find(root[node]); //경로 압축(https://www.acmicpc.net/board/view/108031) 중요
}

//트리 합침 (두 노드 연결)
void _union(int node1, int node2) {
    root[_find(node1)] = _find(node2); //한 트리의 루트 노드를 다른 트리의 루트 노드로 연결
}

//두 노드가 같은 트리에 속하는지 확인 (두 노드가 연결되어 있는지 확인)
bool isConn(int node1, int node2) {
    return _find(node1) == _find(node2);
}
```

<br/>

### Prim 알고리즘

- **정점 선택**을 기반으로 하는 알고리즘
- 임의의 정점으로부터 시작하여 **신장 트리를 단계적으로 확장**
- 일반적으로 O(ElogV)의 시간복잡도
- 간선의 개수에 비해 정점의 개수가 적은 경우에 적합 (그래프가 Dense한 경우)

1. 처음에는 시작 정점만이 MST 집합에 포함
2. 앞 단계의 MST 집합의 인접한 정점들 중 최소 가중치의 간선으로 연결된 정점을 선택하여 트리를 확장 (즉 가중치가 작은 간선을 먼저 선택)
3. 위 과정을 모든 정점에 방문할 때까지 반복

❗중요❗**정점 선택 시 사이클 생성 여부 확인**

- 방문했던 정점을 다시 방문하면 사이클 생성
- `visited` 배열로 정점 방문 여부 관리

<br/>

### 대표 문제

- [1197번 최소 스패닝 트리](https://www.acmicpc.net/problem/1197)
- [1922번 네트워크 연결](https://www.acmicpc.net/problem/1922)

<br/>

### 참고

[최소 신장 트리(MST, Minimum Spanning Tree)란](https://gmlwjd9405.github.io/2018/08/28/algorithm-mst.html)

[크루스칼 알고리즘(Kruskal Algorithm)](https://www.youtube.com/watch?v=LQ3JHknGy8c)

[Union-Find 알고리즘](https://www.youtube.com/watch?v=AMByrd53PHM)

[프림 알고리즘(Prim Algorithm)](https://www.weeklyps.com/entry/%ED%94%84%EB%A6%BC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Prims-algorithm#d8)