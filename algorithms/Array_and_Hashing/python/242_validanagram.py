# Using a counting sort approch to determine if two strings are anagarms

# Main idea: 'b' - 'a' = 1 -> Using count arr to save


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        
        # Create a count array with 26 letters of 0
        count = [0]*26
        
        for char in s:
            # Save the count of each character
            # 'a' is at index 0, 'b' at index 1, ..., 'z' at index 25
            count[ord(char) - ord('a')] += 1  
            
        for char in t:
            # Decrease the count for each character in t
            count[ord(char) - ord('a')] -= 1
            # If count goes negative, t has more of char than s
            if count[ord(char) - ord('a')] < 0:
                return False
        return True

def main():
    solution = Solution()
    s = "anagram"
    t = "nagarmm"
    print(solution.isAnagram(s, t))
    
if __name__ == "__main__":
    main()