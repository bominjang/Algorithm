class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 2:
            return max(nums)
        
        dp = list(range(0, n))
        dp[0] = nums[0]
        dp[1] = max(nums[0], nums[1])
        
        for i in range(2, n):
            #이전 계단만 밟을지, 아니면 전전 계단을 밟고 현재 계단을 밟을 것인지
            dp[i] = max(dp[i-1], dp[i-2]+nums[i]) 
        
        return dp[n-1]
