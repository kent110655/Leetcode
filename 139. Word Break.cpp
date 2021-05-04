class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int N = s.size();
        vector<bool> dp(N+1, false);
        dp[0] = true;
        for(int i = 1; i <= N; i++)
        {
            for(auto w : wordDict)
            {
                int len = w.size();
                if(len > i)
                    continue;
                string sub = s.substr(i - len, len);
                if(sub == w)
                {
                    dp[i] = dp[i] || dp[i - len];
                }
            }
        }
        return dp[N];
    }
};
/*
Comment:
DP完全背包問題。
dp[i]:前i個子字串是否可以用dic中的字串組成。
因為要以有順序地把物品放入背包
所以要把物品的迭代放在內側，字串迭代放在外側
每個loop比較0~i字串的最後部分是否有符合字典字串
如果有再查看dp[i-len]是否有成功，再更新dp[i]
最終dp[N]即為所求。
時間複雜度：Ｏ(nW)
空間複雜度：Ｏ(W)
*/
