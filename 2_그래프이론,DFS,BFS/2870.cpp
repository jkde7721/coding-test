#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
string s, nums;
vector<string> v;

bool cmp(string s1, string s2) {
    if (s1.size() == s2.size()) return s1.compare(s2) < 0;
    return s1.size() < s2.size();
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s; nums = "";
        for (char c : s) {
            if (c >= '0' && c <= '9') {
                if (nums == "0") nums = "";
                nums += c;
            }
            else if (!nums.empty()) {
                v.push_back(nums);
                nums = "";
            }
        }
        if (!nums.empty()) v.push_back(nums);
    }
    
    sort(v.begin(), v.end(), cmp);
    for (string str : v) {
        cout << str << '\n';
    }

    return 0;
}