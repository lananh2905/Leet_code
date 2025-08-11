#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        while(left < right)
        {
            int sum = numbers[left] + numbers[right];
            if(sum == target){
                return vector<int> {left + 1, right + 1};
            }
            if(sum < target){
                left ++;
            }
            else {
                right --;
            }
        }
        return vector<int> {left + 1, right + 1};
    }
};

int main(){
    Solution sol;
    vector<int> numbers = {2,7,11,15};
    int target = 9;
    vector<int> results = sol.twoSum(numbers, target);
    for(int x : results){
        cout<<x<<" ";
    }
    return 0;
}