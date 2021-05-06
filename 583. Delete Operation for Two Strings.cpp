class Solution {
public:
    int minDistance(string word1, string word2) {
        int N1 = word1.size();
        int N2 = word2.size();
        int dp[N1 + 1][N2 + 1];
        for(int i = 0; i <= N1; i++)
            dp[i][0] = 0;
        for(int i = 0; i <= N2; i++)
            dp[0][i] = 0;
        for(int i = 1; i <= N1; i++)
        {
            for(int j = 1; j <= N2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
            }
        }
        int sub = dp[N1][N2];
        return N1 + N2 - sub * 2;
    }
};

/*
Comment:
LCS問題(DP)
利用LCS解法求出兩個string的最長子字串長度sub
兩個string的長度各自剪掉sub的長度即為所求。
時間複雜度：Ｏ(n1 * n2)
空間複雜度：Ｏ(n1 * n2)
*/
