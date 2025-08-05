#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
    public:
    bool isAnagram(string s, string t) {

        if (s.length() != t.length()) {
            return false;
        }

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s == t;
    }
};

int main() {
    Solution sol;
    string s = "abcdef";
    string t = "fedcaa";

    bool result = sol.isAnagram(s, t);
    cout<< result << endl;
    return 0;
}