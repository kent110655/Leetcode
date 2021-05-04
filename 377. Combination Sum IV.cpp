class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        m = vector<int>(target + 1, -1);
        m[0] = 1;
        return solve(nums, target);
    }
private:
    vector<int> m;
    int solve(vector<int>& nums, int target)
    {
        if(target < 0)          //target組成失敗
            return 0;
        if(m[target] != -1)     //Recursive過程中算過
            return m[target];
        int ans = 0;
        for(auto n : nums)
        {
            ans += solve(nums, target - n);
        }
        m[target] = ans;
        return ans;
    }
};
/*
Comment:
Recursion解法。
時間複雜度：Ｏ(sum(target/nums))
空間複雜度：Ｏ(target)
*/

/*
Algo 1:
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned long> dp(target + 1, 0);
        dp[0] = 1;
        for(int i = 1; i <= target; i++)
        {
            for(auto n : nums)
            {
                if(i >= n)
                    dp[i] += dp[i - n];
            }
        }
        return dp[target];
    }
};
Comment:
DP完全背包問題(順序問題)
時間複雜度：Ｏ(target * |nums|)
空間複雜度：Ｏ(target)
*/
