/*
#include <iostream>
using namespace std;

int na, nb, sum, ci;
string a, b, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    na = a.size() - 1; nb = b.size() - 1;
    while (na >= 0 && nb >= 0) {
        sum = (a[na] - '0') + (b[nb] - '0') + ci;
        if (sum >= 10) { ci = 1; ret += (sum - 10) + '0'; }
        else { ci = 0; ret += sum + '0'; }
        na--; nb--;
    }
    while (na >= 0) {
        sum = (a[na] - '0') + ci;
        if (sum >= 10) { ci = 1; ret += (sum - 10) + '0'; }
        else { ci = 0; ret += sum + '0'; }
        na--;
    }
    while (nb >= 0) {
        sum = (b[nb] - '0') + ci;
        if (sum >= 10) { ci = 1; ret += (sum - 10) + '0'; }
        else { ci = 0; ret += sum + '0'; }
        nb--;
    }
    if (ci) ret += "1";

    for (int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i];
    }

    return 0;
}
*/

//위 코드 중복 제거
#include <iostream>
using namespace std;

int sum, ci;
string a, b, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> a >> b;
    while (a.size() || b.size()) {
        sum = 0;
        if (a.size()) {
            sum += a.back() - '0';
            a.pop_back();
        }
        if (b.size()) {
            sum += b.back() - '0';
            b.pop_back();
        }
        sum += ci;
        ret += (sum % 10) + '0';
        ci = sum / 10;
    }
    if (ci) ret += "1";

    for (int i = ret.size() - 1; i >= 0; i--) {
        cout << ret[i];
    }

    return 0;
}