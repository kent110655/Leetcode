class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int half = 0;
        for(auto u : nums)
            half += u;
        if(half % 2 != 0)
            return false;
        half /= 2;
        vector<bool> dp(half+1, false);
        dp[0] = true;
        for(auto n : nums)
        {
            for(int w = half; w >= 0; w--)
            {
                if(dp[w] == true && w + n <= half)
                    dp[w + n] = true;
                if(dp[half] == true)
                    return true;
            }
        }
        return false;
    }
};
/*
Comment:
DP解法
先求出總和的一半 half。
設置一個vector<bool> dp
dp[i]:i是否可以用nums中的數字湊出來
依序用 nums 的 n 去"從後到前"更新dp[] 
(由後往前更新可避免重複使用到更新的dp[])
當跑到dp[i]為true的時候，更新dp[i+n]為true。
(要注意i+n超過half，則不用更新)
當dp[half]＝true，代表可以湊出half。
時間複雜度：Ｏ(n*half)
空間複雜度：Ｏ(half)
*/
