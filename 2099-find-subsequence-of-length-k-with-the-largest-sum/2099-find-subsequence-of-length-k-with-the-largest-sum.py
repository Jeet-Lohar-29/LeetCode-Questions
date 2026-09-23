class Solution:
    def maxSubsequence(self, nums: list[int], k: int) -> list[int]:
        # Pair each number with its original index
        indexed_nums = [(num, i) for i, num in enumerate(nums)]
        
        indexed_nums.sort(key=lambda x: x[0], reverse=True)
        top_k = indexed_nums[:k]
        
        top_k.sort(key=lambda x: x[1])
        
        return [num for num, i in top_k]
