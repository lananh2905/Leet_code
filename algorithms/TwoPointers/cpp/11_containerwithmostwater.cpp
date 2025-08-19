#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono> // For time measurement
#include <map>
#include <fstream>
#include <sstream>

using namespace std;

class Solution {
    public:
    int maxArea(vector<int>& height) {

        int left = 0;
        int right = height.size() - 1;
        int max_area = 0;

        while (left - right < 0) {
            int current_area = min_int(height[left], height[right]) * (right - left);
            max_area = max_int(max_area, current_area);

            if(height[left] < height[right]){
                left ++;
            }
            else if(height[left] > height[right])
            {
                right --;
            }
            else {
                if(height[left + 1] < height[right - 1]){
                    right --;
                }
                else {
                    left ++;
                } 
            }
        }

        return max_area;
    }

    private:
    int min_int(int a, int b) {
        return (a < b) ? a : b;
    }

    private:
    int max_int(int a, int b) {
        return (a > b) ? a : b;
    }
};

class BruteForceSolution {
    public:
    int maxArea(vector<int>& height) {

        int size = height.size();
        int max_con = 0;

        for(int left = 0; left < size - 1; left++){

            for(int right = left + 1; right < size; right ++){
                int container = min_int(height[left], height[right]) * (right - left);
                if(container > max_con){
                    max_con = container;
                }
            }
        }
        return max_con;
    }

    private:
    int min_int(int a, int b) {
        return (a < b) ? a : b;
    }
};



// readfile from local
vector<int> readfile(const string& file_path){
    ifstream file(file_path);
    vector<int> heigts;

    if(!file.is_open()) {
        cerr << "Can't open file:" << file_path << endl;
        return heigts;
    }

    string line;
    if (getline(file, line)) {
        // Remove leading [ and trailing ]
        if (line.front() == '[') line.erase(0, 1);
        if (line.back() == ']') line.pop_back();

        stringstream ss(line);
        string height;

        while (getline(ss, height, ',')) {
            // Remove quotes ("") if present
            height.erase(remove(height.begin(), height.end(), '\"'), height.end());
            // Remove whitespace ( ) if present
            height.erase(remove_if(height.begin(), height.end(), ::isspace), height.end());
            heigts.push_back(stoi(height));
        }
    }
    return heigts;
}

int main() {
    Solution solution;

    vector<int> height = readfile("../test/test_data.txt");

    auto start = chrono::high_resolution_clock::now(); // Start time measurement

    // vector<int> height = {1,8,6,2,5,4,8,3,7};

    cout << "Maximum area: " << solution.maxArea(height) << endl;

    auto end = chrono::high_resolution_clock::now(); // End time measurement
    chrono::duration<double> duration = end - start; // Calculate duration
    cout << "Time taken: " << duration.count() << " seconds" << endl;
    return 0;
}
// Output: Maximum area: 49