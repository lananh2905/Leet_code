 #include <iostream>
 #include <vector>
 #include <string>
 #include <stack>

using namespace std;

class Solution {
private:
    vector<string> result;

public:
    vector<string> generateParenthesis(int n) {
        
        string str = "";
        backtracking(str, 0, 0, n);
        return result;
    }
    
    void backtracking(string str, int open, int close, int n) {
        // Base case: if we have used all n pairs
        if(str.size() == n * 2) {
            result.push_back(str);
            return;
        }
        
        // Add opening parenthesis if we haven't used all n
        if(open < n) {
            backtracking(str + "(", open + 1, close, n);
        }
        
        // Add closing parenthesis if it won't make string invalid
        if(close < open) {
            backtracking(str + ")", open, close + 1, n);
        }
    }
};

int main(){
    Solution sol;
    int n = 3;

    vector<string> result = sol.generateParenthesis(n);
    for(string str : result){
        cout<<str<<", ";
    }
    return 0;
}