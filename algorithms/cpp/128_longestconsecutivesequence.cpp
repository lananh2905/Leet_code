#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        // Sort nums
        set<int> sorted_nums(nums.begin(), nums.end());

        // count: save current count
        // max_count: save max of count
        int count = 1;
        int max_count = 1;
        int size = sorted_nums.size();
        if(size == 0) return 0;

        //Loop throught sorted_nums
        auto it = sorted_nums.begin();
        for(int i = 1; i < size; i++)
        {
            int tmp = *it;
            advance(it, 1);

            // if sorted nums[i] is an consecutive element
            if(*it == tmp + 1)
            {
                count++;
                if(count > max_count)
                {
                    max_count = count;
                }
            } 
            else 
            {
                count = 1;
            }
        }
        
        return max_count;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    cout<<sol.longestConsecutive(nums)<<endl;
    return 0;
}