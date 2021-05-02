class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        if(nums.size() == 1)
            return (nums[0] == target) || (nums[0] == -target) ? 1 : 0;
        int sum = 0;
        for(auto u: nums)
            sum += u;
        if(sum < target || (target + sum) % 2 == 1)
            return 0;
        int half = (target + sum) / 2;
        vector<int> dp(half+1, 0);
        dp[0] = 1;
        for(int n:nums)
        {
            for(int i = half; i >= 0; i--)
            {
                if(dp[i] > 0 && i + n <= half)
                {
                    dp[i+n] += dp[i];
                }
            }
        }
        return dp[half];
    }
};

/*
Comment:
把數組分成兩部分，正值的P與負值的N。
                  sum(P) - sum(N) = target
sum(P) + sum(N) + sum(P) - sum(N) = target + sum(P) + sum(N)
                       2 * sum(P) = target + sum(nums)
                           sum(P) = (target + sum(nums) ) / 2
依照上面的思路把問題轉換成0/1背包問題
把數組分出一部分，且他的總和為(target + sum(nums) ) / 2
所求為有幾種分法可以符合上述條件。
利用0/1背包解法。
用一個大小0~half的vector<int> dp
dp[i]：i可以有幾種方式組合。
依序用 nums 的 n 去"從後到前"更新dp[] 
(由後往前更新可避免重複使用到更新的dp[])
當跑到dp[i]>0的時候，更新dp[i+n] += dp[i]。
(要注意i+n超過half，則不用更新)
最終dp[half]代表組合可能數。
時間複雜度：Ｏ(n*half)
空間複雜度：Ｏ(half)
*/
