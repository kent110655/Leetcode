class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,INT_MIN);
        dp[0]=0;
        dp[1]=0;
        dp[2]=1;
        for(int i=3;i<n+1;i++)
        {
            for(int j=1;j<i+1;j++)
            {
                dp[i]= max(dp[i], max(j*dp[i-j], j*(i-j)));
            }
        }
        return dp[n];
    }
};

/*
Comment:
DP algo.
dp[i]= max(dp[i], max(j*dp[i-j], j*(i-j)))
j*dp[i-j]：j * (i-j的最大組合)
j*(i-j)：j * (i-j不拆)
*/
