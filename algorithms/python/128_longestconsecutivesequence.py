from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        
        sorted_nums = sorted(nums)
        length = len(nums)
        if(length == 0): return 0
        
        count = 1
        max_count = 1
        
        for i in range(1, length):
            
            if(sorted_nums[i] == sorted_nums[i - 1]):
                continue
            
            if(sorted_nums[i] == sorted_nums[i - 1] + 1):
                count +=1
                if(count > max_count):
                    max_count = count
            else:
                count = 1
        
        return max_count
    

def main():
    sol = Solution()
    nums = [0,3,7,2,5,8,4,6,0,1]  
    print(sol.longestConsecutive(nums))
    
if __name__ == "__main__":
    main()        
            
        
        