class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        for(auto c: coins)
        {
            for(int i = c; i <= amount; i++)
            {
                if(i - c >= 0)
                    dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
};
/*
Comment:
優化Algo 1
把dp[0]設為1
不用判斷dp[i-c]是否有值
因為是累加且初值都為0
所以可以都進行累加動作不影響結果
也不用判斷是否 i == c
*/

/*
Algo 1:
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if(amount == 0)
            return 1;
        vector<int> dp(amount + 1, 0);
        dp[0] = 0;
        for(auto c: coins)
        {
            for(int i = c; i <= amount; i++)
            {
                if(i - c == 0)
                    dp[i]++;
                else if(dp[i - c])
                {
                    dp[i] += dp[i - c];
                }
            }
        }
        return dp[amount];
    }
};
Comment:
完全背包問題
dp[i]:i的可能組成數
時間複雜度：Ｏ(amount * coins.size())
空間複雜度：Ｏ(amount)
*/
