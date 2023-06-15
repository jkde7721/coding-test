#include <iostream>
#include <map>
using namespace std;

int t, n, ret;
string s;
map<string, int> _map;

int main() {
    cin >> t;
    for (int i = 0; i < t; i++) {
        ret = 1; _map.clear();
        cin >> n;
        for (int j = 0; j < n; j++) {
            cin >> s >> s;
            _map[s]++;
        }

        for (auto it : _map) {
            ret *= (it.second + 1);
        }
        cout << (ret - 1) << '\n';
    }

    return 0;
}