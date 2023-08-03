## 강결합 요소(SCC, Strongly Connected Component)

> 방향 그래프의 특정 정점 u과 v에 대해 양방향 경로가 있을 때, u와 v가 속한 최대의 컴포넌트

**특징**

- 같은 SCC 내 임의의 두 정점 u, v 사이의 양방향 경로는 항상 존재
- SCC 끼리는 사이클 존재하지 않음: 서로 다른 SCC 내 임의의 두 정점 A, B 사이의 양방향 경로 존재하지 않음 (만약 존재한다면 A, B의 SCC는 같음)

**대표문제**

[Strongly Connected Component](https://www.acmicpc.net/problem/2150)

<br/>

### 코사라주 알고리즘(Kosaraju Algorithm)

- DFS를 총 2번 수행
- 타잔 알고리즘에 비해 easy
- O(V+E)의 시간복잡도

**작동 원리**

1. 정방향 그래프를 DFS하며 탐색이 끝나는 정점 순서대로 스택에 push
2. 스택에서 pop하는 순서대로 역방향 그래프(원래 그래프의 모든 간선 방향을 뒤집은 그래프)에서 DFS 수행
3. DFS하며 탐색되는 모든 정점들을 같은 SCC로 묶음
4. 스택이 빌 때까지 반복

- 원래 그래프와 역방향 그래프의 SCC가 동일하다는 점을 이용
- 정방향 DFS가 늦게 종료되는 정점부터 역방향 DFS 수행 (늦게 종료되는 정점은 다른 정점과 가장 많이 연결되어 있음, 해당 정점에서 갈 수 있는 정점이 많음) → 해당 정점과 양방향으로 연결된 정점들을 최대로 찾음

**소스 코드**

```c++
void dfs(int node) {
    visited[node] = 1;
    for (int i : adj[node]) {
        if (visited[i]) continue;
        dfs(i);
    }
    stk.push(node); //DFS 종료 시점에 스택에 push
}

void rdfs(int node, vector<int>& v) {
    visited[node] = 1; v.push_back(node); //SCC 구성
    for (int i : radj[node]) {
        if (visited[i]) continue;
        rdfs(i, v);
    }
}

int main() {
    //주요 로직
    for (int i = 1; i <= v; i++) {
        if (visited[i]) continue;
        dfs(i);
    }
    memset(visited, 0, sizeof(visited));
    while (stk.size()) {
        if (!visited[stk.top()]) {
            vector<int> v;
            rdfs(stk.top(), v);
            scc.push_back(v);
        }
        stk.pop();
    }
    return 0;
}
```

<br/>

### 타잔 알고리즘(Tarjan Algorithm)

- 코사라주 알고리즘과 달리 1번의 DFS만 수행
- O(V+E)의 시간복잡도
- 코사라주 알고리즘은 현재 정점의 인접 정점을 모두 방문한 후(DFS 종료 시점에) 스택에 push하는 반면, 타잔 알고리즘은 현재 정점에 방문하자마자 스택에 push

**작동 원리**

1. DFS를 수행하며 아직 방문하지 않은 정점들을 스택에 push
2. 현재 정점의 `lowLink` 값을 다음 정점의 `lowLink` 값과의 min 연산을 통해 업데이트 (현재 정점의 `lowLink` 초기값은 현재 정점을 처음 방문한 순서 → 이 순서값은 `visitCnt` 전역 변수로 관리)
3. 현재 정점의 모든 인접 정점을 방문한 후, 현재 정점의 `lowLink` 값이 현재 정점을 처음 방문한 순서와 같다면(현재 정점의 `lowLink` 값이 한번도 업데이트되지 않았다면) SCC 구성

   3-1. 현재 정점이 나올 때까지 스택에서 pop

   3-2. 앞 과정에서 pop된 모든 정점이 하나의 SCC를 구성

`lowLink`: 한 정점이 포함된 사이클 내 정점들 중 가장 빠른 방문 순서 (가장 빠르게 방문한 정점을 중심으로 사이클이 형성)

- 한 사이클을 이루는 정점들이 스택에 저장되어 있을 때 가장 빨리 방문한 정점이 가장 아래에 위치 (방문하자마자 스택에 푸시하기 때문)
- 스택 내 '가장 빨리 방문한 정점 ~ 스택 top의 정점' 하나의 SCC 구성
- 현재 정점의 모든 인접 정점을 방문해야 SCC 구성을 시작 → 추가적으로 SCC 위상정렬(SCC를 한 노드로 압축한 그래프에 대한 위상정렬) 구현도 가능 ➡️ SCC가 구성되는 순서의 역순이 위상정렬의 결과

**소스 코드**

```c++
//finished 배열: 해당 노드의 SCC 구성 여부를 관리 (true이면 어떤 SCC에 이미 속한 상태)
//lowLink 배열: 해당 노드를 포함하는 사이클 내 노드들 중 가장 빠른 방문 순서 저장

int dfs(int node) {
    //정점 방문 시 바로 스택에 push
    stk.push(node); lowLink[node] = visitCnt++;
    int ll = lowLink[node];
    for (int i : adj[node]) {
        if (finished[i]) continue;
        if (!lowLink[i]) ll = min(ll, dfs(i));
        else ll = min(ll, lowLink[i]);
    }
    //해당 노드를 중심으로 사이클이 형성
    if (ll == lowLink[node]) {
        vector<int> v; int tmp;
        while (1) {
            tmp = stk.top(); stk.pop();
            v.push_back(tmp); finished[tmp] = 1; //SCC 구성
            if (tmp == node) break;
        }
        scc.push_back(v);
    }
    return lowLink[node] = ll;
}

int main() {
    //주요 로직
    for (int i = 1; i <= v; i++) {
        if (!lowLink[i]) dfs(i);
    }
    return 0;
}
```

<br/>

### 참고

[SCC(Strongly Connected Component) 알고리즘 1](https://blog.naver.com/uss425/222193890263)

[SCC(Strongly Connected Component) 알고리즘 2](https://ip99202.github.io/posts/SCC-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98/)
