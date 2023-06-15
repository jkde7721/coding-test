//�޸�: 5936KB, �ð�: 460ms
#include <bits/stdc++.h>
using namespace std;

//dp �迭: STR, INT�� ���� i, j�� �� �� �� �ִ� ����Ʈ ���� ����
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
        //���� ret: cur_str, cur_int�� �� ����Ʈ ����
        //���� pnt: ó�� �� ����Ʈ�� ���� ����Ʈ
        for (int p = 0; p <= pnt; p++) {
            int nxt_str = min(1000, cur_str + p);
            int nxt_int = min(1000, cur_int + pnt - p);
            //���� ����Ʈ�� ���� �߰������� �� �� �ִ� �ִ� ����Ʈ ����
            ret = max(ret, go(nxt_str, nxt_int)); 
        }
        for (int i : tmp) visited[i] = false; //����
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

//�޸�, �ð� �ٿ��� �ٽ� Ǯ���