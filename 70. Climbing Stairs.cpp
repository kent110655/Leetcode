class Solution {
public:
    int climbStairs(int n) {
        int n1,n2,res;
        n1=1;
        n2=1;
        res=1;
        for(int i=2;i<=n;i++)
        {
            res=n1+n2;
            n1=n2;
            n2=res;
        }
        return res;
    }
};

/*
algo 1:
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
Comment:
DP algo.
dp[n]:走到第n階的方法數
dp[i]=dp[i-1]+dp[i-2]
*/

/*
algo 2:
class Solution {
public:
    int climbStairs(int n) {
        int n1,n2,res;
        n1=1;
        n2=1;
        res=1;
        for(int i=2;i<=n;i++)
        {
            res=n1+n2;
            n1=n2;
            n2=res;
        }
        return res;
    }
};
Comment:
只需用到兩個空間來存前兩個
所以不用vector，直接用兩個變數替代即可。
*/
