class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[j]=dp[j-1]+dp[j];
            }
        }
        return dp[n-1];
    }
};

/*
algo 1:
class Solution {
public:
    int uniquePaths(int m, int n) {
        int MM=max(m,n)-1;
        int mm=min(m,n)-1;
        long a=1,b=1,c=1;
        for(int i=MM+1;i<=MM+mm;i++)
        {
            a=a*i;
        }
        for(int i=1;i<=mm;i++)
        {
            b=b*i;
        }
        return a/b;
    }
};
Comment:
組合問題
Ｃ(m-1,n-1)即可。
*/

/*
algo 2:
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                dp[j]=dp[j-1]+dp[j];
            }
        }
        return dp[n-1];
    }
};
Comment:
DP解法
*/
