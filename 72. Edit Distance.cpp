class Solution {
public:
    int minDistance(string word1, string word2) {
        int N1 = word1.size();
        int N2 = word2.size();
        int dp[N1 + 1][N2 + 1];
        for(int i = 0; i <= N1; i++)
            dp[i][0] = i;
        for(int i = 0; i <= N2; i++)
            dp[0][i] = i;
        for(int i = 1; i <= N1; i++)
        {
            for(int j = 1; j <= N2; j++)
            {
                if(word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]))+1;
            }
        }
        return dp[N1][N2];
    }
};
/*
Comment:
dp[i][j]：使前i個字的word1與前j個字的word2相同的最少修改數
若 w1[i] = w2[j]：
dp[i][j] = dp[i - 1][j - 1]
若 w1[i] != w2[j]：
dp[i][j] = min(insert, delete, replace)
insert: dp[i][j-1]+1
delete: dp[i-1][j]+1
replace: dp[i-1][j-1]+1
時間複雜度：Ｏ(n1 * n2)
空間複雜度：Ｏ(n1 * n2)
*/
