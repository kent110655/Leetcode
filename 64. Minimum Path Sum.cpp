class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n);
        dp[0]=grid[0][0];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    ;
                else if(j==0)
                    dp[j]=dp[j]+grid[i][j];
                else if(i==0)
                    dp[j]=dp[j-1]+grid[i][j];
                else
                    dp[j]=min(dp[j],dp[j-1])+grid[i][j];
            }
        }
        return dp[n-1];
    }
};

/*
algo 1:
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        dp[0][0]=grid[0][0];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    ;
                else if(i==0)
                    dp[i][j]=dp[i][j-1]+grid[i][j];
                else if(j==0)
                    dp[i][j]=dp[i-1][j]+grid[i][j];
                else
                    dp[i][j]=min(dp[i][j-1],dp[i-1][j])+grid[i][j];
            }
        }
        return dp[m-1][n-1];
    }
};
Comment:
dp[i][j]=max(dp[i][j-1],dp[i-1][j])+grid[i][j]
Space Complexity:Ｏ(m*n)
*/

/*
algo 2:
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> dp(n);
        dp[0]=grid[0][0];
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0 && j==0)
                    ;
                else if(j==0)
                    dp[j]=dp[j]+grid[i][j];
                else if(i==0)
                    dp[j]=dp[j-1]+grid[i][j];
                else
                    dp[j]=min(dp[j],dp[j-1])+grid[i][j];
            }
        }
        return dp[n-1];
    }
};
Comment:
只用一維陣列即可取代algo 1的二維陣列
Space Complexity 由Ｏ(m*n)-->Ｏ(n)
*/
