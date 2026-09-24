class Solution:
    def countSubstrings(self, s: str) -> int:
        count = 0
        
        def expandAroundCenter(left: int, right: int) -> int:
            palindromes = 0
            while left >= 0 and right < len(s) and s[left] == s[right]:
                palindromes += 1
                left -= 1
                right += 1
            return palindromes

        for i in range(len(s)):
            count += expandAroundCenter(i, i)
            count += expandAroundCenter(i, i + 1)
            
        return count
