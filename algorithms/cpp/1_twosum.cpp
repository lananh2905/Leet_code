#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        // Loop through the array
        for(int i=0; i < nums.size(); i++){

                // Loop through the rest of the array
                for (int j = i + 1; j < nums.size(); j++){

                    // If the current number is greater than the target, we can break early
                    int tmp = nums[i] + nums[j];
                    if (tmp == target) {
                        return vector<int> {i, j};
                    }
            }
        }
        return vector<int> {};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,-2,-3,-4,-5};
    int target = -8;
    vector<int> result = sol.twoSum(nums, target);
    
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No two sum solution found." << endl;
    }
    
    return 0;
}