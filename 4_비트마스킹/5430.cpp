#include <iostream>
#include <algorithm>
using namespace std;

int t, n, s, e, idx, arr[100001];
string op, nums, tmp;
bool isR, isError;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t > 0) {
        cin >> op >> n >> nums;
        s = idx = 0; e = n - 1;
        isR = false; isError = false;
        for (char c : nums) {
            if (c >= '0' && c <= '9') tmp += c;
            else if (tmp != "") {
                arr[idx++] = stoi(tmp);
                tmp = "";
            }
        }
        for (char c : op) {
            if (c == 'R') isR = !isR;
            else if (s > e) { isError = true; break; }
            else if (isR) e--;
            else s++;
        }

        if (isError) cout << "error\n";
        else if (s > e) cout << "[]\n";
        else {
            if (isR) reverse(arr + s, arr + e + 1);
            cout << "[" << arr[s];
            for (int i = s + 1; i <= e; i++) {
                cout << "," << arr[i];
            }
            cout << "]\n";
        }
        t--;
    }

    return 0; 
}