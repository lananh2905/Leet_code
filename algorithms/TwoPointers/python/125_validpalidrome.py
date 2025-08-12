from typing import List

class Solution:
    def isPalindrome(self, s: str) -> bool:
        s_normalize = self.normalizeString(s)
        left, right = 0, len(s_normalize) - 1
        while left < right:
            if s_normalize[left] != s_normalize[right]:
                return False
            left += 1
            right -= 1
        return True

    def normalizeString(self, s: str) -> str:
        return ''.join(c.lower() for c in s if c.isalnum())