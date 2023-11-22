//Top-Down 풀이
#include <iostream>
#include <cstring>
using namespace std;

//dp 배열: [i, j] 범위에서 가장 긴 KOI 유전자의 길이 저장
int dp[500][500];
string dna;

int go(int st, int en) {
    if (en - st < 1) return 0;
    if (en - st == 1) {
        if (dna.substr(st, 2) == "at" || dna.substr(st, 2) == "gc") return 2;
        return 0;
    }
    int& ret = dp[st][en];
    if (ret == -1) {
        ret = max(ret, go(st + 1, en));
        ret = max(ret, go(st, en - 1));
        ret = max(ret, go(st + 1, en - 1) + (dna[st] == 'a' && dna[en] == 't' || dna[st] == 'g' && dna[en] == 'c' ? 2 : 0));
        for (int idx = st; idx < en; idx++) {
            ret = max(ret, go(st, idx) + go(idx + 1, en));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> dna;
    cout << go(0, dna.size() - 1) << '\n';
    return 0;
}