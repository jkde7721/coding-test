#include <iostream>
#include <vector>
using namespace std;

const int INF = 987654321;
int n, mp, mf, ms, mv, p[15], f[15], s[15], v[15], c[15], price = INF, tmp, ret;
vector<int> choice;

int isOk() {
    int sp = 0, sf = 0, ss = 0, sv = 0, sc = 0;
    for (int i : choice) {
        sp += p[i]; sf += f[i]; ss += s[i]; sv += v[i]; sc += c[i];
    }
    if (sp >= mp && sf >= mf && ss >= ms && sv >= mv && sc <= price) return sc;
    return -1;
}

bool isFirst(int a, int b) {
    int tmpa, tmpb;
    do {
        tmpa = a & 1; tmpb = b & 1;
        if (tmpa > tmpb) return true;
        else if (tmpa < tmpb) return false;
        a >>= 1; b >>= 1;
    } while (a > 0 && b > 0);
    if (a > 0) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> mp >> mf >> ms >> mv;
    for (int i = 0; i < n; i++) {
        cin >> p[i] >> f[i] >> s[i] >> v[i] >> c[i];
    }

    for (int i = 1; i < (1 << n); i++) {
        choice.clear();
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) choice.push_back(j);
        }
        if ((tmp = isOk()) != -1) { 
            if (tmp < price || isFirst(i, ret)) ret = i;
            price = tmp;
        }
    }

    if (price == INF) cout << "-1\n";
    else {
        cout << price << '\n';
        for (int i = 0; i < n; i++) {
            if (ret & (1 << i)) cout << (i + 1) << ' ';
        }
    }

    return 0;
}