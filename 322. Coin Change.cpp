class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        vector<int> dp(amount + 1,INT_MAX);
        dp[0] = 0;
        for(auto c : coins)
        {
            for(int i = c; i <= amount; i++)
            {
                if(dp[i - c] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[i-c]+1);
                }
            }
        }
        return dp[amount] == INT_MAX ? -1:dp[amount];
    }
};
/*
Comment:
優化 Algo 1 的細節。
把dp初始值設為INT_MAX，且dp[0] = 0
即可少判斷dp[i]是否為初始更新
且不用另外判斷dp[i-c]時是否為i == c
*/

/*
Algo 1:
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for(auto c : coins)
        {
            for(int i = c; i <= amount; i++)
            {
                if(dp[i - c])
                {
                    if(i - c == 0)
                        dp[i] = 1;
                    else
                        dp[i] = (dp[i]==0) ? dp[i-c]+1 : min(dp[i], dp[i-c]+1);
                }
            }
        }
        return dp[amount] == 0 ? -1:dp[amount];
    }
};
Comment:
完全背包問題。
因為每個物品都可以無限取用，所以沒有重複計算的問題。
只需把0/1背包的逆順序改成正順序即可。
時間複雜度：Ｏ(amount * coin.size())
空間複雜度：Ｏ(amount)
*/
