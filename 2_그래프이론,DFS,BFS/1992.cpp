#include <iostream>
using namespace std;

int arr[64][64], n;

string compress(int y, int x, int k) {
    if (k == 1) return to_string(arr[y][x]);
    
    string lu = compress(y, x, k / 2);
    string ru = compress(y, x + k / 2, k / 2);
    string ld = compress(y + k / 2, x, k / 2);
    string rd = compress(y + k / 2, x + k / 2, k / 2);
    if (lu == ru && lu == ld && lu == rd && lu.find("(") == string::npos) return lu;
    return "(" + lu + ru + ld + rd + ")";
}

int main() {
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }
    printf("%s\n", compress(0, 0, n).c_str());

    return 0;
}