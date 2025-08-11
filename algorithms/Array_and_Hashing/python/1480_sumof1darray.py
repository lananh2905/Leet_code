# Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

# Return the running sum of nums.

from typing import List

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        news = []
        news.append(nums[0])
        for i in range(1, len(nums)):
            news.append(news[i-1] + nums[i])
        return news