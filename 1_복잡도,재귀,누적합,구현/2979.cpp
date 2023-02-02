#include <iostream>

using namespace std;
int fee[4], car[101], s, e, result = 0;

int main() {
    cin >> fee[1] >> fee[2] >> fee[3];
    for (int i = 0; i < 3; i++) {
        cin >> s >> e;
        for (int j = s; j < e; j++) {
            car[j]++;
        }
    }

    for (int i = 0; i < 101; i++) {
        result += car[i] * fee[car[i]];
    }
    cout << result << "\n";

    return 0;
}