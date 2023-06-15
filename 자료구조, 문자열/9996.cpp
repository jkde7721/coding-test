#include <iostream>
using namespace std;

int n;
string p, str, f, b;

int main() {
    cin >> n >> p;
    f = p.substr(0, p.find("*"));
    b = p.substr(p.find("*") + 1);

    for (int i = 0; i < n; i++) {
        cin >> str;
        if (str.size() >= f.size() + b.size() &&
            str.substr(0, f.size()) == f &&
            str.substr(str.size() - b.size()) == b) {
            cout << "DA\n";
        }
        else cout << "NE\n";
    }

    return 0;
}