from py_compile import main
from typing import List
import ast # for parsing Python expressions

class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        anagrams = {}
        
        for s in strs:
            sorted_str = ''.join(sorted(s))
            if sorted_str not in anagrams:
                anagrams[sorted_str] = []
            anagrams[sorted_str].append(s)
            
        return list(anagrams.values())

# This function reads a file and returns its content as a list of strings.
def readFile(filename: str) -> List[str]:
    with open(filename, 'r') as file:
        content = file.read()
    return ast.literal_eval(content) # string to list

def main():
    solution = Solution()
    test_cases = [
        ["eat", "tea", "tan", "ate", "nat", "bat"],
        [""],
        ["a"],
        ["abc", "bca", "cab", "xyz", "zyx"]
    ]
    for case in test_cases:
        print(solution.groupAnagrams(case))
        
if __name__ == "__main__":
    main()