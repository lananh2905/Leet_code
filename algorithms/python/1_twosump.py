from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:

        new_nums = nums.copy()

        # Loop through the array
        for num in nums:
            tmp = target - num

            # Remove the current number to avoid using it again
            new_nums.remove(num)
            
            # Check if the complement exists in the modified list
            if tmp in new_nums:
                
                if num == tmp:
                    # if the number is the same as its complement, we need to find its index in the original list
                    if nums.count(num) > 1:
                        first_id = nums.index(num)
                        second_id = nums.index(tmp, first_id + 1) # start_index = first_id + 1 to find the second occurrence
                        return [first_id, second_id]
                return [nums.index(num), nums.index(tmp)]
        
        return []

def main():
    solution = Solution()
    print(solution.twoSum([3,3], 6)) 

main()