## LCA(Lowest Common Ancestor, 최소 공통 조상)

### 중요 포인트

> 특정 노드 a, b의 최소 공통 조상을 찾고자 하는 경우

- sparse 2차원 배열 생성

  - 특정 노드의 모든 조상 노드 저장할 필요X
  - 2의 제곱수 번째의 조상 노드만 저장 `sparse[a][i] = a번 노드의 2^i번째 조상 노드`

    ex. 자신의 7번째 조상 노드는 (자신의 4번째 조상 → 4번째 조상 노드의 2번째 조상 → 2번째 조상 노드의 1번째 조상)으로 올라가서 찾을 수 있음

  - skewed tree 이더라도 sparse 배열을 통해 리프 노드 → 루트 노드까지 O(logN)만에 탐색 가능 (N은 노드 개수)

- 노드 a와 노드 b의 깊이(depth)를 맞춤

  - 깊이 값이 더 큰 노드를 자신의 조상 노드로 치환 (노드 간 깊이 값이 일치하도록)

    ex. 노드 a의 깊이 값이 더 큰 경우, 노드 a의 조상 노드들 중 노드 b와 깊이 값이 같은 조상 노드를 선택

    ```c++
    int &node = (depth[a] > depth[b] ? a : b), diff = abs(depth[a] - depth[b]);
    //노드 a와 노드 b의 깊이 차이가 0이 될 때까지
    while (diff > 0) {
        node = sparse[node][(int)log2(diff & -diff)];
        diff -= (diff & -diff); //depth가 더 큰 노드를 위로 올림
    }
    ```

- 본격적인 최소 공통 조상 찾기

  - 노드 a, b의 sparse 배열로 갈 수 있는 최상위 조상 노드로부터 시작하여 쭉 내려옴
  - sparse 배열로 간 조상 노드가 서로 같지 않다면 노드 a, b를 해당 조상 노드로 update

    ex. `2^i`번째 조상이 다르기 시작하면 그 하위 조상들(`2^(i-1)` ... `2^0`번째 조상들)도 모두 다름 → 탐색할 필요가 없으므로 skip

    ```c++
    //2^16 = 65,536, 2^17 = 131,072 (현재 노드 개수는 최대 100,000라 가정)
    for (int i = 16; i >= 0; i--) {
      if (sparse[a][i] != sparse[b][i]) {
          a = sparse[a][i];
          b = sparse[b][i];
      }
    }
    ```

  - for문 종료 후 노드 a, b는 서로 같지 않고 바로 위 부모 노드는 같으므로 LCA는 `sparse[a][0]` 또는 `sparse[b][0]`

<br/>

### 대표문제

- [LCA](https://www.acmicpc.net/problem/11437)

<br/>

### 참고

[LCA 알고리즘](https://stg0123.github.io/algorithm/29/)
