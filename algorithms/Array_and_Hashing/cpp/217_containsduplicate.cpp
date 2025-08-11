#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        vector<int> unique_nums(nums);
        sort(unique_nums.begin(), unique_nums.end());

        if(nums.size() < 2) return false;

        for (int i = 0; i < unique_nums.size(); i++) {
            if (unique_nums[i] == unique_nums[i + 1]) {
                return true;
            }
        }


        // Alternative approach using FIND() => TIME LIMIT EXCEEDED
        // while(nums.size() > 1) {

        //     int tmp = *nums.begin();

        //     // Remove the current element from the vector
        //     nums.erase(nums.begin());

        //     // Check if the current element exists in the remaining vector
        //     if(find(nums.begin(), nums.end(), tmp) != nums.end()) {
        //         return true;
        //     }
        // }
        return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {5, 2, 3, 4};
    bool result = solution.containsDuplicate(nums);
    cout << (result ? "Contains Duplicate" : "No Duplicate") << endl;
    return 0;
}