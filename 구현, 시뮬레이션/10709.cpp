#include <iostream>
using namespace std;

int h, w, joi[100][100];
string s;
bool isCloud;

int main() {
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        cin >> s; isCloud = false;
        for (int j = 0; j < w; j++) {
            if (s.at(j) == 'c') {
                joi[i][j] = 0;
                isCloud = true;
            }
            else if (isCloud) joi[i][j] = joi[i][j - 1] + 1; 
            else joi[i][j] = -1;
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << joi[i][j] << ' ';
        }
        cout << '\n';
    }
    
    return 0;
}