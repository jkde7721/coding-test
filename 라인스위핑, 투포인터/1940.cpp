#include <iostream>
using namespace std;

int n, m, id[15000], ret = 0;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> id[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (id[i] + id[j] == m) ret++;
        }
    }
    cout << ret << '\n';
    
    return 0;
}