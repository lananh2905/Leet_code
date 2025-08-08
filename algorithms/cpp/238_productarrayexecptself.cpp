#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        // left : save left of nums[i]
        // right : save righ of num[i]
        vector<int> left;
        vector<int> right;

        // Sure product != 0 in begin
        left.push_back(1);
        right.push_back(1);

        int size = nums.size();

        for(int i = 0; i < size - 1; i++)
        {   
            // cout<<"i = "<<i<<endl;
            // cout<<"nums = "<<nums[i]<<endl;
            
            left.push_back(left[i] * nums[i]);
            right.push_back(right[i] * nums[size - i - 1]);
            // cout<<"left: "<<left[i + 1]<<" right :"<<right[i + 1]<<endl;
        }

        vector<int> results;
        for(int i = 0; i < size; i++)
        {   
            // results[i] = left[i] * right[i]
            results.push_back(left[i] * right[size - i - 1]);
        }

        return results;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1,1,0,-3,3};
    cout<<"Results: ";
    vector<int> results = sol.productExceptSelf(nums);
    for(int &re : results)
    {
        cout<<re<<" ";
    }
    return 0;
}