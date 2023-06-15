#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, tmp;
unordered_map<int, int> _map;
vector<int> v;

bool cmp(int a, int b) {
    return _map[a] > _map[b];
}

int main() {
    cin >> n >> c;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        _map[tmp]++; 
        if (find(v.begin(), v.end(), tmp) == v.end()) {
            v.push_back(tmp);
        }
    }
    stable_sort(v.begin(), v.end(), cmp);

    for (int i : v) {
        for (int j = 0; j < _map[i]; j++) {
            cout << i << ' ';
        }
    }

    return 0;
}