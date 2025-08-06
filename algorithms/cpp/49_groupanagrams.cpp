#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <chrono> // For time measurement
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Solution class to group anagrams from a list of strings
class Solution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        unordered_map<string, vector<string>> anagram_map;

        for(string str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end()); // Sort the string to find anagrams
            anagram_map[sorted_str].push_back(str); // Group anagrams together
        }

        vector<vector<string>> results;
        for(auto& pair : anagram_map) {
            results.push_back(pair.second); // Collect the grouped anagrams
        }

        return results;
    }
};


// Alternative implementation using a different approach
class AlternativeSolution {
    public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>> results;
        vector<string> new_strs = strs;

        while (!new_strs.empty()){

            // Processing first string
            string tmp = *new_strs.begin();
            new_strs.erase(new_strs.begin());

            // result save the anagrams of first str
            // tmp_strs save remaining strs
            vector<string> result;
            vector<string> tmp_strs;
            result.push_back(tmp);

            // Loop through tmp_strs to find angrams and save into result
            for(int i = 0; i < new_strs.size(); i++){

                if(isAnagram(tmp, new_strs[i])){
                    result.push_back(new_strs[i]);
                    continue;
                }
                tmp_strs.push_back(new_strs[i]);
                
            }
            new_strs = tmp_strs;
            results.push_back(result);
        }
        return results;
    }

    private:

    // Helper function to check if two strings are anagrams
    bool isAnagram(const string& s1, const string &s2) {
        if(s1 == s2) {
            return true;
        }

        if(s1.size() != s2.size()) {
            return false;
        }

        string sorted_s1 = s1;
        string sorted_s2 = s2;
        sort(sorted_s1.begin(), sorted_s1.end());
        sort(sorted_s2.begin(), sorted_s2.end());
        return sorted_s1 == sorted_s2;

        // vector<int> count(26, 0);
        // for(char c: s1) {
        //     count[c - 'a']++;
        // }

        // for(char c: s2) {
        //     count[c - 'a']--;
        //     if (count[c - 'a'] < 0) {
        //         return false;
        //     }
        // }
        // return true;
    }
};


// readfile from local
vector<string> readfile(const string& file_path){
    ifstream file(file_path);
    vector<string> words;

    if (!file.is_open()) {
        cerr << "Can't open file:" << file_path << endl;
        return words;
    }

    string line;
    if (getline(file, line)) {
        // Remove leading [ and trailing ]
        if (line.front() == '[') line.erase(0, 1);
        if (line.back() == ']') line.pop_back();

        stringstream ss(line);
        string word;

        while (getline(ss, word, ',')) {
            // Remove quotes ("") if present
            word.erase(remove(word.begin(), word.end(), '\"'), word.end());
            // Remove whitespace ( ) if present
            word.erase(remove_if(word.begin(), word.end(), ::isspace), word.end());
            words.push_back(word);
        }
    }
    return words;
}


int main() {
    Solution sol;
    vector<string> strs = readfile("test_data.txt");

    auto start = chrono::high_resolution_clock::now(); // Start time measurement
    vector<vector<string>> result = sol.groupAnagrams(strs);

    auto end = chrono::high_resolution_clock::now(); // End time measurement
    chrono::duration<double> duration = end - start; // Calculate duration

    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& str : group) {
            cout << str << " ";
        }
        cout << "]" << endl;
    }

    // Output the time taken
    cout << "Time taken: " << duration.count() << " ms" << endl;

    return 0;
}