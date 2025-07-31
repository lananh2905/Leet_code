//You are given an m x n integer grid accounts where accounts[i][j] is the amount of money the i​​​​​​​​​​​th​​​​ customer has in the j​​​​​​​​​​​th​​​​ bank. Return the wealth that the richest customer has.

//A customer's wealth is the amount of money they have in all their bank accounts. The richest customer is the customer that has the maximum wealth.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size();
        int n = accounts[0].size();
        cout << "m: " << m << ", n: " << n << endl;
        int max = 0;
        // Loop though customers
        for (int i=0; i < m; i ++)
        {
            int tmp = accounts[i][0];
            // Loop though cus
            for (int j=1; j < n; j++)
            {
                tmp += accounts[i][j];
            }
            if (tmp > max) max = tmp;
        }
        return max;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> accounts = {{1, 2, 3}, {3, 2, 1}, {4, 5, 6}};
    cout << "Maximum Wealth: " << sol.maximumWealth(accounts) << endl;
    return 0;
}