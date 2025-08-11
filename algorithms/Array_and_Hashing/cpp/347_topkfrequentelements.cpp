#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
    public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // Create a frequency map to count occurrences of each number
        // First value is the number, second value is the frequency
        unordered_map<int, int> mp;

        for(int &num: nums) {
            if(mp.find(num) == mp.end()){
                mp[num] = 0;
            }
            mp[num]++;
        }

        // Convert the map to a vector of pairs for sorting
        vector<pair<int, int>> sorted_vec(mp.begin(), mp.end());

        sort(sorted_vec.begin(), sorted_vec.end(), 
            // Lambda function to sort in descending order based on frequency
            [](const pair<int, int>& a, const pair<int, int>& b){
                return a.second > b.second;
        });

        // Collect the top k frequent elements
        vector<int> results;
        for(int i = 0; i < k; i++){
            results.push_back(sorted_vec[i].first);
        }

        return results;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,1,1,2,2,3,3,4,4,4,5,5,5,5,6};
    int k = 3;
    vector<int> result = sol.topKFrequent(nums, k);
    cout << "Results: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}