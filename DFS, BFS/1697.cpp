//재귀 풀이
//메모리: 4552KB, 시간: 1748ms
#include <bits/stdc++.h>
#define MAX 100001
using namespace std;

//visited 배열: 해당 위치에 오기까지 걸린 최소 시간 저장
const int d[] = {2, -1, 1};
int n, k, visited[MAX];

void dfs(int cur, int t) {
    visited[cur] = t;
    //현재 위치가 목표 위치보다 크다면 굳이 하나씩 뒤로 갈 필요X
    if (cur >= k) {
        visited[k] = min(visited[k], visited[cur] + cur - k);
        return;
    }
    for (int i = 0; i < 3; i++) {
        //+1보다 *2를 먼저 해야 최소값 빨리 구함
        int next = (i == 0 ? cur * d[i] : cur + d[i]);
        //다음 위치가 범위를 벗어나면 더 오래 걸림
        if (next <= 0 || next >= MAX || t + 1 >= visited[k] || t + 1 >= visited[next]) continue;
        dfs(next, t + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(visited, visited + MAX, MAX);
    cin >> n >> k;
    dfs(n, 0);
    cout << visited[k] << '\n';
    return 0;
}