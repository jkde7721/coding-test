//메모리: 2028KB, 시간: 8ms
#include <bits/stdc++.h>
using namespace std;

char cube[54], color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
//옆면 회전 위한 인덱스
int t, n, idx[6][12] = {{29, 28, 27, 47, 46, 45, 20, 19, 18, 38, 37, 36}, 
    {33, 34, 35, 42, 43, 44, 24, 25, 26, 51, 52, 53}, 
    {6, 7, 8, 45, 48, 51, 15, 16, 17, 44, 41, 38}, 
    {2, 1, 0, 36, 39, 42, 11, 10, 9, 53, 50, 47}, 
    {0, 3, 6, 18, 21, 24, 17, 14, 11, 35, 32, 29}, 
    {8, 5, 2, 27, 30, 33, 9, 12, 15, 26, 23, 20}};
//해당 면 회전 위한 인덱스
int idx2[8] = {0, 1, 2, 5, 8, 7, 6, 3};
string turn;
map<char, int> side = {{'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5}};

void spin(int s, bool dir) {
    vector<char> v(8), v2(12);
    //해당 면 회전
    for (int i = 0; i < 8; i++) v[i] = cube[s*9 + idx2[i]];
    if (dir) rotate(v.begin(), v.begin() + 6, v.end());
    else rotate(v.begin(), v.begin() + 2, v.end());
    for (int i = 0; i < 8; i++) cube[s*9 + idx2[i]] = v[i];
    //옆면 회전
    for (int i = 0; i < 12; i++) v2[i] = cube[idx[s][i]];
    if (dir) rotate(v2.begin(), v2.begin() + 9, v2.end());
    else rotate(v2.begin(), v2.begin() + 3, v2.end());
    for (int i = 0; i < 12; i++) cube[idx[s][i]] = v2[i];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        for (int i = 0; i < 54; i++) cube[i] = color[i/9];
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> turn;
            spin(side[turn[0]], turn[1] == '+');
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) cout << cube[i*3+j];
            cout << '\n';
        }
    }
    return 0;
}

//Dirty Solution
//메모리: 2032KB, 시간: 4ms
/*
#include <bits/stdc++.h>
using namespace std;

int t, n, m;
string turn;
char cube[6][3][3], ch;
map<int, char> color = {{0, 'w'}, {1, 'y'}, {2, 'r'}, {3, 'o'}, {4, 'g'}, {5, 'b'}};
map<char, int> idx = {{'U', 0}, {'D', 1}, {'F', 2}, {'B', 3}, {'L', 4}, {'R', 5}};
int side[6][4] = {{3, 5, 2, 4}, {3, 4, 2, 5}, {0, 5, 1, 4}, 
                {0, 4, 1, 5}, {0, 2, 1, 3}, {0, 3, 1, 2}}; //해당 면을 회전시킴에 따라 영향을 받는 면
//해당 면을 회전시킴에 따라 영향을 받는 면 별로, 영향을 받는 행/열
int y[6][4][3] = {{{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}}, {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}, {2, 2, 2}}, 
    {{2, 2, 2}, {0, 1, 2}, {2, 2, 2}, {2, 1, 0}}, {{0, 0, 0}, {0, 1, 2}, {0, 0, 0}, {2, 1, 0}},
    {{0, 1, 2}, {0, 1, 2}, {2, 1, 0}, {2, 1, 0}}, {{2, 1, 0}, {0, 1, 2}, {0, 1, 2}, {2, 1, 0}}};
int x[6][4][3] = {{{2, 1, 0}, {2, 1, 0}, {2, 1, 0}, {2, 1, 0}}, {{0, 1, 2}, {0, 1, 2}, {0, 1, 2}, {0, 1, 2}}, 
    {{0, 1, 2}, {0, 0, 0}, {0, 1, 2}, {2, 2, 2}}, {{2, 1, 0}, {0, 0, 0}, {2, 1, 0}, {2, 2, 2}}, 
    {{0, 0, 0}, {0, 0, 0}, {2, 2, 2}, {2, 2, 2}}, {{2, 2, 2}, {0, 0, 0}, {0, 0, 0}, {2, 2, 2}}};

void spin(int n, int side[4], bool dir, int y[4][3], int x[4][3]) {
    //해당 면 회전
    char arr[3][3];
    memcpy(arr, cube[n], sizeof(arr));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (dir) cube[n][j][2-i] = arr[i][j]; //시계 방향
            else cube[n][2-j][i] = arr[i][j]; //반시계 방향
        }
    }
    //옆면 회전
    char tmp[3];
    for (int i = 0; i < 3; i++) tmp[i] = cube[side[0]][y[0][i]][x[0][i]];
    if (dir) {
        for (int i = 3; i > 0; i--) {
            for (int j = 0; j < 3; j++) cube[side[(i+1)%4]][y[(i+1)%4][j]][x[(i+1)%4][j]] = cube[side[i]][y[i][j]][x[i][j]];
        }
        for (int j = 0; j < 3; j++) cube[side[1]][y[1][j]][x[1][j]] = tmp[j];
    }
    else {
        for (int i = 1; i < 4; i++) {
            for (int j = 0; j < 3; j++) cube[side[i-1]][y[i-1][j]][x[i-1][j]] = cube[side[i]][y[i][j]][x[i][j]];
        }
        for (int j = 0; j < 3; j++) cube[side[3]][y[3][j]][x[3][j]] = tmp[j];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        for (int k = 0; k < 6; k++) {
            fill(&cube[k][0][0], &cube[k][0][0] + 9, color[k]);
        }
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> turn; m = idx[turn[0]];
            spin(m, side[m], turn[1] == '+', y[m], x[m]);
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) cout << cube[0][i][j];
            cout << '\n';
        }
    }
    return 0;
}
*/