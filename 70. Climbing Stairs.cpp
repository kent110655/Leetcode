class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1);
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            dp[i]=dp[i-2]+dp[i-1];
        }
        return dp[n];
    }
};

/*
Comment:
DP algo.
dp[n]:走到第n階的方法數
dp[i]=dp[i-1]+dp[i-2]
*/
