#include <iostream>
#include <map>
using namespace std;

int n, m;
string tmp;
map<int, string> m1;
map<string, int> m2;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> m1[i];
        m2.insert({m1[i], i});
    }

    for (int i = 0; i < m; i++) {
        cin >> tmp;
        if (atoi(tmp.c_str()) == 0) {
            cout << m2[tmp] << '\n';
        }
        else {
            cout << m1[stoi(tmp)] << '\n';
        }
    }
    
    return 0;
}