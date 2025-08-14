#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // For time measurement
#include <unordered_set>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        // Using hash map to minimun time exceed
        vector<vector<int>> results;
        unordered_set<int> check_set(nums.begin(), nums.end());

        // Sort nums
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        vector<int> check_vec = sorted_nums;
        int size = nums.size();
        int count_zero = 0;

        for(int left = 0; left < size; left ++){

            if(sorted_nums[left] == 0){
                count_zero ++;
            }

            // Skip duplicate value
            if(left > 0 && sorted_nums[left] == sorted_nums[left - 1]){
                continue;
            }

            check_set.erase(sorted_nums[left]);
            unordered_set<int> check_right = check_set;

            // Throughout remaining value
            for(int right = left + 1; right < size - 1; right ++){

                // Skip duplicate value
                if(right > left + 1 && sorted_nums[right] == sorted_nums[right -1]){
                    continue;
                }

                // Check to keep duplicate remaining value
                if(sorted_nums[right] != sorted_nums[right + 1]){
                    check_right.erase(sorted_nums[right]);
                }

                // Check sum
                int sum = sorted_nums[left] + sorted_nums[right];
                if(check_right.find(-sum) != check_right.end()){

                    vector<int> check_re = {sorted_nums[left], sorted_nums[right], -sum};
                    results.push_back(vector<int> {sorted_nums[left], sorted_nums[right], -sum});
                }
                check_right.erase(sorted_nums[right]);
            }
        }

        // Special case
        vector<int> zero = {0, 0, 0};
        if(count_zero >= 3 && find(results.begin(), results.end(), zero) == results.end()){
            results.push_back(zero);
        }
        return results;
    }
};



class AlternateSolution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> results;
        //unordered_map<int, vector<int>> num_map;

        // Sort the input array to use two pointers technique
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        // Handle edge case where the array has less than 3 elements
        int n = nums.size();
        
        while(sorted_nums[0] <= 0 && !sorted_nums.empty()) {


            // Skip duplicates for the first element
            int tmp = sorted_nums[0];
            sorted_nums.erase(sorted_nums.begin());

            // Find pairs that sum to the negative of the current element
            vector<vector<int>> re = findTwoSum(sorted_nums, 0 - tmp);

            // If pairs are found, add the current element to each pair and sort it
            if(re.size() > 0){
                for(vector<int>& triplet : re) {
                    triplet.push_back(tmp);
                    sort(triplet.begin(), triplet.end());

                    //num_map[tmp] = triplet;
                }
            }

            // Remove all occurrences of the current element to avoid duplicates
            if(!sorted_nums.empty() && sorted_nums[0] == tmp) {
                sorted_nums.erase(remove(sorted_nums.begin(), sorted_nums.end(), tmp), sorted_nums.end());
            }
            
        }
        return results;
    }

private:
    vector<vector<int>> findTwoSum(vector<int>& nums, int target) {
        vector<vector<int>> results;
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int sum = nums[left] + nums[right];
            if(sum == target){
                results.push_back(vector<int> {nums[left], nums[right]});
            }
            if(sum < target){
                left ++;
            }
            else{
                right --;
            }
        }
        return results;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,-2};

    auto start = chrono::high_resolution_clock::now(); // Start time measurement
    vector<vector<int>> results = sol.threeSum(nums);

    auto end = chrono::high_resolution_clock::now(); // End time measurement
    chrono::duration<double> duration = end - start; // Calculate duration
    
    for(const auto& triplet : results) {
        cout << "[";
        for(int num : triplet) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    // Output the time taken to find the triplets
    cout << "Time taken: " << duration.count() << " seconds" << endl;
    
    return 0;
}