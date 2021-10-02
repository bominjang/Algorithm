class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        if n <= 3:
            return max(nums)
        
        dp = list(range(0, n)) #첫번째 집을 들르는 경우
        dp[0] = nums[0]
        dp[1] = nums[0]
        
        dp2 = list(range(0, n)) #두번째 집을 들르는 경우
        dp2[0] = 0
        dp2[1] = nums[1]
        
        for i in range(2, n):
            if i!= n-1:
                dp[i] = max(dp[i-1], dp[i-2]+nums[i])
            dp2[i] = max(dp2[i-1], dp2[i-2]+nums[i])
            
        return max(dp[n-2], dp2[n-1])
