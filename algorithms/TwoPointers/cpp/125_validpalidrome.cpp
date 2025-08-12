#include<string>
#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string s_normalize = normalizeString(s);
        int left = 0, right = s_normalize.size() - 1;
        while (left < right) {
            if (s_normalize[left] != s_normalize[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }

private:
    string normalizeString(const string &s) {
        string re;
        for(char c : s)
        {
            if(isalnum(static_cast<unsigned char>(c))){
                re += tolower(static_cast<unsigned char>(c));
            }
        }
        return re;
    }
};