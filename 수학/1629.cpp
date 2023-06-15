#include <iostream>
typedef long long ll;
using namespace std;

ll a, b, c;

int getRemainder(ll t) {
    if (t == 1) return a % c;
    ll tmp = getRemainder(t / 2);
    tmp = (tmp * tmp) % c;
    if (t % 2) return (tmp * a) % c;
    return tmp;
}

int main() {
    cin >> a >> b >> c;
    cout << getRemainder(b) << '\n';
    
    return 0;
}