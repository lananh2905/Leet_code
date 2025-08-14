from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        results = []
        size = len(nums)
        count_zero = 0
        
        for left in range(size - 2):
            if left > 0 and nums[left] == nums[left - 1]:
                continue
            
            if nums[left] == 0:
                count_zero += 1
            
            check_set = set(nums[left + 1:])
            for right in range(left + 1, size - 1):
                if right > left + 1 and nums[right] == nums[right - 1]:
                    continue
                
                if nums[right] != nums[right + 1]:
                    check_set.discard(nums[right])
                
                sum_value = nums[left] + nums[right]
                if -sum_value in check_set:
                    results.append([nums[left], nums[right], -sum_value])
                    check_set.discard(nums[right])
        
        if count_zero >= 3 and [0, 0, 0] not in results:
            results.append([0, 0, 0])
        
        return results