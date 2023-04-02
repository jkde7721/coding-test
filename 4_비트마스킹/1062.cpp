//메모리: 2024KB, 시간: 36ms
/*
#include <iostream>
using namespace std;

int n, k, word[50], letter, ret, tmp, num;
string str;
bool alpha[26];

void go(int idx, int cnt) {
    if (cnt == k || cnt == num) {
        tmp = 0;
        for (int i = 0; i < n; i++) {
            if ((word[i] & letter) == word[i]) tmp++;
        }
        ret = max(ret, tmp);
        return;
    }
    for (int i = idx; i < 26; i++) {
        if ((letter & (1 << i)) || !alpha[i]) continue;
        letter |= (1 << i);
        go(i + 1, cnt + 1);
        letter &= ~(1 << i);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (int j = 0; j < str.size(); j++) {
            if (!alpha[str[j] - 'a']) num++;
            alpha[str[j] - 'a'] = 1;
            word[i] |= 1 << (str[j] - 'a');
        }
    }

    if (k < 5) cout << "0\n"; 
    else {
        k -= 5; num -= 5;
        letter = (1 << ('a' - 'a')) | (1 << ('c' - 'a')) | (1 << ('i' - 'a')) | (1 << ('n' - 'a')) | (1 << ('t' - 'a'));
        go(0, 0);
        cout << ret << '\n';
    }

    return 0;
}
*/

//메모리: 2024KB, 시간: 128ms
//for문 + 재귀 보다 재귀 + 재귀가 조금 더 걸림
#include <iostream>
using namespace std;

int n, k, word[50];
string str;

int go(int idx, int cnt, int mask) {
    if (cnt == k + 1) return 0;
    if (idx == 26) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            if ((word[i] & mask) == word[i]) tmp++;
        }
        return tmp;
    }
    int ret = go(idx + 1, cnt + 1, mask | (1 << idx));
    if (idx != 'a' - 'a' && idx != 'c' - 'a' && idx != 'i' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a') {
        ret = max(ret, go(idx + 1, cnt, mask)); 
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> str;
        for (char c : str) word[i] |= 1 << (c - 'a');
    }
    cout << go(0, 0, 0) << '\n';

    return 0;
}