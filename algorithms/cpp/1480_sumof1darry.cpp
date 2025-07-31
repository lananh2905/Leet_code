//Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

//Return the running sum of nums.

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> news;
        news.push_back(nums[0]);
        int n = nums.size();

        for(int i=1; i < n; i++) 
        {
            int temp = news[i-1] + nums[i];
            news.push_back(temp);
        }
        return news;
    }
};