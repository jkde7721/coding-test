#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int m, n;
string messi[3] = {"", "Messi", "Messi Gimossi"};
ll len[41] =  {0, 5, 13};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m;
    for (int i = 3; i <= 40; i++) {
        len[i] = len[i-1] + 1 + len[i-2];
    }
    for (n = 40; n > 2; ) {
        if (m == len[n-1] + 1) { //공백일 경우
            cout << "Messi Messi Gimossi\n"; return 0; 
        }
        else if (m <= len[n-1]) n--;
        else { m -= len[n-1] + 1; n -= 2; }
    }
    if (n == 2 && m == 6) cout << "Messi Messi Gimossi\n"; //공백일 경우
    else cout << messi[n][m - 1] << '\n';

    return 0;
}