#include <iostream>
using namespace std;

int n, ret = 665;

int main() {
    cin >> n;
    while (n > 0) {
        ret++;
        if (to_string(ret).find("666") != string::npos) {
            n--;
        }
    }
    cout << ret << '\n';

    return 0;
}