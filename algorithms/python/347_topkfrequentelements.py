from typing import List

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        map = {}
        
        for num in nums :
            if num not in map:
                map[num] = 0
            map[num] += 1
        
        sorted_data = sorted(map.items(), key=lambda x: x[1], reverse=True)
        
        results = []
        for i in range(k):
            results.append(sorted_data[i][0])
            
        return results

def main():
    sol = Solution()
    nums = [1,1,1,2,2,3]
    k = 2
    print(sol.topKFrequent(nums, k))

if __name__ == "__main__" :
    main()
    