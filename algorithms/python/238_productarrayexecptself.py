from typing import List
import math

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        left = [1]
        right = [1]
        results = []
        
        n = len(nums)
        
        for i in range(n):
            left.append(left[i]*nums[i])
            right.append(right[i]*nums[n-i-1])
        
        for i in range(n):
            results.append(left[i]*right[n-i-1])
        
        return results

# Alternate approach using math.prod -> Time limit exceeded
# class Solution:
#     def productExceptSelf(self, nums: List[int]) -> List[int]:
#         results = []
        
#         for i in range(len(nums)):
#             result = math.prod(nums[:i]) * math.prod(nums[i+1:])
#             results.append(result)
        
#         return results
    
    
def main():
    sol = Solution()
    nums = [1, 2, 3, 4]
    print(sol.productExceptSelf(nums))
    
if __name__ == "__main__":
    main()
            