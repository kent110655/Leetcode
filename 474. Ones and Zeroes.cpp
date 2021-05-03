class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        //vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int dp[101][101]={0};
        for(auto t: strs)
        {
            int zero = 0;
            int one = 0;
            for(auto s: t)
            {
                if(s == '0')
                    zero++;
                else
                    one++;
            }
            for(int k = m; k >= zero; k--)
            {
                for(int j = n; j >= one; j--)
                {
                    dp[k][j] = max(dp[k - zero][j - one] + 1, dp[k][j]);
                }
            }
        }
        return dp[m][n];
    }
};
/*
Comment:
0/1背包問題
此題可以看成兩個背包(0背包與1背包)

dp原先思路：
dp[i][k][j]:在前i個string中可以用k個0、j個1組成的最大string
空間優化使dp[i][k][j] -> dp[k][j]

利用一個二維vector dp來更新兩背包的變化
dp[k][j]:能拼成 k個0 j個1 的方法數
dp[k][j]為dp[k-zero][j-one]+1與原本值取大者
由後端掃到前端，避免重複計算到。
最終所有strs的element跑完更新完dp以後
dp[m][n]即為所求。
時間複雜度：Ｏ(lmn) l:數組長度
空間複雜度：Ｏ(mn)
P.S.因為1 <= m, n <= 100 所以直接宣告dp[101][101]={0}
*/
