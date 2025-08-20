#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {

        int result = 0;

        // Set up two pointers
        int left = 0;
        int right = height.size() - 1;

        // Set up Max of left and right height
        int maxLeft = height[left];
        int maxRight = height[right];

        while(left < right){

            // Min between maxLeft and maxHeight
            int min_between_twoMax = min_int(maxLeft, maxRight);
            int water = 0;

            // If maxLeft is smaller -> move left
            if(maxLeft < maxRight){
                left ++;
                water = min_between_twoMax - height[left];
                maxLeft = max_int(maxLeft, height[left]);
            }
            else{
                right --;
                water = min_between_twoMax - height[right];
                maxRight = max_int(maxRight, height[right]);
            }

            if(water > 0) result += water;
        }
        return result;
    }


    int min_int(int a, int b){
        return (a < b) ? a : b;
    }
    int max_int(int a, int b){
        return (a > b) ? a : b;
    }
};

int main() {
    Solution sol;
    vector<int> height = {4,2,0,3,2,5};
    cout << "Trapped rainwater: " << sol.trap(height) << endl;
    return 0;
}
