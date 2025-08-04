from typing import List


class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        unique_nums = set(nums)
        return len(unique_nums) < len(nums)

def main():
    solution = Solution()
    nums = [1, 2, 3, 4]
    print(solution.containsDuplicate(nums))

main()