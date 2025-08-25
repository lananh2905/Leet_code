#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        // Check length
        int size = tokens.size();
        if(size == 1) return stoi(tokens[0]);
        
        // Number: save number
        stack<int> number;
        int result;

        for(int i = 0; i < tokens.size(); i++){

            // If number is empty or it is interger
            if (number.empty() || isInterger(tokens[i])){

                // Save in stack number
                int num = stoi(tokens[i]);
                number.push(num);
            }
            else {
                int num1 = number.top();
                number.pop();
                int num2 = number.top();
                number.pop();

                result = calculate(num1, num2, tokens[i]);
                number.push(result);

            }

        }  
        return result;
    }

    int calculate(int num1, int num2, string notation){
        if(notation == "+"){
            return num1 + num2;
        }
        if(notation == "-"){
            return num2 - num1;
        }
        if(notation == "*"){
            return num1 * num2;
        }
        if(notation == "/"){
            return num2 / num1;
        }
        return 0;
    }

    bool isInterger(string s){
        if (s.empty()) return false;

        int start = 0;
        if (s[0] == '-' || s[0] == '+') {
            if (s.size() == 1) return false;
            start = 1;
        }

        for (int i = start; i < s.size(); i++) {
            if (!isdigit(s[i])) return false;
        }
        return true;
    }
    
};

int main(){
    Solution sol;
    vector<string> tokens = {"4","-2","/","2","-3","-","-"};

    cout<<sol.evalRPN(tokens)<<endl;
    return 0;
}
