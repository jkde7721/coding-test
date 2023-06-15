//메모리: 5936KB, 시간: 460ms
#include <bits/stdc++.h>
using namespace std;

//dp 배열: STR, INT가 각각 i, j일 때 깰 수 있는 퀘스트 개수 저장
int N, STR[50], INT[50], PNT[50], dp[1001][1001];
bool visited[50];

int go(int cur_str, int cur_int) {
    int& ret = dp[cur_str][cur_int];
    if (ret == -1) {
        vector<int> tmp; ret = 0; int pnt = 0;
        for (int i = 0; i < N; i++) {
            if (STR[i] > cur_str && INT[i] > cur_int) continue;
            ret++;
            if (visited[i]) continue;
            visited[i] = true;
            pnt += PNT[i];
            tmp.push_back(i);
        }
        //현재 ret: cur_str, cur_int로 깬 퀘스트 개수
        //현재 pnt: 처음 깬 퀘스트로 얻은 포인트
        for (int p = 0; p <= pnt; p++) {
            int nxt_str = min(1000, cur_str + p);
            int nxt_int = min(1000, cur_int + pnt - p);
            //얻은 포인트를 통해 추가적으로 깰 수 있는 최대 퀘스트 개수
            ret = max(ret, go(nxt_str, nxt_int)); 
        }
        for (int i : tmp) visited[i] = false; //원복
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> N;
    for (int i = 0; i < N; i++) cin >> STR[i] >> INT[i] >> PNT[i];
    cout << go(1, 1) << '\n';

    return 0;
}

//메모리, 시간 줄여서 다시 풀어보기