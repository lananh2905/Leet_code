from typing import List

class Solution:
    def maxArea(self, height: List[int]) -> int:
        
        left = 0
        right = len(height) - 1
        max_area = 0
        
        while left < right:

            current_area = self.min_int(height[left], height[right]) * (right - left)
            max_area = self.max_int(max_area, current_area)

            if height[left] < height[right]:
                left += 1
            elif height[left] > height[right]:
                right -= 1
            elif height[left - 1] < height[right - 1]:
                left += 1
            else:
                right -= 1
        
        return max_area
    
    def min_int(self, a: int, b: int) -> int:
        return a if a < b else b
    
    def max_int(self, a: int, b: int) -> int:
        return a if a > b else b
                    
            