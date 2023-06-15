#include <iostream>
#include <algorithm>

using namespace std;
int h[9], sum = 0;

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> h[i];
        sum += h[i];
    }
    sort(h, h + 9);

    for (int i = 0; i < 9; i++) {
        for (int j = i; j < 9; j++) {
            if ((sum - h[i] - h[j]) == 100) {
                for (int n = 0; n < 9; n++) {
                    if (n != i && n != j) {
                        cout << h[n] << "\n";
                    }
                }
                return 0;
            }
        }
    }

    return 0;
}