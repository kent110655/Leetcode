class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int N1 = text1.size();
        int N2 = text2.size();
        int dp[N1+1][N2+1];
        for(int r = 0; r <= N1; r++)
            dp[r][0] = 0;
        for(int e = 0; e <= N2; e++)
            dp[0][e] = 0;
        for(int i = 1; i <= N1; i++)
        {
            for(int j = 1; j <= N2; j++)
            {
                if(text1[i-1] == text2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[N1][N2];
    }
};
/*
Comment:
利用DP解LCS題
遍尋兩個string
當兩個element相同，則 dp[i][j] = dp[i-1][j-1]+1
當兩個element不相同，則 dp[i][j] = max(dp[i-1][j], dp[i][j-1])
(在邊界之外的值為0)
最終dp[N1][N2]即為所求。
EX:
e 1 1 2 2 3
c 1 1 2 2 2
a 1 1 1 1 1
  a b c d e ->橫排為0（直排字母也為0）
Ans = 3
時間複雜度：Ｏ(n^2)
空間複雜度：Ｏ(n)
*/
