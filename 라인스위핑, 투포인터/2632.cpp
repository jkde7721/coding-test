//메모리: 9840KB, 시간: 8ms
#include <bits/stdc++.h>
using namespace std;

int s, m, n, a[1000], b[1000], sa[1000001], sb[1000001], ta, tb, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s >> m >> n;
    for (int i = 0; i < m; i++) { cin >> a[i]; ta += a[i]; }
    for (int i = 0; i < n; i++) { cin >> b[i]; tb += b[i]; }
    for (int i = 0; i < m; i++) {
        for (int j = 0, sum = 0; j < m; j++) {
            sum += a[(i+j) % m];
            sa[sum]++; //해당 피자 크기의 경우의 수 증가
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0, sum = 0; j < n; j++) {
            sum += b[(i+j) % n];
            sb[sum]++;
        }
    }
    sa[0] = sb[0] = 1; //피자 크기가 0인 경우의 수
    sa[ta] = sb[tb] = 1; //피자 크기가 전체 피자 크기인 경우의 수
    for (int i = 0; i <= s; i++) {
        ret += sa[i] * sb[s-i];
    }
    cout << ret << '\n';

    return 0;
}