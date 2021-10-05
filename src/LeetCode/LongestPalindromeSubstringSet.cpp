class Solution {
public:
    string longestPalindrome(string s) {
        const int SIZE = s.size();
        vector<vector<char>> dp(SIZE, vector<char>(SIZE, 0));
        int left = 0, right=0;
        
        //
        for(int i=0;i<SIZE;i++){
            for(int j=0;j<i;j++){
                dp[j][i] = (s[i]==s[j])&&(i-j<=2 || dp[j+1][i-1]);
                if (dp[j][i])
                {
                    if(i-j > right-left)
                    {
                        left=j;
                        right=i;
                    }
                }
            }
        }
        
        return s.substr(left, right-left+1);

    }
};
