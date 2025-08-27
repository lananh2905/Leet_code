from typing import List

class Solution:
    def generateParenthesis(self, n: int) -> List[str]:

        self.result = []
        self.backtrack("", 0, 0, n)
        return self.result

    def backtrack(self, str, open, close, n):
        if(len(str) == 2 * n):
            self.result.append(str)
            
        if(open < n):
            self.backtrack(str + '(', open +1, close, n)
            
        if(close < open):
            self.backtrack(str + ')', open, close + 1, n)
        return