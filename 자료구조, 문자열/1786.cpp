//KMP 알고리즘 (시간복잡도 O(N+M))
//메모리: 11384KB, 시간: 60ms
#include <bits/stdc++.h>
using namespace std;

//fix 배열: 해당 인덱스가 문자열의 끝이라고 가정할 때 일치하는 접두사, 접미사의 최대 길이
int fix[1000000], st = 1, match;
string t, p; //t의 길이 N, p의 길이 M
vector<int> ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    getline(cin, t); getline(cin, p);
    //일치하는 접두사, 접미사의 최대 길이 계산 (시간복잡도 O(M))
    while (st + match < p.size()) {
        if (p[st + match] == p[match]) { fix[st + match] = match + 1; match++; }
        else if (!match) st++;
        else {
            st += match - fix[match - 1];
            match = fix[match - 1];
        }
    }
    //문자열 탐색 (시간복잡도 O(N))
    st = match = 0;
    while (st + p.size() <= t.size()) {
        if (match < p.size() && t[st + match] == p[match]) match++; 
        else if (!match) st++;
        else {
            st += match - fix[match - 1];
            match = fix[match - 1];
        }
        if (match == p.size()) ret.push_back(st + 1);
    }
    cout << ret.size() << '\n';
    for (int i : ret) cout << i << ' ';
    
    return 0;
}