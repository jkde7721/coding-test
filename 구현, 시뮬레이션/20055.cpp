#include <bits/stdc++.h>
using namespace std;

int n, k, a[200], cnt, t;
bool pos[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < 2*n; i++) cin >> a[i];
    while (++t) {
        rotate(a, a + (2 * n - 1), a + 2 * n);
        rotate(pos, pos + n - 1, pos + n);
        pos[n-1] = 0; //내리는 위치 처리
        for (int i = n - 2; i >= 0; i--) {
            if (pos[i] && !pos[i+1] && a[i+1]) {
                pos[i] = 0; pos[i+1] = 1; a[i+1]--;
                if (a[i+1] == 0) cnt++;
            }
        }
        pos[n-1] = 0; //내리는 위치 처리
        if (a[0]) { 
            pos[0] = 1; a[0]--;
            if (a[0] == 0) cnt++; 
        }
        if (cnt >= k) break;
    }
    cout << t << '\n';
    return 0;
}