#include <iostream>
using namespace std;

int n, num, one, two, sec1, sec2;
string pre = "00:00", s;

int second(string str) {
    return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
}

int interval(string start, string end) {
    return second(end) - second(start);
}

string format(int isec) {
    string min = "0" + to_string(isec / 60);
    string sec = "0" + to_string(isec % 60); 
    return min.substr(min.size() - 2, 2) + ":" + sec.substr(sec.size() - 2, 2);
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num >> s;
        if (one > two) sec1 += interval(pre, s);
        else if (one < two) sec2 += interval(pre, s);
        if (num == 1) one++;
        else two++;
        pre = s;
    }
    if (one > two) sec1 += interval(pre, "48:00");
    else if (one < two) sec2 += interval(pre, "48:00");

    cout << format(sec1) << '\n';
    cout << format(sec2) << '\n';

    return 0;
}